#include "project.h"
#include "CInstructionFormatter.h"
#include "..\..\Dis\Disx86_10\CReg.h"
#include "..\..\Dis\Disx86_10\CFundamentalDataType.h"


//
// DANGER
//
#define DO(_o)	OC_##_o,
typedef enum {
#include "..\..\dis\disx86_10\opcodes.dat"
} OPCODES;




BOOL
isUnconditionalJmp(INSTRUCTION &inst)
{
	if ( inst.hoc == (HOPCODE_CLASS)OC_JMP )
		return TRUE;
	else
		return FALSE;
}

BOOL
isConditionalJmp(INSTRUCTION &inst)
{
	if ( !isUnconditionalJmp(inst) && inst.hoc >= (HOPCODE_CLASS)OC_JO && inst.hoc <= (HOPCODE_CLASS)OC_JNLE )
		return TRUE;
	else
		return FALSE;
}
BOOL
isCall(INSTRUCTION &inst)
{
	if ( inst.hoc == (HOPCODE_CLASS)OC_CALL )
		return TRUE;
	else
		return FALSE;
}

BOOL
isJmpOrCall(INSTRUCTION& inst)
{
	return isConditionalJmp(inst) || isUnconditionalJmp(inst) || isCall(inst);
}

//
//
//
// Here's a whole bunch of formatting shit that we'll want to clean up
//
//
//

/*
typedef struct tagMEMPTR {
	SIZE_ATTRIBUTE	address_size;	// size of the final effective address (pointer)
	SIZE_ATTRIBUTE	operand_size;
	REG		seg;	// segment register
	REG		base;	// base register
	REG		idx;	// index register
	int		scale;	// scale factor applied to index register
	[ switch_type(SIZE_ATTRIBUTE), switch_is(address_size) ]
	union {
		[case (SIZE_8)]
		BYTE	disp8;
		[case (SIZE_16)]
		WORD	disp16;
		[case (SIZE_32)]
		DWORD	disp32;
		[case (SIZE_64)]
		QWORD	disp64;
	} NAMELESS_UNION;
	DWORD	mask;	// use mask; see MEMPTR_USE flags
} MEMPTR;
#define MEMPTR_USE_SEG		0x1		// segment register used in address calculation
#define MEMPTR_USE_BASE		0x2		// base register used in address calculation
#define MEMPTR_USE_IDX		0x4		// index register used in address calculation
#define MEMPTR_USE_SCALE	0x8		// scale factor applied to index used in address calculation
#define MEMPTR_USE_DISP8	0x10	// 8-bit displacement used in address calculation
#define MEMPTR_USE_DISP16	0x20	// 16-bit displacement used in address calculation
#define MEMPTR_USE_DISP32	0x40	// 32-bit displacement used in address calculation
#define MEMPTR_USE_DISP64	0x80	// 64-bit displacement used in address calculation
*/
int
CInstructionFormatter::FormatOPERAND_MEMPTR(MEMPTR& mp, char *pBuf, int cBuf)
{
	char buf2[64];
	switch( mp.operand_size )	{
	case SIZE_8:
		strcpy(pBuf, "byte ptr ");
		break;
	case SIZE_16:
		strcpy(pBuf, "word ptr ");
		break;
	case SIZE_32:
		strcpy(pBuf, "dword ptr ");
		break;
	case SIZE_48:
		strcpy(pBuf, "tword ptr ");
		break;
	case SIZE_64:
		strcpy(pBuf, "qword ptr ");
		break;
	default:
		*pBuf =0;
	}

	if ( mp.mask & MEMPTR_USE_SEG )	{
		strcat(pBuf, CReg::Name( mp.seg ) );
		strcat(pBuf, ":");
	}
	strcat(pBuf, "[");
	if ( mp.mask & MEMPTR_USE_BASE )	{
		strcat(pBuf, CReg::Name( mp.base ) );
	}
	if ( mp.mask & MEMPTR_USE_IDX )	{
		strcat(pBuf, "+");
		strcat(pBuf, CReg::Name( mp.idx ) );
	}
	if ( mp.mask & MEMPTR_USE_SCALE )	{
		_ASSERT( mp.mask & MEMPTR_USE_IDX );	// scale applies only to index
		sprintf((char *)buf2, "*%d", mp.scale);
		strcat(pBuf, buf2);
	}

	//
	// If the base and index are not specified, we just have a displacement.
	// in this case, ask the symbol manager (if available) what symbol
	// this points to.
	//
	if ( m_pISym && ((mp.mask & (MEMPTR_USE_BASE | MEMPTR_USE_IDX)) == 0) )	{
		// we currently only deal with 32 bit displacements...
		if ( mp.mask & MEMPTR_USE_DISP32 == 0 )
			goto get_dword_displacement;

		CComPtr<ISymbol> pISymbol;
		if (FAILED(m_pISym->GetSymbolByAddress(&pISymbol, mp.disp32)))
			goto get_dword_displacement;
		SYMBOL_INFO *SymbolInfo;
		if (FAILED(pISymbol->GetSymbolInfo(&SymbolInfo)))
			goto get_dword_displacement;

		strcat(pBuf, astring(SymbolInfo->Name));

		int delta = mp.disp32 - SymbolInfo->Address;
		if (delta)	{
			char tbuf[10];
			strcat(pBuf, "+0x");
			sprintf(tbuf, "%X", delta);
			strcat(pBuf, tbuf);
		}

		char tbuf[10];
		strcat(pBuf, " (");
		sprintf(tbuf, "%X", mp.disp32);
		strcat(pBuf, tbuf);
		strcat(pBuf, ")");
		
		pISymbol->ReleaseSymbolInfo(SymbolInfo);

	} else {
get_dword_displacement:
		//
		// Grab a DWORD of the displacement
		//
		CDisplacement disp;
		char *fmt="";	// format specifyer
		if ( mp.mask & MEMPTR_USE_DISP8 )	{
			disp.SetValue( mp.disp8, TRUE /* signed */ );
			fmt = "%c%02X";
		} else if ( mp.mask & MEMPTR_USE_DISP16 )	{
			disp.SetValue( mp.disp16, TRUE /* signed */ );
			fmt = "%c%04X";
		} else if ( mp.mask & MEMPTR_USE_DISP32 )	{
			disp.SetValue( mp.disp32, TRUE /* signed */ );
			fmt = "%c%08X";
		}

		if ( mp.mask & ( MEMPTR_USE_DISP8 | MEMPTR_USE_DISP16 | MEMPTR_USE_DISP32 ) )	{
			sprintf(buf2, fmt, disp.GetSign(), disp.GetMagnitude() );
			strcat(pBuf, buf2);
		}
	}

	strcat(pBuf, "]");
	return strlen(pBuf)+1;
}

int
CInstructionFormatter::FormatOPERAND_IMM(IMM& imm, char *pBuf, int cBuf, BOOL bXlate)
{
		switch(imm.size)	{
		case SIZE_8:
			sprintf(pBuf, "%02Xh", (DWORD) imm.imm8 );
			break;
		case SIZE_16:
			sprintf(pBuf, "%04Xh", (DWORD) imm.imm16 );
			break;
		case SIZE_32:
			{
				if (!bXlate)
					goto normal;

				CComPtr<ISymbol> pISymbol;
				if (FAILED(m_pISym->GetSymbolByAddress(&pISymbol, imm.imm32)))
					goto normal;
				SYMBOL_INFO *SymbolInfo;
				if (FAILED(pISymbol->GetSymbolInfo(&SymbolInfo)))
					goto normal;

				strcpy(pBuf, astring(SymbolInfo->Name));

				int delta = imm.imm32 - SymbolInfo->Address;
				if (delta)	{
					char tbuf[10];
					strcat(pBuf, "+0x");
					sprintf(tbuf, "%X", delta);
					strcat(pBuf, tbuf);
				}

				char tbuf[10];
				strcat(pBuf, " (");
				sprintf(tbuf, "%X", imm.imm32);
				strcat(pBuf, tbuf);
				strcat(pBuf, ")");

				pISymbol->ReleaseSymbolInfo(SymbolInfo);
				break;
			}
normal:
			sprintf(pBuf, "%08Xh", (DWORD) imm.imm32 );
			break;
//		case SIZE_64:
//			sprintf(pBuf, "%04Xh", (DWORD) imm.imm16 );
//			break;
		default:
			strcpy(pBuf, "????");
			break;
		}

	return strlen(pBuf)+1;
}

int
FormatOPERAND_DIRECT(DIRECT& direct, char *pBuf, int cBuf)
{
		switch(direct.size)	{
//		case SIZE_8:
//			sprintf(pBuf, "%02Xh", (DWORD) direct.direct8 );
//			break;
//		case SIZE_16:
//			sprintf(pBuf, "%04Xh", (DWORD) direct.direct16 );
//			break;
		case SIZE_32:
			sprintf(pBuf, "%08Xh", (DWORD) direct.direct32 );
			break;
		case SIZE_48:
			sprintf(pBuf, "%04X:%08X", (DWORD) direct.direct48.wHi, (DWORD) direct.direct48.dwLo );
			break;

//		case SIZE_64:
//			sprintf(pBuf, "%04Xh", (DWORD) direct.direct16 );
//			break;
		default:
			strcpy(pBuf, "????");
			break;
		}

	return strlen(pBuf)+1;
}

/*
typedef struct tagOPERAND {
	OPERAND_CLASS	cls;	// OPERAND_CLASS_x constant
	DWORD			flags;	// see OPERAND_FLAG_xxx flags
	[ switch_type(OPERAND_CLASS), switch_is(cls) ]
	union {
		[case(OPERAND_CLASS_MEM)]
		MEMPTR	mem;
		[case(OPERAND_CLASS_REG)]
		REG		reg;
		[case(OPERAND_CLASS_REGPAIR)]
		REG		regpair[2];	
		[case(OPERAND_CLASS_PORT)]
		IOPORT	port;
		[case(OPERAND_CLASS_IMM)]
		IMM		imm;
		[case(OPERAND_CLASS_DIRECT)]
		DIRECT		direct;
		[default]
		;
	} NAMELESS_UNION;
} OPERAND;
*/
int
CInstructionFormatter::FormatOPERAND(OPERAND& op, char *pBuf, int cBuf, BOOL bXlate)
{
	switch( op.cls )	{
	case OPERAND_CLASS_MEM:
		FormatOPERAND_MEMPTR(op.mem, pBuf, cBuf);
		break;
	case OPERAND_CLASS_REG:
		strcpy(pBuf, CReg::Name( op.reg ) );
		break;
	case OPERAND_CLASS_REGPAIR:
		strcpy(pBuf, CReg::Name( op.regpair[0] ) );
		strcat(pBuf, ":");
		strcat(pBuf, CReg::Name( op.regpair[1] ) );
		break;
	case OPERAND_CLASS_IMM:
		FormatOPERAND_IMM(op.imm, pBuf, cBuf, bXlate);
		break;
	case OPERAND_CLASS_DIRECT:
		FormatOPERAND_DIRECT(op.direct, pBuf, cBuf);
		break;
	case OPERAND_CLASS_PORT:
		sprintf(pBuf, "%04Xh", op.port );
		break;
	default:
		strcpy(pBuf, "[Invalid]");
		break;
	}
	return strlen(pBuf)+1;
}

STDMETHODIMP
CInstructionFormatter::GetInstructionString(PINSTRUCTION pInst, BSTR *pbstr)
{
	char buf[256];
	GetAnsiString2(*pInst, (unsigned char *)&buf, sizeof(buf));
	*pbstr = ::SysAllocString( wstring(buf) );
	return S_OK;

}
STDMETHODIMP
CInstructionFormatter::GetAnsiString(IDisInstruction *pIInst, unsigned char *pStr, ULONG ulLen)
{
	INSTRUCTION inst;
	HRESULT hr = pIInst->GetINSTRUCTION(&inst);
	_ASSERT( SUCCEEDED(hr) );
	return GetAnsiString2(inst, pStr, ulLen);
}

STDMETHODIMP
CInstructionFormatter::GetAnsiString2(INSTRUCTION &inst, unsigned char *pStr, ULONG ulLen)
{
	char *pBuf = (char *)pStr;	// god MIDL is annoying...

	//
	// Output virtual address as label
	//
	sprintf(pBuf, "%08X: ", inst.dwVirtualAddress);
	
	//
	// Output code bytes
	//
	for (int i=0;i<(int)inst.dwLen;i++)	{
		char b[8];
		sprintf(b, "%02X ", inst.bytes[i]);
		strcat(pBuf, b);
	}

	//
	// Pad with spaces til column 40
	//
	int pos = strlen(pBuf);
	while (pos < 40)
		pBuf[pos++] = ' ';
	pBuf[pos] = 0;

	//
	// Output class name
	//
	strcat(pBuf, (char *)inst.AnsiName);
	
	//
	// Pad with spaces til column 50
	//
	pos = strlen(pBuf);
	while (pos < 50)
		pBuf[pos++] = ' ';
	pBuf[pos] = 0;

	//
	// Output each operand
	//
	BOOL bXlate;
	if (isJmpOrCall(inst))
		bXlate = TRUE;
	else
		bXlate = FALSE;
	for (i=0;i<inst.cOperands;i++)	{
		char buf[64];
		FormatOPERAND(inst.op[i], (char *)&buf, sizeof(buf), bXlate);
		strcat(pBuf, (char *)buf);
		strcat(pBuf, ",");
	}

	//
	// Get rid of the extra ',' at the end
	//
	pos = strlen(pBuf);
	pBuf[pos-1] = 0;

	return S_OK;
}

STDMETHODIMP
CInstructionFormatter::SetSymbolManager(IDisSymMgr *pISym)
{
	m_pISym = pISym;	// auto ref-count
	return S_OK;
}