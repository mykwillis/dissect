//
// All of this wants to be moved into the disassembler when it
// is all worked out.  The other modules of CFG should have no
// inside knowledge of the x86
//
#include "project.h"
#include "CExpression.h"

OLECHAR *RegisterNames[] =
{
	L"EAX",
	L"ECX",
	L"EDX",
	L"EBX",
	L"ESP",
	L"EBP",
	L"ESI",
	L"EDI"
};

REGISTER_BANK_SPEC RegSpec =
{
	4,	// register size in bytes
	8,	// number of registers in bank
	(OLECHAR *)RegisterNames
};

OLECHAR *FlagNames[] =
{
	L"CF",	// 00: carry flag
	L"x1",	// 01: reserved
	L"PF",	// 02: parity
	L"x2",	// 03: reserved
	L"AF",	// 04: alignment-check
	L"x3",	// 05: reserved
	L"ZF",	// 06: zero flag
	L"SF",	// 07: sign flag
	L"TF",	// 08: Trap flag
	L"IF",	// 09: Interrupt-enable
	L"DF",	// 10: direction
	L"OF",	// 11: Overflow
};


MACHINE_SPEC MachineSpec =
{
	1,			// number of register banks
	&RegSpec,	// register banks
	{ 0, 4 },	// stack pointer (bank 0, reg 4)
	12,			// number of flags
	FlagNames
};

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
isRet(INSTRUCTION &inst)
{
	if ( inst.hoc == (HOPCODE_CLASS)OC_RETN 
		|| inst.hoc == (HOPCODE_CLASS)OC_RETF )
		return TRUE;
	else
		return FALSE;
}


BOOL
isCtrlFlow(INSTRUCTION &inst)
{
	return ( isConditionalJmp(inst) || isUnconditionalJmp(inst) || isCall(inst) || isRet(inst) );
}

DWORD GetJmpTarget(INSTRUCTION &inst)
{
	switch( inst.op[0].cls )	{
	case OPERAND_CLASS_REG:
	case OPERAND_CLASS_REGPAIR:
	case OPERAND_CLASS_PORT:
		return 0;
	case OPERAND_CLASS_IMM:
		return inst.op[0].imm.imm32;
	case OPERAND_CLASS_DIRECT:
		return inst.op[0].direct.direct32;
	case OPERAND_CLASS_MEM:
		{
		if ( inst.op[0].mem.mask & ( MEMPTR_USE_BASE | MEMPTR_USE_SEG | MEMPTR_USE_IDX | MEMPTR_USE_SCALE ) )
			return 0;
#if 0	// This is a call through a pointer
		DWORD mask = inst.op[0].mem.mask;
		if ( mask & MEMPTR_USE_DISP8 )
			return inst.op[0].mem.disp8;
		if ( mask & MEMPTR_USE_DISP16 )
			return inst.op[0].mem.disp16;
		if ( mask & MEMPTR_USE_DISP32 )
			return inst.op[0].mem.disp32;
#endif // if 0
		}

		return 0;
	default:
		return 0;
	}

}
DWORD GetCallTarget(INSTRUCTION& inst)
{
	return GetJmpTarget(inst);
}

STDMETHODIMP
GetCtrlFlow(INSTRUCTION& inst, CTRL_FLOW *Flow)
{
	if ( isConditionalJmp(inst) )	{
		Flow->Type = CTRL_CJMP;
		Flow->cjmp.TrueTarget = GetJmpTarget(inst);
		Flow->cjmp.FalseTarget = inst.dwVirtualAddress + inst.dwLen;
		return S_OK;
	} else if ( isUnconditionalJmp(inst) )	{
		Flow->Type = CTRL_UJMP;
		Flow->ujmp.Target = GetJmpTarget(inst);
		return S_OK;
	} else if ( isCall(inst) )	{
		Flow->Type = CTRL_CALL;
		Flow->call.CallTarget = GetCallTarget(inst);
		Flow->call.FallTarget = inst.dwVirtualAddress + inst.dwLen;
		return S_OK;
	} else if ( isRet(inst) ) {
		Flow->Type = CTRL_RET;
		return S_OK;
	} else {
		Flow->Type = CTRL_FALL;
		Flow->fall.FallTarget = inst.dwVirtualAddress + inst.dwLen;
		return S_OK;
	}
}


//
// BUGBUG: Probably don't need this; can't we just rely on having QUADs
// set up that show all changes to StackPointer???
//
int
GetStackAdjustment(INSTRUCTION &inst)
{
	switch ((int)inst.hoc)	{
	case OC_PUSH:
		return -4;
	case OC_POP:
		return +4;
	case OC_CALL:
		return -4;
	case OC_RETF:
	case OC_RETN:
		return +4;
	case OC_ENTER:
		_ASSERT( inst.op[0].cls == OPERAND_CLASS_IMM );
		return - ( 4 + (int)inst.op[0].imm.imm32 );		// 4 for PUSH EBP, then the locals
	case OC_LEAVE:
		// this guy is going to take a little work; it effectively does
		// a MOV ESP, EBP / POP EBP.  We should know what EBP is relative to
		// ESP if ENTER was used in this function, but this is icky for now.
		return +4;	// for the POP EBP; still have to adjust for MOV ESP, EBP
	case OC_ADD:
		if (	( inst.op[0].cls == OPERAND_CLASS_REG )
			&&	( inst.op[0].reg.type == REGTYPE_GEN_DWORD )
			&&	( inst.op[0].reg.num == REG_NUM_SP ) 
			&&	( inst.op[1].cls == OPERAND_CLASS_IMM ) )	{
				return inst.op[1].imm.imm32;
		} else	{
			return 0;
		}
	case OC_SUB:
		if (	( inst.op[0].cls == OPERAND_CLASS_REG )
			&&	( inst.op[0].reg.type == REGTYPE_GEN_DWORD )
			&&	( inst.op[0].reg.num == REG_NUM_SP ) 
			&&	( inst.op[1].cls == OPERAND_CLASS_IMM )	) {
				return -(int)inst.op[1].imm.imm32;
		} else {
			return 0;
		}
		break;
	default:
		return 0;	// BUGBUG: We could have ADC, SBC, etc...
	}
}

STDMETHODIMP
GetAssignment(INSTRUCTION &inst, ASSIGNMENT &Assignment)
{
	if ( isCtrlFlow(inst) )
		return E_FAIL;

	switch( (int) inst.hoc )	{
	case OC_MOV:
		//
		// First operand is target, second operand is source
		//
		Assignment.Target = inst.op[0];	// struct copy
		Assignment.Source = CExpression::CreateOperandExpression( inst.op[1] );
		break;
	case OC_ADD:
		//
		// First operand is target and source1, second operand is source2
		//
		Assignment.Target = inst.op[0];
		Assignment.Source = CExpression::CreateBinaryExpression( OP_ADD, inst.op[0], inst.op[1] );
		break;
	default:
		return E_FAIL;
		break;
	}
	return S_OK;
}

#if 0
STDMETHODIMP
GetPushPop(INSTRUCTION &inst, PUSHPOP &PushPop)
{
	PushPop.IsPush = TRUE;
	switch ( (int)inst.hoc  )	{
	case OC_POP:
		PushPop.IsPush = FALSE;
		// fall through
	case OC_PUSH:
		PushPop.Operand = inst.op[0];
		break;
	case OC_POPF:
		PushPop.IsPush = FALSE;
		// fall through
	case OC_PUSHF:
		PushPop.Operand = inst.op[0];	// BUGBUG: This is flat wrong!!!
		break;
	default:
		return E_FAIL;
	}

	return S_OK;
}

BOOL
isPushPop(INSTRUCTION &inst)
{
	PUSHPOP Placeholder;
	return SUCCEEDED( GetPushPop(inst, Placeholder) );

}
#endif // if 0

BOOL
isAssignment(INSTRUCTION& inst)
{
	ASSIGNMENT Placeholder;
	return SUCCEEDED( GetAssignment(inst, Placeholder) );
}
//
// This function should eventually be implemented in a seperate 
// component specific to the INSTRUCTION type.
// We will eventually need to be able to return multiple statements
// for the same INSTRUCTION, i.e. DIV
//
STDMETHODIMP
GenerateStatement(INSTRUCTION& inst, STATEMENT *Statement)
{
	if ( isCtrlFlow(inst) )	{
		Statement->Type = STATEMENT_TYPE_CTRL;
		HRESULT h = GetCtrlFlow(inst, &Statement->Flow);
		if ( FAILED(h) )
			return h;
	} else if ( isAssignment(inst) )	{
		//
		// Simple assignment instruction
		Statement->Type = STATEMENT_TYPE_ASSIGNMENT;
		HRESULT h = GetAssignment(inst, Statement->Assignment);
		if ( FAILED(h) )
			return h;
#if 0
	} else if ( isPushPop(inst) )	{
		Statement->Type = STATEMENT_TYPE_PUSHPOP;
		HRESULT h = GetPushPop(inst, Statement->PushPop);
		if ( FAILED(h) )
			return h;
#endif // if 0
	} else {
		//
		// unknown
		//
		_ASSERT(0);
#if 0
		Statement->Type = STATEMENT_TYPE_UNKNOWN;
#endif // if 0
	}

	return S_OK;
}

#if 0
STDMETHODIMP
GenerateUCode(INSTRUCTION& inst, UCODE *uCode, int size, /*out*/ int *num)
{
	size;
	*num = 0;

	//
	// Since we only have one uCode per instruction right now, just
	// assign the stack adjustment of the instruction to this ucode
	//
	uCode[0].StackAdjustment = GetStackAdjustment(inst);

	if ( isCtrlFlow(inst) )	{
		//
		// Simple control flow instruction
		//
		*num = 1;
		uCode[0].Type = UCODE_TYPE_CTRL;
		HRESULT h = GetCtrlFlow(inst, &uCode[0].Flow);
		if ( FAILED(h) )
			return h;
	} else if ( isAssignment(inst) )	{
		//
		// Simple assignment instruction
		*num = 1;
		uCode[0].Type = UCODE_TYPE_ASSIGNMENT;
		HRESULT h = GetAssignment(inst, uCode[0].Assignment);
		if ( FAILED(h) )
			return h;
	} else {
		//
		// Not so simple instruction.  Process individually
		//
		switch((int)inst.hoc)	{
		case 0:
		default:
			*num = 1;
			uCode[0].Type = UCODE_TYPE_UNKNOWN;
		}
	}

	return S_OK;
}
#endif // if 0


#if OLD_CODE_BUT_KEEP_ME

#endif // OLD_CODE_BUT_KEEP_ME

STDMETHODIMP
TranslateREGToREGUSE( REG& Reg, REGUSE *RegUse )
{
	_ASSERT( RegUse != NULL );
	_ASSERT( RegUse->Mask = 0 );

	switch ( Reg.type )	{
	case REGTYPE_GEN_QWORD:
		RegUse->Mask |= 0xff;
		// fall
	case REGTYPE_GEN_DWORD:
		RegUse->Mask |= 0x0f;
		// fall
	case REGTYPE_GEN_WORD:
		RegUse->Mask |= 0x03;
		// fall
	case REGTYPE_GEN_BYTE:
		RegUse->Mask |= 0x01;

		// common code for all general regs
		RegUse->Register.Bank = 0;
		RegUse->Register.Index = Reg.num;
		return S_OK;

	case REGTYPE_MMX:
	case REGTYPE_CONTROL:
	case REGTYPE_TEST:
	case REGTYPE_DEBUG:
	case REGTYPE_SEG:
	case REGTYPE_FLAGS:
	case REGTYPE_SYSTEM:
		return E_NOTIMPL;
	default:
		return E_FAIL;
	}
}