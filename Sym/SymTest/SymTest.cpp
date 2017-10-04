//
// Disable annoying Level 4 warnings
//
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

#include <afxtempl.h>

#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>


#include <windows.h>
#include <comcat.h>	// ICatRegister

//
// Private CLSIDs
//
#include "guids.h"				
#include "..\..\common\sym.h"

int main()
{
	CComPtr<IDisSymMgr> pISym;

	HRESULT h = CoInitialize(NULL);
	if ( FAILED(h) )	{
		printf("CoInitialize(NULL) failed: %X\n", h);
		exit(1);
	}

	h = CoCreateInstance(CLSID_SymMgr, NULL, CLSCTX_ALL, IID_IDisSymMgr, (void **)&pISym);
	if ( FAILED(h) )	{
		printf("Failed to create symbol manager: %X\n", h);
		exit(1);
	}

	h = pISym->CreateNew(L"\\typelib.tlb");
	if ( FAILED(h) )	{
		printf("Failed to create new type library: %X\n", h);
		exit(1);
	}
//#if 0
	CComPtr<IDisSmX> pISmX;
	h = CoCreateInstance(CLSID_SmxImageHlp, NULL, CLSCTX_ALL, IID_IDisSmX, (void **)&pISmX);
	if ( FAILED(h) )	{
		printf("Failed to create symbol extractor: %X\n", h);
	}

	OutputDebugString("Extracting symbols from SymMgr...\n");
	h = pISmX->Extract(L"d:\\dis\\sym\\symmgr\\debug\\symmgr.dll", 0, pISym);
	if ( FAILED(h) )	{
		printf("Failed to extract symbols from symmgr: %X\n", h);
	}

	OutputDebugString("Extracting symbols from SmxImageHlp...\n");
	h = pISmX->Extract(L"d:\\dis\\sym\\smximagehlp\\debug\\smximagehlp.dll", 0, pISym);
	if ( FAILED(h) )	{
		printf("Failed to extract symbols from symmgr: %X\n", h);
	}
	
	OutputDebugString("Extracting symbols from Disx86_10...\n");
	h = pISmX->Extract(L"d:\\dis\\dis\\disx86_10\\debug\\disx86_10.dll", 0, pISym);
	if ( FAILED(h) )	{
		printf("Failed to extract symbols from symmgr: %X\n", h);
	}

	OutputDebugString("Extracting symbols from LdrPE...\n");
	h = pISmX->Extract(L"d:\\dis\\ldr\\ldrpe\\debug\\ldrpe.dll", 0, pISym);
	if ( FAILED(h) )	{
		printf("Failed to extract symbols from symmgr: %X\n", h);
	}


//#endif // if 0
	//
	// Add a module
	//
	MODULE_INFO ModuleInfo;
	ModuleInfo.Name			= ::SysAllocString(L"TestMod.dll");
	ModuleInfo.DocString	= ::SysAllocString(L"Some witty comment");
	ModuleInfo.BaseAddress	= 0x01000000;
	ModuleInfo.Size			= 0x00001000;

	CComPtr<IModule> pIModule;
	h = pISym->AddModule(&pIModule, &ModuleInfo);
	if (FAILED(h))	{
		printf("Failed to add module: %X\n", h);
		exit(1);
	}

	::SysFreeString( ModuleInfo.Name );
	::SysFreeString( ModuleInfo.DocString );

	//
	// Add a type
	//
	TYPE_INFO TypeInfo;
	TypeInfo.Name = ::SysAllocString(L"SOME_TYPE");
	TypeInfo.DocString = ::SysAllocString(L"Here's what this type does...");
	TypeInfo.Size = 4;
	TypeInfo.TypeKind = TKIND_RECORD;
	TypeInfo.Record.NumberOfMembers = 2;
	HTYPE Types[2] = { STANDARD_HTYPE( VT_UI4 ), STANDARD_HTYPE( VT_UI2 ) };
	TypeInfo.Record.Types = (HTYPE *)Types;
	BSTR Names[2]; 
	Names[0] = ::SysAllocString(L"ulLongField"); 
	Names[1] = ::SysAllocString(L"usShortField"); 
	TypeInfo.Record.Names = (BSTR *)Names;

	CComPtr<IType> pIType;
	h = pISym->AddType(&pIType, &TypeInfo);
	if ( FAILED(h) )	{
		printf("Failed to add type: %x\n", h);
		exit(1);
	}

	HTYPE TypeHandle;
	h = pISym->GetTypeHandle(&TypeHandle, pIType);
	if ( FAILED(h) )	{
		printf("Failed to get type handle: %x\n", h);
		exit(1);
	}

	
	::SysFreeString( TypeInfo.Record.Names[0] );
	::SysFreeString( TypeInfo.Record.Names[1] );

	//
	// Add a symbol
	//
	SYMBOL_INFO SymbolInfo;
	SymbolInfo.Name			= ::SysAllocString(L"Function_1");
	SymbolInfo.DocString	= ::SysAllocString(L"Use me like this...");
	SymbolInfo.Address		= 0x01000500;
	SymbolInfo.Size			= 20;

	SymbolInfo.SymKind				= SKIND_FUNC;
	SymbolInfo.Function.FuncKind	= FUNC_STATIC;
	SymbolInfo.Function.InvKind		= INVOKE_FUNC;
	SymbolInfo.Function.CallConv	= CC_STDCALL;
	SymbolInfo.Function.ReturnType	= TypeHandle;
	
	SymbolInfo.Function.NumberOfParams = 0;
	SymbolInfo.Function.Types = NULL;
	SymbolInfo.Function.Names = NULL;

	CComPtr<ISymbol> pISymbol;
	h = pISym->AddSymbol(&pISymbol, &SymbolInfo);
	if ( FAILED(h) )	{
		printf("Failed to add symbol: %x\n", h);
		exit(1);
	}

	pISym->CloseTypeHandle(TypeHandle);

	::SysFreeString( SymbolInfo.Name );
	::SysFreeString( SymbolInfo.DocString );

	return 0;

}

#if 0
int main()
{
	IDisSymMgr *pISym;

	HRESULT h = CoInitialize(NULL);
	if ( FAILED(h) )	{
		printf("CoInitialize(NULL) failed: %X\n", h);
		exit(1);
	}

	h = CoCreateInstance(CLSID_SymMgr, NULL, CLSCTX_ALL, IID_IDisSymMgr, (void **)&pISym);
	if ( FAILED(h) )	{
		printf("Failed to create symbol manager: %X\n", h);
		exit(1);
	}

	LPWSTR Name;
	DWORD Values[4];
	LPWSTR Names[4];
	HTYPE Types[4];
	int cMembers=0;

	//
	// Add an enumeration
	//
	HTYPE hEnum;
	Name = L"Enumeration1";
	cMembers = 4;

	Values[0] = 0;
	Values[1] = 4;
	Values[2] = 8;
	Values[3] = 12;


	Names[0] = L"Enum_Value_0";
	Names[1] = L"Enum_Value_4";
	Names[2] = L"Enum_Value_8";
	Names[3] = L"Enum_Value_12";

	h = pISym->AddEnum(&hEnum, Name, cMembers, Values, Names);
	if ( FAILED(h) )	{
		printf("Failed to create enum: %Xh", h);
		exit(1);
	}

	//
	// Add a structure
	//
	HTYPE hStruct;
	Name = L"Structure1";
	cMembers = 3;
	
	Types[0] = hEnum;
	Types[1] = STANDARD_HTYPE( VT_UI4 );
	Types[2] = STANDARD_HTYPE( VT_CY );

	Names[0] = L"StructureEnumerationMember";
	Names[1] = L"UintThing";
	Names[2] = L"MoneyMoney";

	h = pISym->AddStruct(&hStruct, Name, cMembers, Types, Names);
	if ( FAILED(h) )	{
		printf("Failed to create struct: %Xh", h);
		exit(1);
	}

	//
	// Add a union
	//
	HTYPE hUnion;
	Name = L"Union1";
	cMembers = 2;

	Types[0] = hEnum;
	Types[1] = hStruct;

	Names[0] = L"Enum";
	Names[1] = L"Struct";

	h = pISym->AddUnion(&hUnion, Name, cMembers, Types, Names);
	if ( FAILED(h) )	{
		printf("Failed to create union: %Xh", h);
		exit(1);
	}

	//
	// Add a typedef
	//
	HTYPE hTypedef;
	Name = L"TypedefForUnion1";
	h = pISym->AddTypedef(&hTypedef, Name, hUnion);
	if ( FAILED(h) )	{
		printf("Failed to create typedef: %Xh", h);
		exit(1);
	}

	//
	// Get info on what we have
	//
	BSTR EnumName;
	h = pISym->GetTypeName(hEnum, &EnumName);
	if ( FAILED(h) )	{
		printf("Failed to get enum name: %Xh\n", h);
		exit(1);
	}
	printf("Enum Name is %ws.\n", EnumName);
	::SysFreeString(EnumName);

	BSTR StructName;
	h = pISym->GetTypeName(hStruct, &StructName);
	if ( FAILED(h) )	{
		printf("Failed to get Struct name: %Xh\n", h);
		exit(1);
	}
	printf("Struct Name is %ws.\n", StructName);
	::SysFreeString(StructName);

	BSTR UnionName;
	h = pISym->GetTypeName(hUnion, &UnionName);
	if ( FAILED(h) )	{
		printf("Failed to get Union name: %Xh\n", h);
		exit(1);
	}
	printf("Union Name is %ws.\n", UnionName);
	::SysFreeString(UnionName);

	BSTR TypedefName;
	h = pISym->GetTypeName(hTypedef, &TypedefName);
	if ( FAILED(h) )	{
		printf("Failed to get Typedef name: %Xh\n", h);
		exit(1);
	}
	printf("Typedef Name is %ws.\n", TypedefName);
	::SysFreeString(TypedefName);


	//
	// Search for types by name
	//
	HTYPE hEnum2 = NULL;
	h = pISym->GetTypeByName(&hEnum2, L"Enumeration1");
	if ( FAILED(h) )	{
		printf("Couldn't find enum by name: %Xh", h);
		exit(1);
	}
	if (hEnum != hEnum2)	{
		printf("Got wrong enum handle!\n");
		exit(1);
	}

	HTYPE hStruct2 = NULL;
	h = pISym->GetTypeByName(&hStruct2, L"Structure1");
	if ( FAILED(h) )	{
		printf("Couldn't find struct by name: %Xh", h);
		exit(1);
	}
	if (hStruct != hStruct2)	{
		printf("Got wrong struct handle!\n");
		exit(1);
	}


	//
	// Add a function
	//
	HSYMBOL hSymbol;
	BSTR bsName = ::SysAllocString( L"ImAFunction" );
	int cParams = 3;
	Types[0] = STANDARD_HTYPE( VT_UI1 );
	Types[1] = STANDARD_HTYPE( VT_UI2 );
	Types[2] = STANDARD_HTYPE( VT_UI4 );
	Names[0] = L"LittleGuy";
	Names[1] = L"MediumFella";
	Names[2] = L"Gargantuan";
	
	h = pISym->AddFunction(&hSymbol,
							bsName,
							FUNC_STATIC,
							INVOKE_FUNC,
							CC_STDCALL,
							0x40000000,
							STANDARD_HTYPE( VT_CY ),
							cParams,
							Types,
							Names);
	if ( FAILED(h) )	{
		printf("Failed to add function: %Xh", h);
		exit(1);
	}

	pISym->Release();

	return 0;
}

#endif // if 0