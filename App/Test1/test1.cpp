#pragma warning(disable : 4010 4201 4214 4115 4514)
	// warning C4010: single-line comment contains line-continuation character
	// warning C4201: nonstandard extension used : nameless struct/union
	// winnt.h(188) : warning C4201: nonstandard extension used : 
	//					nameless struct/union
	// winnt.h(1357) : warning C4214: nonstandard extension used : bit field types other than int
	// rpcndr.h(1891) : warning C4115: 'IRpcStubBuffer' : named type definition in parentheses
	// warning C4514: 'Int64ShllMod32' : unreferenced inline function has been removed
#define STRICT
#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED
#include <windows.h>
#include <objbase.h>
#include <stdio.h>
#include <atlbase.h>
#include <atlimpl.cpp>
#include <crtdbg.h>

#include "guids.h"

#include "..\..\common\util.h"

#include "..\..\common\ldr.h"
#include "..\..\common\dis.h"
#include "..\..\common\fmt.h"
#include "..\..\common\sym.h"
#include "..\..\common\cfg.h"

#include "..\..\common\ldr_i.c"
#include "..\..\common\dis_i.c"
#include "..\..\common\fmt_i.c"
#include "..\..\common\sym_i.c"
#include "..\..\common\cfg_i.c"



CComPtr<IDisLdr> pILdr;
CComPtr<IDisDis> pIDis;
CComPtr<IDisFmt> pIFmt;
CComPtr<IDisSmX> pISmX;
CComPtr<IDisSymMgr> pISym;
CComPtr<IDisImg> pIImg;
CComPtr<IDisCfg> pICfg;

#define COMMAND_SUCCESS			0
#define COMMAND_FAIL			1
#define COMMAND_INVALID			2

#define COMMAND_USAGE			3

typedef int(*PCOMMAND_FUNC)(char **args);
typedef struct tagDIS_COMMAND_MAP
{
	PCSTR szCmd;
	PCSTR szDesc;
	PCSTR szUsage;
	PCOMMAND_FUNC pFunc;
} DIS_COMMAND_MAP;
#define PRINT printf

int
htoi(PCSTR sz)
{
	int rc = 0;
	while (*sz)	{
		if ( toupper(sz[0]) >= 'A' && toupper(sz[0]) <= 'F' )
			rc = rc*16 + toupper(sz[0]) - 'A' +10;
		else
			rc = rc*16 + sz[0] - '0';
		sz++;
	}
	return rc;
}
DWORD
strtodw(PCSTR sz)
{
	DWORD dw;
	if ( sz[0] == '0' && toupper(sz[1]) == 'X' )
		dw = htoi(sz+2);
	else
		dw = atoi(sz);

	return dw;
}


DWORD
GetSymbolAddress(PCSTR szSym)
{
	DWORD dw;

	wstring wsz(szSym);

	BSTR bsName = ::SysAllocString(wsz);
	CComPtr<ISymbol> pISymbol;
	HRESULT h = pISym->GetSymbolByName( &pISymbol, bsName );

	if ( FAILED(h) )
		return 0;

	SYMBOL_INFO *SymbolInfo;
	h = pISymbol->GetSymbolInfo(&SymbolInfo);
	if ( FAILED(h) )
		return 0;

	dw = SymbolInfo->Address;
	pISymbol->ReleaseSymbolInfo(SymbolInfo);

	return dw;
}
DWORD
GetAddressFromString(PCSTR pszAddr)
{
	if (!pszAddr)
		return 0;

	DWORD dwAddr=0;
	if ( isdigit(*pszAddr) )
		dwAddr = strtodw(pszAddr);
	else
		dwAddr = GetSymbolAddress(pszAddr);
	return dwAddr;

}

#define DEFAULT_DISASSEMBLE_COUNT	20
int DefaultDisassembleCount = DEFAULT_DISASSEMBLE_COUNT;
int
CmdDisassemble(char **szArgs)
{
	DWORD dwPtr;
	DWORD dwVA;

	//
	// Grab the address to disassemble
	//
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}

	//
	// Determine number of instructions to disassemble
	//
	int count=0;
	if (szArgs[2])
		count = DefaultDisassembleCount = atoi(szArgs[2]);
	if (!count)
		count = DefaultDisassembleCount = DEFAULT_DISASSEMBLE_COUNT;


	//
	// Get a dereferenceable pointer to use
	// 
	dwVA = dwAddr;
	HRESULT h;
	if (FAILED(pIImg->ConvertVAToPtr(dwVA, &dwPtr)))
		return COMMAND_FAIL;

	//
	// Disassemble each instruction, let the Instruction Formatter
	// format it, and output it to standard out.
	//
	try {
		while (count--)	{
			INSTRUCTION inst;
			BSTR bstr;

			h = pIDis->Disasm(dwPtr, dwVA, &inst);
			if ( FAILED(h) )	{
				printf("Failed to disasm: %X\n", h);
				exit(1);
			}
			h = pIFmt->GetInstructionString(&inst, &bstr);
			if ( FAILED(h) )	{
				printf("Failed to get instruction string: %X\n", h);
				exit(1);
			}

			printf("%ws\n", bstr);
			::SysFreeString(bstr);

			dwPtr+= inst.dwLen;
			//pIImg->ConvertPtrToVA(dwPtr, &dwVA);
			dwVA+= inst.dwLen;
		}
	} catch (...) {
		PRINT("Exception occurred while disassembling.\n");
	}	
	
	return COMMAND_SUCCESS;
}
template <class T> class auto_ptr
{
public:
	T* p;
	operator T*() { return p; }
	auto_ptr() { p = NULL; }
	~auto_ptr() { delete p; }
	T& operator*() {_ASSERTE(p!=NULL); return *p; }
	//The assert on operator& usually indicates a bug.  If this is really
	//what is needed, however, take the address of the p member explicitly.
	T** operator&() { _ASSERTE(p==NULL); return &p; }
	T* operator->() { _ASSERTE(p!=NULL); return p; }
	T* operator=(T* lp){return p = lp;}
};

//
// List symbol information
//
int
CmdSym(char **szArgs)
{
	PSTR szTok = szArgs[1];

	if (szTok && !*szTok)
		szTok = NULL;

	//
	// Convert the given symbol name, if any, to a wide character string
	//
	wstring wsz(szTok);

	CComPtr<IEnumSymbols> pIEnum;
	HRESULT h = pISym->EnumSymbols(&pIEnum);
	if ( FAILED(h) )	{
		return COMMAND_FAIL;
	}

	DWORD dwGot;
	CComPtr<ISymbol> pISymbol;
	h = pIEnum->Next(1, &pISymbol, &dwGot);
	while ( SUCCEEDED(h) && dwGot )	{
		SYMBOL_INFO *SymbolInfo;
		h = pISymbol->GetSymbolInfo(&SymbolInfo);

		if (!wsz || (SymbolInfo->Name && !wcsnicmp(SymbolInfo->Name, wsz, wcslen(wsz))) )
			PRINT("%-30ws Addr: %Xh Size: %Xh\n", SymbolInfo->Name, SymbolInfo->Address, SymbolInfo->Size);

		pISymbol->ReleaseSymbolInfo(SymbolInfo);
		pISymbol = NULL;
		h =  pIEnum->Next(1, &pISymbol, &dwGot);
	}
	return COMMAND_SUCCESS;
}

int
CmdNear(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}

	CComPtr<ISymbol> pISymbol;
	if ( FAILED(pISym->GetSymbolByAddress(&pISymbol, dwAddr)) )	{
		PRINT("Could not find symbol near %X\n", dwAddr);
	} else {
		SYMBOL_INFO *SymbolInfo;
		pISymbol->GetSymbolInfo(&SymbolInfo);

		DWORD Delta = dwAddr - SymbolInfo->Address;
		PRINT("%ws+%Xh\n", SymbolInfo->Name, Delta);

		pISymbol->ReleaseSymbolInfo(SymbolInfo);
	}

	return COMMAND_SUCCESS;

}

void
PrintSymbolicAddress(DWORD dwAddr)
{
	CComPtr<ISymbol> pISymbol;
	if ( FAILED(pISym->GetSymbolByAddress(&pISymbol, dwAddr)) )	{
		PRINT("%X\n", dwAddr);
	} else {
		SYMBOL_INFO *SymbolInfo;
		pISymbol->GetSymbolInfo(&SymbolInfo);
		
		DWORD Delta = dwAddr - SymbolInfo->Address;
		PRINT("%ws+%Xh\n", SymbolInfo->Name, Delta);

		pISymbol->ReleaseSymbolInfo(SymbolInfo);
	}
}


BOOL
LoadImage(char *pszModule, IDisSymMgr *pISym)
{
	// convert module name to unicode
	wstring wszModule(pszModule);

	//
	// Tell the loader to load the image
	//
	PRINT("Loading image...");
	if (pIImg) pIImg.Release();	// free old image
	HRESULT h = pILdr->Load( wszModule, &pIImg );
	if ( FAILED(h) )	{
		PRINT("Failed to load image!\n");
		return FALSE;
	}
	PRINT("Done.\n");

	//
	// Tell the symbol manager to extract symbols from the image
	//
	PRINT("Extracting symbols...");
	h = pISym->Extract(pIImg);
	if ( FAILED(h) )	{
		PRINT("Failed to extract symbols!\n");
		return FALSE;	// we should allow this, really
	}
	PRINT("Done.\n");

	//
	// Tell the CFG to parse all symbols
	//
	PRINT("Parsing all known entry points...");
	h = pICfg->ParseAllSymbols();
	if ( FAILED(h) )	{
		PRINT("Failed to parse entry points!\n");
		return FALSE;
	}
	return TRUE;
}

#if LATER
int
CmdLoad(PSTR szCmdLine)
{
	char *pszCmd = strdup(szCmdLine);
	char *pszNear = strtok(pszCmd, " \t");
	_ASSERT ( !stricmp(pszNear, "load") );
	char *pszModule = strtok(NULL, " \t");
	if ( !pszModule )	{
		free( pszCmd );
		return COMMAND_FAIL;
	}

	if (LoadImage(pszModule))	{
		free (pszCmd);	// done
		return COMMAND_SUCCESS;
	}
	else	{
		PRINT("Could not load module: %s\n", pszModule);
		free (pszCmd);	// done
		return COMMAND_FAIL;
	}

}
#endif

//BUGBUG: this could change!
const char *
CtrlFlowTypeNames[] =
{ "UJMP", "CJMP", "IJMP", "CALL", "FALL", "RET" };

PCSTR
GetRefTypeString(CTRL_FLOW_TYPE Type)
{
	if ((DWORD)Type <= CTRL_RET)
		return CtrlFlowTypeNames[Type];
	else
		return "<unknown>";
}

int
CmdCRef(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}
	PRINT("Searching for code references to: ");
	PrintSymbolicAddress(dwAddr);

#define NUM_REFS 20
	DIS_REF Refs[NUM_REFS];
	int count = NUM_REFS;
	HRESULT h = pICfg->GetEdgesIn( dwAddr, Refs, &count );

	if ( FAILED(h) || count == 0)
		PRINT("No references found.");

	for (int i=0;i<count;i++)	{
		CComPtr<ISymbol> pISymbol;
		SYMBOL_INFO *SymbolInfo;
		OLECHAR *wsz;
		DWORD Delta;
		if ( FAILED(pISym->GetSymbolByAddress(&pISymbol, Refs[i].Address)) )	{
			wsz = L"<unknown>";
			Delta = 0;
		} else {
			pISymbol->GetSymbolInfo(&SymbolInfo);

			Delta = Refs[i].Address - SymbolInfo->Address;
			wsz = SymbolInfo->Name;
		}

		PCSTR szType = GetRefTypeString(Refs[i].Type);
		PRINT("%s at %ws+%Xh(%X)\n", szType, wsz, Delta, Refs[i].Address);
		if (pISymbol && SymbolInfo)
			pISymbol->ReleaseSymbolInfo(SymbolInfo);
	}

	return COMMAND_SUCCESS;
}

int
CmdDRef(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}
	PRINT("Searching for data references to: ");
	PrintSymbolicAddress(dwAddr);

	CComPtr<IEnumInstructions> pIEnum;
	HRESULT h = pICfg->GetDataReferences( dwAddr, &pIEnum );
	if ( FAILED(h) )
		PRINT("Could not get data references.");

	DWORD dwGot;
	INSTRUCTION Instruction;
	h = pIEnum->Next(1, &Instruction, &dwGot);
	if ( FAILED(h) || !dwGot )	{
		PRINT("Found no references.\n");
	}
	while ( SUCCEEDED(h) && dwGot )	{
		BSTR InstructionString;
		h = pIFmt->GetInstructionString(&Instruction, &InstructionString);
		if ( FAILED(h) )	{
			printf("Failed to get instruction string: %X\n", h);
			return COMMAND_FAIL;
		}
		printf("%ws\n", InstructionString);
		::SysFreeString(InstructionString);

		h = pIEnum->Next(1, &Instruction, &dwGot);
	}

	return COMMAND_SUCCESS;
}

int
CmdParseAll(char **)
{
	HRESULT h = pICfg->ParseAllSymbols();
	if ( SUCCEEDED(h) )
		return COMMAND_SUCCESS;
	else
		return COMMAND_FAIL;
}

int
CmdParse(char **szArgs)
{
	if (!szArgs[1])
		return CmdParseAll(szArgs);

	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}

	pICfg->Parse( dwAddr );

	return COMMAND_SUCCESS;
}

int
CmdClear(char **)
{
	pICfg->Clear();
	return COMMAND_SUCCESS;
}

int
CmdBB(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}

	BASIC_BLOCK bb;
	HRESULT h = pICfg->GetNextBasicBlock( dwAddr, &bb );
	if ( FAILED(h) )	{
		PRINT("Could not get next basic block\n");
		return COMMAND_FAIL;
	}

	PRINT("Basic Block at ");
	PrintSymbolicAddress( bb.Address );
	PRINT(" Address: %Xh Size: %Xh  Refs: %d  StackAdjustment: %d\n", bb.Address, bb.Size, bb.EdgesIn, bb.StackAdjustment);
	
	DWORD dwPtr;
	if (FAILED(pIImg->ConvertVAToPtr(bb.Address, &dwPtr)))
		return COMMAND_FAIL;

	DWORD dwVA = bb.Address;
	while (dwVA < bb.Address + bb.Size)	{
		INSTRUCTION inst;
		BSTR bstr;

		h = pIDis->Disasm(dwPtr, dwVA, &inst);
		if ( FAILED(h) )	{
			printf("Failed to disasm: %X\n", h);
			exit(1);
		}
		h = pIFmt->GetInstructionString(&inst, &bstr);
		if ( FAILED(h) )	{
			printf("Failed to get instruction string: %X\n", h);
			exit(1);
		}

		printf("%ws\n", bstr);
		::SysFreeString(bstr);

		dwPtr+= inst.dwLen;
		dwVA+= inst.dwLen;
	}

	return COMMAND_SUCCESS;


}

#define DUMP_BB_VERBOSE	0x1
#define DUMP_BB_SUMMARY	0x2
int
OutputBasicBlockEx(BASIC_BLOCK &bb, DWORD Options)
{
	if ( Options & DUMP_BB_SUMMARY )	{
		PrintSymbolicAddress( bb.Address );
		PRINT(" Size: %Xh  Refs: %d  StackAdjustment: %d\n", bb.Size, bb.EdgesIn, bb.StackAdjustment);
		return COMMAND_SUCCESS;
	}


	if ( Options & DUMP_BB_VERBOSE )	{
		PRINT("// ");
		PrintSymbolicAddress( bb.Address );
		PRINT("// Size: %Xh  Refs: %d  StackAdjustment: %d\n", bb.Size, bb.EdgesIn, bb.StackAdjustment);
	}
	
	DWORD dwPtr;
	if (FAILED(pIImg->ConvertVAToPtr(bb.Address, &dwPtr)))
		return COMMAND_FAIL;

	DWORD dwVA = bb.Address;
	while (dwVA < bb.Address + bb.Size)	{
		INSTRUCTION inst;
		BSTR bstr;

		HRESULT h = pIDis->Disasm(dwPtr, dwVA, &inst);
		if ( FAILED(h) )	{
			printf("Failed to disasm: %X\n", h);
			exit(1);
		}
		h = pIFmt->GetInstructionString(&inst, &bstr);
		if ( FAILED(h) )	{
			printf("Failed to get instruction string: %X\n", h);
			exit(1);
		}

		printf("%ws\n", bstr);
		::SysFreeString(bstr);

		dwPtr+= inst.dwLen;
		dwVA+= inst.dwLen;
	}

	return COMMAND_SUCCESS;
	
}

int
OutputBasicBlock(BASIC_BLOCK &bb)
{
	return OutputBasicBlockEx(bb, 0);
}

int
Disasm(DWORD dwVA, DWORD dwEndVA)
{
	//
	// Obtain a dereferenceable pointer
	//
	DWORD dwPtr;
	if (FAILED(pIImg->ConvertVAToPtr(dwVA, &dwPtr)))
		return COMMAND_FAIL;

	//
	// Do a brute force disassembly of the bytes in
	// the given range
	//
	while (dwVA < dwEndVA)	{
		INSTRUCTION inst;
		BSTR bstr;

		HRESULT h = pIDis->Disasm(dwPtr, dwVA, &inst);
		if ( FAILED(h) )	{
			printf("Failed to disasm: %X\n", h);
			exit(1);
		}
		h = pIFmt->GetInstructionString(&inst, &bstr);
		if ( FAILED(h) )	{
			printf("Failed to get instruction string: %X\n", h);
			exit(1);
		}

		printf("%ws\n", bstr);
		::SysFreeString(bstr);

		dwPtr+= inst.dwLen;
		dwVA+= inst.dwLen;
	}
	return COMMAND_SUCCESS;
}

int
CmdImports(char **szArgs)
{
	//
	// Retrieve an enumeration of imports
	//
	CComPtr<IDisEnumImports> pEnumImports;
	HRESULT h = pIImg->EnumImports(&pEnumImports);
	if ( FAILED(h) )	{
		PRINT("Could not enumerate imports\n");
		return COMMAND_FAIL;
	}

	//
	// Dump each import
	//
	IMG_IMPORT Import;
	DWORD dwGot;
	h = pEnumImports->Next(1, &Import, &dwGot);
	while ( SUCCEEDED(h) && dwGot )	{
		PRINT("%ws!%-30ws Addr: %Xh\n", Import.Module, Import.Name, Import.Address);
		::SysFreeString( Import.Module );
		::SysFreeString( Import.Name );
		h =  pEnumImports->Next(1, &Import, &dwGot);
	}

	return COMMAND_SUCCESS;
}

int
CmdProc(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}

	//
	// Parse the procedure at the given address
	//
	PROCEDURE Procedure;
	if (FAILED(pICfg->ParseProcedure( dwAddr, &Procedure )) )	{
		PRINT("Could not parse procedure\n");
		return COMMAND_FAIL;
	}

	//
	// Dump the procedure header
	//
	PRINT("//\n");
	PRINT("// Procedure: ");
	PrintSymbolicAddress( Procedure.Address );
	PRINT("// Size: %Xh Blocks: %d\n", Procedure.Size, Procedure.NumberOfBasicBlocks);
	PRINT("//\n");

	//
	// Dump each of the procedure's basic blocks
	//
	for (DWORD i=0;i<Procedure.NumberOfBasicBlocks;i++)	{
		DWORD Address = Procedure.BasicBlocks[i];

		BASIC_BLOCK BasicBlock;
		if ( FAILED(pICfg->GetNextBasicBlock( Address, &BasicBlock )) )	{
			PRINT("Failed while getting basic block!\n");
			return COMMAND_FAIL;
		}
		OutputBasicBlock(BasicBlock);
		Address = BasicBlock.Address + BasicBlock.Size;

		//
		// Look for dead code (gaps in the basic block list)
		//
		if ( (i+1) < Procedure.NumberOfBasicBlocks && Address < Procedure.BasicBlocks[i+1] )	{
			int DeadCodeBytes = Procedure.BasicBlocks[i+1] - Address;
			PRINT("// %d(%Xh) bytes of dead code at:", DeadCodeBytes, DeadCodeBytes);
			PrintSymbolicAddress( Address );
		}
	}

	return COMMAND_SUCCESS;
}

//
// a string must be printable and NULL terminated, or just
// all letters and numbers
//
#define MIN_STRING_LENGTH 5	// CUSTOMIZE
int
CmdStrings(char **szArgs)
{
	if (!pIImg)
		return COMMAND_SUCCESS;


	BOOL SkipCodeSections = TRUE;	// CUSTOMIZE

	DWORD PreferredLoadAddress;
	if (FAILED(pIImg->GetPreferredLoadAddress(&PreferredLoadAddress)))
		PreferredLoadAddress = 0;

	CComPtr<IEnumSections> pIEnum;
	HRESULT h = pIImg->EnumSections(&pIEnum);
	if ( FAILED(h) )
		return COMMAND_FAIL;

	//
	// Search for strings in all sections
	//
	IMG_SECTION Section;
	DWORD dwGot;
	h = pIEnum->Next(1, &Section, &dwGot);
	while ( SUCCEEDED(h) && dwGot )	{
		
		//
		// If this is a code section, skip it
		//
		if ( SkipCodeSections && Section.Type == IMG_SECTION_CODE )	{
			h = pIEnum->Next(1, &Section, &dwGot);
			continue;
		}

		//
		// Get beginning and ending pointers to this section.  (We have to get
		// the last address of the section, then add one to get the end address)
		//
		DWORD SectionPointer;
		DWORD Address;
		DWORD EndAddress;
		h = pIImg->ConvertVAToPtr( Section.Address, &SectionPointer);
		if ( FAILED(h) )
			return COMMAND_FAIL;
		Address = SectionPointer;
		EndAddress = Address + Section.Size + 1;
		while ( Address < EndAddress )	{
			char StringBuffer[64];	// CUSTOMIZE
			DWORD StringLength;
			DWORD OriginalAddress;
			
			StringLength = 0;
			OriginalAddress = Address;

			//
			// Count the number of printable characters
			//
			while ( isprint((unsigned int)(*(unsigned char *)Address)) )
				StringLength++, Address++;

			//
			// If there was no printable character, continue on
			//
			if (!StringLength)	{
				Address++;
				continue;
			}
			if (StringLength < MIN_STRING_LENGTH)
				continue;

			//
			// If it isn't NULL terminated, we only allow strings of just
			// letters and numbers
			//
			if ( *(char *)Address != 0 )	{
				for (char *p=(char *)OriginalAddress;p<(char *)Address;p++)
					if (! __iscsym((unsigned int)(*(unsigned char *)p)) )
						continue;	// didn't make the grade
			}

			//
			// If we counted enough characters to constitute a string,
			// print it out.  Since it might not be NULL terminated, we
			// have to copy it first.
			//
			int BytesToCopy = min(StringLength, sizeof(StringBuffer));
			strncpy((char *)StringBuffer, (char *)OriginalAddress, BytesToCopy );
			StringBuffer[ BytesToCopy ] = 0;

			DWORD VirtualAddress = Section.Address + (OriginalAddress - SectionPointer );
			PRINT("%08X  \"%s\"\n ", VirtualAddress, StringBuffer);

			//
			// Go to the next address
			//
			OriginalAddress = Address;
		}

		h =  pIEnum->Next(1, &Section, &dwGot);
	}

	return COMMAND_SUCCESS;
}


int
CmdBBList(char **szArgs)
{
	IDisEnumBASIC_BLOCK *Enum;
	HRESULT hr = pICfg->EnumBasicBlocks(&Enum);
	if ( FAILED(hr) )	{
		PRINT("Couldn't enum basic blocks!\n");
		return COMMAND_FAIL;
	}
	BASIC_BLOCK Block;
	DWORD Got;
	hr = Enum->Next(1, &Block, &Got);
	while ( SUCCEEDED(hr) && Got )	{
		OutputBasicBlockEx(Block, DUMP_BB_SUMMARY);
		hr = Enum->Next(1, &Block, &Got);
	}

	return COMMAND_SUCCESS;

}
int
CmdBBGaps(char **szArgs)
{
	BOOL ReportFillBytes = FALSE;
	if (szArgs[1] && !stricmp(szArgs[1], "-a"))
		ReportFillBytes = TRUE;
	IDisEnumBASIC_BLOCK *Enum;
	HRESULT hr = pICfg->EnumBasicBlocks(&Enum);
	if ( FAILED(hr) )	{
		PRINT("Couldn't enum basic blocks!\n");
		return COMMAND_FAIL;
	}
	BASIC_BLOCK Block;
	DWORD Got;
	DWORD EndBlockAddress = 0;
	hr = Enum->Next(1, &Block, &Got);
	while ( SUCCEEDED(hr) && Got )	{
		if (Block.Address > EndBlockAddress)	{
			BOOL ReportThisBlock = TRUE;
			if (!ReportFillBytes)	{
				int Length = Block.Address - EndBlockAddress;
				ReportThisBlock = FALSE;
				DWORD Ptr = 0;
				pILdr->ConvertVirtualAddressToPtr(EndBlockAddress, &Ptr);
				for (int i=0;i<Length;i++)	{
					if (!Ptr || *(BYTE *)Ptr != 0xcc && *(BYTE *)Ptr != 0x0)	{
						ReportThisBlock = TRUE;
						break;
					}
				}
			}

			if (ReportThisBlock)
				PRINT("%X: %d unparsed bytes.\n", EndBlockAddress, Block.Address - EndBlockAddress);
		}

		EndBlockAddress = Block.Address + Block.Size;
		hr = Enum->Next(1, &Block, &Got);
	}

	return COMMAND_SUCCESS;

}

#define DUMP_SHOW_ASCII	0x1
#define DUMP_SHOW_UNICODE 0x2
BOOL
DumpData(
	DWORD VirtualAddress, 
	PVOID Pointer, 
	DWORD Length, 
	SIZE_ATTRIBUTE DataSize,
	DWORD Options)
{
	char *Buffer = new char [200];
	char *BytePointer = (char *)Pointer;
	_ASSERT(DataSize == SIZE_BYTE);	// only bytes, now.

	int BytesRemaining = (int)Length;
	while( BytesRemaining > 0 )	{
		int InitialBytesRemaining = BytesRemaining;

		//
		// Output virtual address as label
		//
		sprintf(Buffer, "%08X: ", VirtualAddress);
		//
		// Output 8 bytes
		//
		for (int i=0;i<BytesRemaining && i<8;i++)	{
			char b[8];
			sprintf(b, "%02X ", (DWORD)BytePointer[i]);
			strcat(Buffer, b);
		}
		BytesRemaining -= i;
		strcat(Buffer,"  ");

		//
		// Output 8 more bytes
		//
		for (i=0;i<BytesRemaining && i<8;i++)	{
			char b[8];
			sprintf(b, "%02X ", (DWORD)BytePointer[i]);
			strcat(Buffer, b);
		}
		BytesRemaining -= i;
		strcat(Buffer,"  ");

		//
		// Output characters
		//
		for (i=0;i<InitialBytesRemaining - BytesRemaining;i++)	{
			char *c = ".";
			
			if (isprint((unsigned int)BytePointer[i]))
				*c = BytePointer[i];
			else
				*c = '.';
			strcat(Buffer, c);
			if (i==7)
				strcat(Buffer, " ");
		}	
		strcat(Buffer, "\n");

		PRINT(Buffer);
		BytePointer += 16;
		VirtualAddress += 16;
	}

	return TRUE;
}

int
CmdDb(char **szArgs)
{
	if (!szArgs[1])
		return COMMAND_USAGE;
	DWORD dwAddr = GetAddressFromString(szArgs[1]);
	if (!dwAddr)	{
		PRINT("Invalid Address: %s\n", szArgs[1]);
		return COMMAND_FAIL;
	}
//	DWORD Length = strtodw(szArgs[2]);


	DWORD Ptr;
	HRESULT h = pILdr->ConvertVirtualAddressToPtr(dwAddr, &Ptr);
	if ( FAILED(h) || !Ptr )
		return COMMAND_FAIL;

	DumpData(dwAddr, (PVOID)Ptr, 16 * 8, SIZE_BYTE, 0);

	return COMMAND_SUCCESS;
}

extern int CmdHelp(char **);

#define BEGIN_COMMAND_MAP(_name)	\
	DIS_COMMAND_MAP _name[] = {
#define COMMAND_ENTRY(_com, _desc, _usage, _func )	\
	{ _com, _desc, _usage, _func },
#define END_COMMAND_MAP				\
	};

BEGIN_COMMAND_MAP(CommandMap)
	COMMAND_ENTRY(	"dis",		"Disassemble instructions",	
					"dis <address> [# of instructions]", CmdDisassemble)
	COMMAND_ENTRY(	"sym",		"Show symbol information",	
					"sym [address | name | partial name]",CmdSym)
	COMMAND_ENTRY(	"near",		"List symbols near address",
					"near <address>", CmdNear)
	COMMAND_ENTRY(	"dref",		"Find references to a data address", 
					"dref <address>", CmdDRef)
	COMMAND_ENTRY(	"cref",		"Find references to a code address", 
					"cref <address>", CmdCRef)
	COMMAND_ENTRY(	"parse",	"Parse code at given address", 
					"parse <address>", CmdParse)
	COMMAND_ENTRY(	"clear",	"Clear all control flow information", 
					"clear", CmdClear)
	COMMAND_ENTRY(	"bb",		"Disassemble a single basic block", 
					"bb <address>", CmdBB)
	COMMAND_ENTRY(	"proc",		"Disassemble a procedure",			
					"proc <address>", CmdProc)
	COMMAND_ENTRY(	"imp",		"List imports",			
					"imp", CmdImports)
	COMMAND_ENTRY(	"strings",		"Find all strings in image",			
					"strings", CmdStrings)
	COMMAND_ENTRY(	"bblist",		"Show all parsed basic blocks",			
					"bblist", CmdBBList)
	COMMAND_ENTRY(	"bbgaps",		"Show gaps in basic block list",			
					"bbgaps", CmdBBGaps)
	COMMAND_ENTRY(	"db",		"Dump bytes",			
					"db <address>", CmdDb)
	COMMAND_ENTRY(	"?",	"Get help", 
					"help [command]", CmdHelp)
END_COMMAND_MAP
#define NUM_COMMANDS (sizeof(CommandMap)/sizeof(CommandMap[0]))

void
ShowCommandUsage(const char *Command)
{
	for (int i=0;i<NUM_COMMANDS;i++)	{
		if (!stricmp(Command, CommandMap[i].szCmd))	{
			PRINT("%-30s %s\nUsage: %s\n", CommandMap[i].szCmd, CommandMap[i].szDesc, CommandMap[i].szUsage);
			break;
		}
	}
}

void
ShowCommandSummary(const char *Command)
{
	for (int i=0;i<NUM_COMMANDS;i++)	{
		if (!stricmp(Command, CommandMap[i].szCmd))	{
			PRINT("%-30s %s\n", CommandMap[i].szCmd, CommandMap[i].szDesc);
			break;
		}
	}
}

int
CmdHelp(char **szArgs)
{
	if (szArgs[1])	{
		ShowCommandUsage(szArgs[1]);
		return COMMAND_SUCCESS;
	}

	for (int i=0;i<NUM_COMMANDS;i++)	{
		ShowCommandSummary(CommandMap[i].szCmd);
	}

	return COMMAND_SUCCESS;
}

#define IS_WHITESPACE(c) ( (c)==' ' || (c)=='\n' || (c)=='\t' )
int DispatchCommand(PSTR szCmdLine)
{
	int rc=COMMAND_INVALID;

#define MAX_ARGS	16
	int i=0;
	
	//
	// Fill in the argument array
	//
	char *szArgs[MAX_ARGS];
	memset(szArgs, 0, sizeof(szArgs));
	char *sz = strtok(szCmdLine, " \n\t");
	if (!sz)
		return COMMAND_SUCCESS;

	szArgs[i++] = strdup ( sz );
	while ( (NULL != (sz = strtok(NULL, " \n\t"))) && i < MAX_ARGS )
		szArgs[i++] = strdup(sz);



	//
	// Find the appropriate command, and dispatch it
	//
	for (int j=0;j<NUM_COMMANDS;j++)	{
		if (!stricmp(szArgs[0], CommandMap[j].szCmd))	{
			try			{	rc = (*CommandMap[j].pFunc)(szArgs);	}
			catch(...)	{	PRINT("Fault in command routine.\n");	}
			break;
		}
	}

	//
	// Free the command line
	//
	for (int k=0;k<i;k++)
		free(szArgs[k]);

	if (COMMAND_USAGE == rc)
		ShowCommandUsage(szArgs[0]);

	return rc;
}

int main(int argc, char **argv)
{

	HRESULT h = CoInitialize(NULL);
	if ( FAILED(h) )	{
		printf("CoInitialize(NULL) failed: %X\n", h);
		exit(1);
	}

	//
	// Create one of each of our components
	//
	h = CoCreateInstance(CLSID_Ldr, NULL, CLSCTX_ALL, IID_IDisLdr, (void **)&pILdr);
	if ( FAILED(h) )	{
		printf("Failed to create loader: %X\n", h);
		exit(1);
	}

	h = CoCreateInstance(CLSID_Disx86, NULL, CLSCTX_ALL, IID_IDisDis, (void **)&pIDis);
	if ( FAILED(h) )	{
		printf("Failed to create disassembler: %X\n", h);
		exit(1);
	}

	h = CoCreateInstance(CLSID_Fmtx86, NULL, CLSCTX_ALL, IID_IDisFmt, (void **)&pIFmt);
	if ( FAILED(h) )	{
		printf("Failed to create formatter: %X\n", h);
		exit(1);
	}
#if 0
	h = CoCreateInstance(CLSID_SmxImageHlp, NULL, CLSCTX_ALL, IID_IDisSmX, (void **)&pISmX);
	if ( FAILED(h) )	{
		printf("Failed to create symbol extractor: %X\n", h);
		exit(1);
	}
#endif
	h = CoCreateInstance(CLSID_SymMgr, NULL, CLSCTX_ALL, IID_IDisSymMgr, (void **)&pISym);
	if ( FAILED(h) )	{
		printf("Failed to create symbol manager: %X\n", h);
		exit(1);
	}
	//
	// Load the Control Flow Graph component
	//
	if (pICfg) pICfg.Release();
	h = CoCreateInstance(CLSID_Cfg10, NULL, CLSCTX_ALL, IID_IDisCfg, (void **)&pICfg);
	if ( FAILED(h) )	{
		printf("Failed to create CFG: %X\n", h);
		exit(1);
	}

	h = pICfg->Attach( pILdr, pIDis, pISym );
	if ( FAILED(h) )	{
		printf("CFG failed to Attach: %X\n", h);
		exit(1);
	}

	pISym->CreateNew(L"\\test1.tlb");

	//
	// Set up the formatter with the information it needs to translate addresses
	// to symbolic names.
	//
	pIFmt->SetSymbolManager(pISym);

	if (argc > 1)	{
		BOOL rc = LoadImage(argv[1], pISym);
		if (!rc)
			printf("Could not load %s\n", argv[1]);
	}
	char cmd[128];
	char *c = "";
	int rc = 0;
	while (c)	{
		printf("\n>>");
		c = gets(cmd);
		if (!strcmp(c, "q"))
			break;

		rc = DispatchCommand(c);
		switch(rc)	{
		case COMMAND_INVALID:
			printf("<Unknown or invalid command>\n");
			break;
		case COMMAND_FAIL:
			printf("Command failed.\n");
			break;
		case COMMAND_USAGE:

		default:
			;
		}
	}

	return 0;
}
