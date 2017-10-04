#include "project.h"
#include "CInstruction.h"
#include "COperand.h"
#include "CReg.h"
#include "XDisException.h"
#include "CEffectiveAddress.h"
#include "CFundamentalDataType.h"
#include "COperandType.h"

// Use
PCSTR
EffectiveAddress16Names[] =
{
	"bx+si",
	"bx+di",
	"bp+si",
	"bp+di",
	"si",
	"di",
	"bp",
	"bx"
};

PCSTR
EffectiveAddress32Names[] =
{
	"eax",
	"ecx",
	"edx",
	"ebx",
	"XX--invalid--XX",
	"ebp",
	"esi",
	"edi"
};

COperand::COperand(CInstruction& inst, OPDEF opDef)
:m_inst(inst)
{
	m_opDef = opDef;
}


//
// "Type" is Intel-speak for "Size"...
//
PCSTR
COperand::GetTypeName() const
{
	// some opcodes have a register hardcoded into them.  check for
	// that case.
	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return "register";
	}
	
	COperandType type( OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() );
	return type.GetName();

}

#ifdef _AFX
//
// This routine returns a string giving the "meat" of what
// the operand is; that is, the address, offset, immediate
// value, or register to which it corresponds.
//
CString
COperand::GetAddressString() const
{
	CString str;
	MODRM modrm;

	// grab the modrm since we may need it
	if ( m_inst.hasModRM() )
		modrm = m_inst.GetModRM();
	
	// some instructions have a register hard-coded into them,
	// so catch that case.
	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return GetEncodedRegisterString();
	}

	switch( OPERAND_ADDRESSING(m_opDef) )	{

	case ADDR_DIRECT:		// address of operand encoded in instruction
		// i think this should be like this; but why is it different from
		// ADDR_OFFSET?  Answer-> It's only different because it's a whole pointer,
		// including the segment.

		// get the PTR from effective address....

		str = "XXXencoded in instXXX";
		break;
	case ADDR_REG_CONTROL:	// modRM selects a control register
		str = CReg::NameControl( modrm.reg );
		break;
	case ADDR_REG_DEBUG:	// modRM selects a debug register
		str = CReg::NameDebug( modrm.reg );
		break;
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		str = GetModRMAddressString();
		break;
	case ADDR_FLAGS:		// flags register
		str = "EFLAGS";
		break;
	case ADDR_REG_GEN:		// modRM selects a general register
		// i think this is supposed to mean that the REG field of modRM selects
		// the general register...
		// ALERT
		// If this is a BYTE operand, we don't get the right register
		// value with this call.
		// should be...
		// if ( isByteOperand() )
		//   szAddr = GetGeneralByteRegisterName()...
		// else
		//   szAddr = GetGeneralRegisterName()...
		//
		str = m_inst.GetGeneralRegisterName( modrm.reg );
		break;
	case ADDR_REG_MMX:		// modRM selects an MMX register
		str = CReg::NameMMX( modrm.reg );
		break;
	case ADDR_IMM:			// immediate data
		{
			CImmediate imm;
			m_inst.GetImmediate(imm, TRUE /* signed */);
			str = imm.GetCString();
		}
		break;
	case ADDR_RELOFFSET:	// offset to be added to instruction counter
		{
			if ( m_inst.GetAddressSizeAttribute() == SIZE_16 )	{
				//
				// Get the immediate value.  If it is not 2 bytes,
				// it will be sign-extended.
				//
				CImmediate imm;
				m_inst.GetImmediate(imm, TRUE /* signed */);
				WORD wAddr = imm.value16();

				//
				// Add the IP of the following instruction
				//
				wAddr += (WORD)m_inst.GetVirtualAddress();
				wAddr += (WORD)m_inst.GetInstructionSize();

				//
				// Reuse the CImmediate to format the string
				//
				imm.SetValue(wAddr, SIZE_16, FALSE /* unsigned */);
				str = imm.GetCString();
			} else {	// 32 bit addressing
				//
				// Get the immediate value.  If it was not 4 bytes, it
				// will be sign-extended.
				//
				CImmediate imm;
				m_inst.GetImmediate(imm, TRUE /* signed */);
				DWORD dwAddr = imm.value32();

				//
				// Add the EIP of the following instruction
				//
				dwAddr += (DWORD)m_inst.GetVirtualAddress();
				dwAddr += (DWORD)m_inst.GetInstructionSize();

				//
				// Reuse the CImmediate to format the string
				//
				imm.SetValue(dwAddr, SIZE_32, FALSE /* unsigned */ );
				str = imm.GetCString();
			}
		}
		break;
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
		return GetModRMAddressString();
		break;
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word 
		{
			CImmediate imm;
			m_inst.GetImmediate(imm, FALSE /* unsigned */);
			str = imm.GetCString();
		}
		break;
	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
		// What this guy really means is that the mod field is 011b, meaning it is
		// actually the R/M field that chooses the register.
		ASSERT( 0x3 == modrm.mod );
		str = m_inst.GetGeneralRegisterName( modrm.rm );
		break;
	case ADDR_REG_SEG:		// modRM selects a segment register
		//str = "modRM select seg";
		str = CReg::NameSeg( modrm.rm );
		break;
	case ADDR_REG_TEST:		// modRM selects a test register
		//str = "modRM select test";
		str = CReg::NameTest( modrm.rm );
		break;
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
		//str = "DS:SI";
		// arguments are implicit
		str = "";
		break;
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
		//str = "ES:DI";
		str = "";
		break;
	default:
		ASSERT(0);
		str = "XXX";
		break;
	}

	return str;
}
#endif // _AFX

//
// GetEncodedRegisterString() returns a string corresponding to a register
// that is encoded in this instruction, i.e., not specified by any
// field of the instruction.
// Registers specified in this manner are typically either byte
// registers, or default-size registers (eAX, eBX, etc).
// A register could also be a segment register, as in PUSH CS.
PCSTR
COperand::GetEncodedRegisterString() const
{
	ASSERT( OPERAND_IS_ENCODED_REG( m_opDef ) );
	PCSTR pName;

	WORD rNum = OPERAND_ENCODED_REG_IDX( m_opDef );

	// process segment registers
	if ( OPERAND_IS_SEG_REG(m_opDef) )	{
		pName = CReg::NameSeg(rNum);
	} else if ( OPERAND_IS_BYTE_REG(m_opDef) )	{
		pName = CReg::Name8(rNum);
	} else {
		// GetGeneralRegisterName() automatically returns correct size (i.e., ax, eax)
		pName = m_inst.GetGeneralRegisterName(rNum);
	}

	return pName;
}

#ifdef _AFX
CString
COperand::GetModRMAddressString(void) const
{
	return (m_inst.GetAddressSizeAttribute() == SIZE_16) ?
		GetModRMAddressName16()
	:	GetModRMAddressName32();
}
#endif // _AFX

#ifdef _AFX
CString
COperand::GetModRMAddressName16() const
{
	MODRM modrm;
	CString str;

	if (m_inst.hasModRM())
		modrm = m_inst.GetModRM();

	switch( modrm.mod )	{
	case 0x0:
		// If Mod==0, the only time we could have displacement is if
		// R/M == 0x6
		if ( 0x6 == modrm.rm )	{
			CDisplacement disp;
			m_inst.GetDisplacement(disp, TRUE /* signed */);
			ASSERT( SIZE_16 == disp.GetSizeAttribute() );
			str = disp.GetCString();
		}
		else {
			str = EffectiveAddress16Names[modrm.rm];
		}
		break;
	case 0x1:
		{
		CDisplacement disp;
		m_inst.GetDisplacement(disp, TRUE /* signed */);
		ASSERT( SIZE_8 == disp.GetSizeAttribute() );
		str = EffectiveAddress16Names[modrm.rm];
#pragma _TODO("Sign extend")
		//disp.ExtendTo(SIZE_16);		
		str += disp.GetCString();
		}
		break;
	case 0x2:
		{
		CDisplacement disp;
		m_inst.GetDisplacement(disp, TRUE /* signed */);
		ASSERT( SIZE_16 == disp.GetSizeAttribute() );
		str = EffectiveAddress16Names[modrm.rm];
		str += disp.GetCString();
		}
		break;
	case 0x3:
		// With this encoding, we are going to have a general register
		// for this operand. (register direct addressing, not register indirect).
		// The MOD field of ModRM tells us which general register to use, but
		// it could be a DWORD, WORD, BYTE, or MMX register.  To find out
		// which type of register it is, we have to look at the TYPE_xxx
		// constant for this operand; that tells use what size the operand is,
		// and therefore which operand we use.
		
		// yes, I know the COperandType is just a temporary on the stack...
		switch( (OPERAND_TYPE) COperandType( OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() ) )	{
		case TYPE_BYTE:			// byte (always)
			str = CReg::Name8(modrm.rm);
			break;
		case TYPE_WORD:			// word (always)
			str = CReg::Name16(modrm.rm);
			break;
		case TYPE_DBLWORD:		// doubleword (always)
			str = CReg::Name32(modrm.rm);
			break;
		case TYPE_QUADWORD:		// quadword (always)
			// ALERT when we go 64 bits, something funny might happen.  for now,
			// we can assume that a quadword TYPE indicates MMX.
			ASSERT( OPERAND_ADDRESSING(m_opDef) == ADDR_P );
			str = CReg::NameMMX(modrm.rm);
			break;
		default:
			ASSERT(0);
			break;
		}
		break;

	default:
		ASSERT(0);

	}

	return str;
}
#endif // _AFX

#ifdef _AFX
CString
COperand::GetSIBAddressString() const
{
	CString str;
	SIB sib;

	ASSERT( m_inst.hasSIB() );
	sib = m_inst.GetSIB();

	BOOL bSpecialCaseDisp32 = ((0x5 == sib.base) && (0 == m_inst.GetModRM().mod));

	// First, we have the base.
	// The base register is in sib.base, though there is one special case.
	// If sib.base == 0101b (0x5), and modrm.mod is 0, there is a 32-bit
	// displacement but no base.

	if ( ! bSpecialCaseDisp32 )	{
		str = CReg::Name32(sib.base);
	}

	// Now, we have the scaled index.  The only catch here is that if sib.index
	// is 0100b == 0x4, there is no scaled index.
	if ( ! (0x4 == sib.index) )	{
		if ( !bSpecialCaseDisp32 )
			str += "+";

		str += CReg::Name32(sib.index);
		// now, tack on the scaling factor
		if		( 0x1 == sib.ss ) str += "*2";
		else if ( 0x2 == sib.ss ) str += "*4";
		else if ( 0x3 == sib.ss ) str += "*8";
	}

	// That's it.  If there is a dislacement from the modrm byte tacked on
	// as well, it should be appended by the calling code.
	// of course, there is that one special case to deal with

	// here's that special-case displacement we were talking about before.
	if ( bSpecialCaseDisp32 )	{
		CDisplacement disp;
		m_inst.GetDisplacement(disp, TRUE /* signed */);
		str += disp.GetCString();
	}

	return str;
}
#endif // _AFX

#ifdef _AFX
CString
COperand::GetModRMAddressName32() const
{
	CString str;
	MODRM modrm;

	if ( m_inst.hasModRM() )
		modrm = m_inst.GetModRM();

	switch( modrm.mod )	{
	case 0x0:
		if ( 0x4 == modrm.rm )	{
			// just use the SIB byte here...
			str = GetSIBAddressString();
		} else if ( 0x5 == modrm.rm )	{
			CDisplacement disp;
			m_inst.GetDisplacement(disp, FALSE /* unsigned */);
			ASSERT( SIZE_32 == disp.GetSizeAttribute() );
			str = disp.GetCString();
		}
		else {
			str = EffectiveAddress32Names[modrm.rm];
		}
		break;
	case 0x1:
		// 8-bit displacement with register indirect
		{
		CDisplacement disp;
		m_inst.GetDisplacement(disp, TRUE /* signed */);
		ASSERT( SIZE_8 == disp.GetSizeAttribute() );
#pragma _TODO("sign extend me")
		if ( 0x4 == modrm.rm )	{
			str = GetSIBAddressString();
		} else	{
			str = EffectiveAddress32Names[modrm.rm];
		}
		str += disp.GetCString();
		}
		break;
	case 0x2:
		{
		CDisplacement disp;
		m_inst.GetDisplacement(disp, TRUE /* signed */);
		ASSERT( SIZE_32 == disp.GetSizeAttribute() );
		if ( 0x4 == modrm.rm )	{
			str = GetSIBAddressString();
		} else {
			str = EffectiveAddress32Names[modrm.rm];
		}
		str += disp.GetCString();
		}
		break;
	case 0x3:
		{
		// With this encoding, we are going to have a general register
		// for this operand. (register direct addressing, not register indirect).
		// The MOD field of ModRM tells us which general register to use, but
		// it could be a DWORD, WORD, BYTE, or MMX register.  To find out
		// which type of register it is, we have to look at the TYPE_xxx
		// constant for this operand; that tells use what size the operand is,
		// and therefore which operand we use.
		
		// yes, I know the COperandType is just a temporary on the stack...
		COperandType type(OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() );
		switch( (OPERAND_TYPE) type )	{
		case TYPE_BYTE:			// byte (always)
			str = CReg::Name8(modrm.rm);
			break;
		case TYPE_WORD:			// word (always)
			str = CReg::Name16(modrm.rm);
			break;
		case TYPE_DBLWORD:		// doubleword (always)
			str = CReg::Name32(modrm.rm);
			break;
		case TYPE_QUADWORD:		// quadword (always)
			// ALERT when we go 64 bits, something funny might happen.  for now,
			// we can assume that a quadword TYPE indicates MMX.
			ASSERT( OPERAND_ADDRESSING(m_opDef) == ADDR_P );
			str = CReg::NameMMX(modrm.rm);
			break;
		default:
			ASSERT(0);
			break;
		}
		}
		break;

	default:
		ASSERT(0);

	}

	return str;
}
#endif // _AFX

BOOL 
COperand::isIndirect(void) const
{
	BOOL rc;	

	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return FALSE;
	}

	switch (OPERAND_ADDRESSING( m_opDef ))	{
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word 
	case ADDR_RELOFFSET:	// offset to be added to instruction counter
		rc = TRUE;
		break;
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		if ((m_inst.GetModRM().mod != 0x3 ))
			rc = TRUE;
		else
			rc = FALSE;
		break;

	case ADDR_DIRECT:		// address of operand encoded in instruction
	case ADDR_REG_CONTROL:	// modRM selects a control register
	case ADDR_REG_DEBUG:	// modRM selects a debug register
	case ADDR_FLAGS:		// flags register
	case ADDR_REG_GEN:		// modRM selects a general register
	case ADDR_REG_MMX:		// modRM selects an MMX register
	case ADDR_IMM:			// immediate data
	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
	case ADDR_REG_SEG:		// modRM selects a segment register
	case ADDR_REG_TEST:		// modRM selects a test register
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
		rc = FALSE;
		break;
	default:
		ASSERT(0);
		break;
	}

	return rc;

}

BOOL 
COperand::isGeneralRegister(void) const
{
	BOOL rc;	

	//
	// this operand could specify a general register if
	//	1) the register is hard-coded in the opcode
	//	2) the mod field of modR/M refers to general register
	//		[ADDR_MOD_REG_GEN, or (ADDR_REG_OR_MEM && mod == 011b)]
	//	3) the reg field of modR/M refers to a general register
	//		[ADDR_REG_GEN]
	//
	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return TRUE;
	}

	switch (OPERAND_ADDRESSING( m_opDef ))	{
	case ADDR_REG_GEN:		// modRM selects a general register [i.e. reg field]
	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
		rc = TRUE;
		break;
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
		if ((m_inst.GetModRM().mod == 0x3 ))	// if mod is 011b, general register is used
			rc = TRUE;
		else
			rc = FALSE;
		break;

	// the remaining cases should be optimized away
	case ADDR_DIRECT:		// address of operand encoded in instruction
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word 
	case ADDR_REG_CONTROL:	// modRM selects a control register
	case ADDR_REG_DEBUG:	// modRM selects a debug register
	case ADDR_FLAGS:		// flags register
	case ADDR_IMM:			// immediate data
	case ADDR_RELOFFSET:	// offset to be added to instruction counter
	case ADDR_REG_SEG:		// modRM selects a segment register
	case ADDR_REG_TEST:		// modRM selects a test register
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
	default:
		rc = FALSE;
		break;
	} // switch

	return rc;

}


#ifdef _AFX
CString
COperand::GetCString(void) const
{
	CString op;
	if ( isIndirect() )	{
		op = GetTypeName();
		op += " ptr";
		op += " [";
	}
	op += GetAddressString();
	if ( isIndirect() )
		op += "]";
	return op;

}
#endif // _AFX

ADDRESSING_METHOD
COperand::GetAddressingMethod(void) const
{
	return OPERAND_ADDRESSING(m_opDef);
}

OPERAND_TYPE
COperand::GetOperandType(void) const
{
	COperandType type( OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() );
	return (OPERAND_TYPE) type;
}

COperandType&
COperand::GetOperandType(COperandType& ot) const
{
	COperandType type( OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() );
	ot = type;	// overloaded =
	return ot;
}

BOOL
COperand::isStackPointer(void) const
{
	BOOL rc;	

	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return FALSE;
	}

	// BUGBUG: whassup???
	switch (OPERAND_ADDRESSING( m_opDef ))	{
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word 
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		if ((m_inst.GetModRM().mod != 0x3 ))
			rc = TRUE;
		else
			rc = FALSE;
		break;

	case ADDR_DIRECT:		// address of operand encoded in instruction
	case ADDR_REG_CONTROL:	// modRM selects a control register
	case ADDR_REG_DEBUG:	// modRM selects a debug register
	case ADDR_FLAGS:		// flags register
	case ADDR_REG_GEN:		// modRM selects a general register
	case ADDR_REG_MMX:		// modRM selects an MMX register
	case ADDR_IMM:			// immediate data
	case ADDR_RELOFFSET:	// offset to be added to instruction counter
	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
	case ADDR_REG_SEG:		// modRM selects a segment register
	case ADDR_REG_TEST:		// modRM selects a test register
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
		rc = FALSE;
		break;
	default:
		ASSERT(0);
		break;
	}

	return rc;

}

CReg&
COperand::GetRegister(CReg& reg) const
{
	if (!isRegister())
		throw XDisException("Operand is not register");

	// if this register is encoded in the opcode, it can be either
	//	1) a segment register
	//	2) a general byte register
	//	3) a general word or dword register
	// No other register type (i.e., CONTROL, DEBUG ) are encoded in opcodes.
	//
	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		// BYTE
		if (OPERAND_IS_BYTE_REG(m_opDef))
			reg.SetType(REGTYPE_GEN_BYTE);
		// WORD
		else if (OPERAND_IS_WORD_REG(m_opDef))
			reg.SetType(REGTYPE_GEN_WORD);
		// SEG
		else if (OPERAND_IS_SEG_REG(m_opDef))
			reg.SetType(REGTYPE_SEG);
		// DEFAULT
		else if (OPERAND_IS_DEFAULT_REG(m_opDef))	{
			REGTYPE rt = (m_inst.GetOperandSizeAttribute() == SIZE_32) ? REGTYPE_GEN_DWORD : REGTYPE_GEN_WORD;
			reg.SetType( rt );
		}
		else	{
			ASSERT(0);
		}

		reg.SetNum( OPERAND_ENCODED_REG_IDX(m_opDef) );
		return reg;
	} // OPERAND_IS_ENCODED_REG

	// here, we have determined that the register is not encoded in the instruction.
	//
	// In general, register numbers are specified by the REG field of the modRM byte,
	// with the REGTYPE being determined by the addressing type of the operand, which
	// has the form:	
	//		ADDR_REG_xxx,
	// where xxx is GEN, SEG, TEST, DEBUG, or CONTROL.  The exact REGTYPE for
	// a general register must be inferred from size information in OPERAND_TYPE().
	// Note that MMX registers are specified by the ADDR_REG_GEN addressing type.
	// All other registers have an instrinsic size, as follows:
	//
	// SEG		SIZE_16
	// MMX		SIZE_64
	// TEST		?
	// DEBUG	?
	// CONTROL	?
	//
	// A general register may also be specified in the R/M field of the modR/M byte.
	// This is the case with the ADDR_MOD_REG_GEN and ADDR_REG_OR_MEM addressing
	// types when the MOD field is 011b.
	//
	ASSERT( m_inst.hasModRM() );
	MODRM modrm = m_inst.GetModRM();	// MUST have modRM if we are register (and not hardcoded)
	SIZE_ATTRIBUTE size = GetSize();
	switch (OPERAND_ADDRESSING( m_opDef ))	{
	
	// do the easy cases first
	case ADDR_REG_SEG:		// modRM selects a segment register
		reg.SetType( REGTYPE_SEG );
		reg.SetNum( modrm.reg );
		break;
	case ADDR_REG_TEST:		// modRM selects a test register
		reg.SetType( REGTYPE_TEST );
		reg.SetNum( modrm.reg );
		break;
	case ADDR_REG_CONTROL:	// modRM selects a control register
		reg.SetType( REGTYPE_CONTROL );
		reg.SetNum( modrm.reg );
		break;
	case ADDR_REG_DEBUG:	// modRM selects a debug register
		reg.SetType( REGTYPE_DEBUG );
		reg.SetNum( modrm.reg );
		break;

	// here, the register is either general or MMX (MMX instructions are encoded
	// simply as general registers with size of SIZE_64)

	case ADDR_REG_GEN:		// modRM selects a general register [i.e. reg field]
	case ADDR_REG_MMX:		// modRM selects an MMX register
		reg.SetNum( modrm.reg );
		reg.SetTypeGeneral(size);
		break;

	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		ASSERT( modrm.mod == 0x3 );
		if (size == SIZE_48)
			throw XDisException("Invalid general register");
		reg.SetNum( modrm.rm );
		reg.SetTypeGeneral(size);
		break;

	default:
		ASSERT(0);
		break;
	} // switch

	return reg;
}

//CImmediate&
//COperand::GetImmediate(CImmediate& imm)
//{
//	if (!isImmediate())
//		throw XDisException("Operand is not immediate");
//	
//	return m_inst.GetImmediate(imm);
//}

CEffectiveAddress&
COperand::GetEffectiveAddress(CEffectiveAddress& ea) const
{
	// ALERT!
	if (!isPointer())
		throw XDisException("Operand is not memory");

	ea.Build(*this);

	return ea;
}

SIZE_ATTRIBUTE 
COperand::GetSize(void) const
{
	COperandType type( OT_CODE(m_opDef), m_inst.GetOperandSizeAttribute() );
	return type.GetSize();
}

BOOL
COperand::isPointer(void) const
{
	BOOL rc;

	switch (OPERAND_ADDRESSING( m_opDef ))	{
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word 
		rc = TRUE;
		break;
	
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either a gen reg or mem addr
		if ((m_inst.GetModRM().mod != 0x3 ))
			rc = TRUE;
		else
			rc = FALSE;
		break;

	case ADDR_RELOFFSET:	// offset to be added to instruction counter
	case ADDR_DIRECT:		// address of operand encoded in instruction
		rc = FALSE;
		break;
	default:
		rc = FALSE;
		break;
	}

	return rc;
}

BOOL
COperand::isRegister(void) const
{
	BOOL rc;	

	if ( OPERAND_IS_ENCODED_REG(m_opDef) )	{
		return TRUE;
	}

	switch (OPERAND_ADDRESSING( m_opDef ))	{
	case ADDR_REG_CONTROL:	// modRM selects a control register
	case ADDR_REG_DEBUG:	// modRM selects a debug register
	case ADDR_REG_GEN:		// modRM selects a general register
	case ADDR_REG_MMX:		// modRM selects an MMX register
	case ADDR_REG_SEG:		// modRM selects a segment register
	case ADDR_REG_TEST:		// modRM selects a test register
		rc = TRUE;
		break;
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		if ((m_inst.GetModRM().mod == 0x3 ))
			rc = TRUE;
		else
			rc = FALSE;
		break;
	default:
		rc = FALSE;
		break;
	}

	return rc;

}

BOOL
COperand::isImmediate(void) const
{
	return ADDR_IMM == OPERAND_ADDRESSING(m_opDef);
}

OPERAND *
COperand::GetOPERAND(OPERAND *pOp) const
{
	ASSERT( pOp );
	
	if ( isRegister() )
		pOp->cls = OPERAND_CLASS_REG;
//	else if ( isMemory() )
	else if ( isPointer() )
		pOp->cls = OPERAND_CLASS_MEM;
	else if ( isImmediate() )
		pOp->cls = OPERAND_CLASS_IMM;
	else if ( isDirect() )
		pOp->cls = OPERAND_CLASS_DIRECT;
	else if ( ADDR_RELOFFSET == OPERAND_ADDRESSING(m_opDef) )
		// ALERT this should have IP added
		pOp->cls = OPERAND_CLASS_IMM;
	else	{
		// BUGBUG: Find out what's up here.
//		ASSERT(0);	// ALERT: PUSHF caused this...
		// this is fucked
		pOp->cls = OPERAND_CLASS_NONE;
	}


	switch (pOp->cls)	{
	case OPERAND_CLASS_REG:
		{
			CReg reg;
			GetRegister(reg);
			pOp->reg.type =  reg.GetType();
			pOp->reg.num = (REG_NUM) reg.GetNum();
		}
		break;
	case OPERAND_CLASS_MEM:
		{
			//
			// Fill in the MEMPTR structure of the operand union.
			//
			CEffectiveAddress addr;
			GetEffectiveAddress(addr);
			pOp->mem.mask = 0;
			pOp->mem.address_size = addr.GetSizeAttribute();
			pOp->mem.operand_size = GetSize();
			CReg reg;

			pOp->mem.seg  =	(REG) addr.GetSegment(reg);

			if ( addr.hasSegmentOverride() )	{
				pOp->mem.seg  =	(REG) addr.GetSegment(reg);
				pOp->mem.mask |= MEMPTR_USE_SEG;
			}
			if ( addr.hasBase() )	{
				pOp->mem.base = (REG) addr.GetBase(reg);
				pOp->mem.mask |= MEMPTR_USE_BASE;
			}
			if ( addr.hasIndex() )	{
				pOp->mem.idx  =	(REG) addr.GetIndex(reg);
				pOp->mem.mask |= MEMPTR_USE_IDX;
			}
			if ( addr.hasScalingFactor() )	{
				pOp->mem.scale=	addr.GetScalingFactor();
				pOp->mem.mask |= MEMPTR_USE_SCALE;
			}
			if ( addr.hasDisplacement() )	{
				CDisplacement disp;
				addr.GetDisplacement(disp);
				switch( disp.GetSizeAttribute() ) {
				case SIZE_8:
					pOp->mem.disp8 = disp.value8();
					pOp->mem.mask |= MEMPTR_USE_DISP8;
					break;
				case SIZE_16:
					pOp->mem.disp16 = disp.value16();
					pOp->mem.mask |= MEMPTR_USE_DISP16;
					break;
				case SIZE_32:
					pOp->mem.disp32 = disp.value32();
					pOp->mem.mask |= MEMPTR_USE_DISP32;
					break;
				default:
					ASSERT(0);
				}

			}

		}
		break;
	case OPERAND_CLASS_IMM:
		{
			ASSERT( m_inst.hasImmediate() );
			//
			// if this is going to be a pointer, the size of the
			// pointer should be whatever is the address size attribute
			//
			CImmediate imm;
			if ( ADDR_RELOFFSET == OPERAND_ADDRESSING(m_opDef) )	{
				pOp->imm.size = m_inst.GetAddressSizeAttribute();
				m_inst.GetImmediateAsAddressOffset(imm, TRUE /* signed */);
			} else	{
				pOp->imm.size = m_inst.GetImmediateSizeAttribute();
				m_inst.GetImmediate(imm, TRUE /* signed */);
			}

			if ( ADDR_RELOFFSET == OPERAND_ADDRESSING(m_opDef) )	{
				imm += m_inst.GetVirtualAddress();
				imm += m_inst.GetInstructionSize();
			}
			switch ( pOp->imm.size )	{
			case SIZE_8:
				pOp->imm.imm8 = imm.value8();
				break;
			case SIZE_16:
				pOp->imm.imm16 = imm.value16();
				break;
			case SIZE_32:
				pOp->imm.imm32 = imm.value32();
				break;
			default:
				ASSERT(0);
			};

		}
		break;
	case OPERAND_CLASS_DIRECT:
		{
			if ( m_inst.GetAddressSizeAttribute() == SIZE_16 )	{
				pOp->direct.size = SIZE_32;	// 16:16 ptr
				pOp->direct.direct32 = m_inst.GetDirect32();
			} else {
				ASSERT( m_inst.GetAddressSizeAttribute() == SIZE_32 );
				pOp->direct.size = SIZE_48;	// 16:32 ptr
				pOp->direct.direct48 = m_inst.GetDirect48();
			}
		}
		break;
	default:
		break;
	}

	return pOp;
}

BOOL COperand::isDirect(void) const
{
	return ( OPERAND_ADDRESSING(m_opDef) == ADDR_DIRECT );
}
