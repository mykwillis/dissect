#include "project.h"
#include "CEffectiveAddress.h"
#include "CInstruction.h"
#include "COperand.h"
#include "XDisException.h"
#include "CFundamentalDataType.h"


CEffectiveAddress::CEffectiveAddress()
{
	Clear();
}

CEffectiveAddress::CEffectiveAddress(COperand &op, CContext *pContext)
{
	SetContext(pContext);
	Build(op);
}

BOOL
CEffectiveAddress::Build(const COperand& op)
{
	BOOL rc;
	CInstruction &inst = op.GetInstruction();

	// get the address size attribute for the instruction
	m_addrSize = inst.GetAddressSizeAttribute();

	// Get the addressing method information
	// These Buildxxx() routines are responsible for setting up any applicable
	// base, index, scaling factor, and displacement.
	// The segment register is determined later in this function.
	switch ( op.GetAddressingMethod() )	{
	case ADDR_DSSI:			// memory addressed by DS:SI pair; e.g., MOVS, CMPS, etc.
		rc = BuildAddrDsSi(op);
		break;
	case ADDR_ESDI:			// memory addressed by ES:DI pair; e.g., MOVS, CMPS, etc
		rc = BuildAddrEsDi(op);
		break;
	case ADDR_OFFSET:		// no modRM; offset of operand is word or dbl word (immediate) 
		rc = BuildAddrOffset(op);
		break;
	case ADDR_DIRECT:		// address of operand encoded in instruction
		rc = BuildAddrDirect(op);
		break;
	case ADDR_RELOFFSET:	// 
		rc = BuildAddrRelOffset(op);
		break;
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
		if ((inst.GetModRM().mod == 0x3 ))
			throw XDisException("ADDR_MEM instruction cannot have register in modrm");

		rc = BuildAddrModRM(op);
		break;
	default:
		ASSERT(0);
	}

	// now, calculate what segment register to use
	if ( inst.hasSegmentOverridePrefix() )	{
		switch ( inst.GetSegmentOverridePrefix() )	{
		case 0x2E:	// CS
			m_rNumSeg = REG_IDX( REG_CS );
			break;
		case 0x36:	// SS
			m_rNumSeg = REG_IDX( REG_SS );
			break;
		case 0x3E:	// DS
			m_rNumSeg = REG_IDX( REG_DS );
			break;
		case 0x26:	// ES
			m_rNumSeg = REG_IDX( REG_ES );
			break;
		case 0x64:	// FS
			m_rNumSeg = REG_IDX( REG_FS );
			break;
		case 0x65:	// GS
			m_rNumSeg = REG_IDX( REG_GS );
			break;
		default:
			ASSERT(0);
		} // switch
		
		m_dwMask |= EA_SEG_OVERRIDE;	// always set
	} else {
		// the default segment register is DS
		// SS is used if EBP or ESP is used in the address calculation
		// ES is used if implied addressing method ADDR_ESDI is used.
		if ( 
			(hasBase() && m_rNumBase == REG_IDX( REG_eBP ))	||
			(hasBase() && m_rNumBase == REG_IDX( REG_eSP ))	||
			(hasIndex() && m_rNumIndex == REG_IDX( REG_eBP ))	||
			(hasIndex() && m_rNumIndex == REG_IDX( REG_eSP ))
			)
			m_rNumSeg = REG_IDX( REG_SS );
		else if ( ADDR_ESDI == op.GetAddressingMethod() )
			m_rNumSeg = REG_IDX( REG_ES );
		else
			m_rNumSeg = REG_IDX( REG_DS );

	}

	m_dwMask |= EA_SEG;	// always set

	return rc;

}

void
CEffectiveAddress::Clear(void)
{
	m_rNumSeg = 0;
	m_rNumBase = 0;
	m_rNumIndex = 0;
	m_scale = 0;
	m_dwMask = 0;
	m_pContext = NULL;
}

BOOL 
CEffectiveAddress::BuildAddrModRM(const COperand& op)
{
	if (SIZE_16 == m_addrSize)
		return BuildAddrModRM16(op);
	else if (SIZE_32 == m_addrSize)
		return BuildAddrModRM32(op);
	else
		ASSERT(0);

	return FALSE;
}

BOOL 
CEffectiveAddress::BuildAddrModRM16(const COperand& op)
{
	MODRM modrm = op.GetInstruction().GetModRM();
	ASSERT( modrm.mod != 0x3 );

	// one special case:
	if ( modrm.mod == 0 && modrm.rm == 0x6 )	{
		// operand is specified as 16-bit displacement
		op.GetInstruction().GetDisplacement(m_disp, TRUE /* signed */);
		ASSERT( SIZE_16 == m_disp.GetSizeAttribute() );
		m_dwMask |= EA_DISP;
		return TRUE;
	}

	// the rest are predictable
	// read the base and index(if present) registers from the rm field
	switch ( modrm.rm )	{
	case 0:
		m_rNumBase = REG_IDX( REG_BX );
		m_rNumIndex= REG_IDX( REG_SI );
		m_dwMask |= EA_BASE | EA_INDEX;
		break;
	case 1:
		m_rNumBase = REG_IDX( REG_BX );
		m_rNumIndex= REG_IDX( REG_DI );
		m_dwMask |= EA_BASE | EA_INDEX;
		break;
	case 2:
		m_rNumBase = REG_IDX( REG_BP );
		m_rNumIndex= REG_IDX( REG_SI );
		m_dwMask |= EA_BASE | EA_INDEX;
		break;
	case 3:
		m_rNumBase = REG_IDX( REG_BP );
		m_rNumIndex= REG_IDX( REG_DI );
		m_dwMask |= EA_BASE | EA_INDEX;
		break;
	case 4:
		m_rNumIndex= REG_IDX( REG_SI );
		m_dwMask |= EA_INDEX;
		break;
	case 5:
		m_rNumIndex= REG_IDX( REG_DI );
		m_dwMask |= EA_INDEX;
		break;
	case 6:
		m_rNumBase = REG_IDX( REG_BP );
		m_dwMask |= EA_BASE;
		break;
	case 7:
		m_rNumBase = REG_IDX( REG_BX );
		m_dwMask |= EA_BASE;
		break;
	default:
		ASSERT(0);
	}

	// now choose the correct displacement size
	// NOTE that really this should be unnecessary; that is, the CDisplacement
	// object should automatically have the correct size.  We want to ASSERT
	// that, however.
	switch( modrm.mod )	{
	case 0:	// no displacement
		break;
	case 1:	// 8-bit displacement
		op.GetInstruction().GetDisplacement(m_disp, TRUE /* signed */);
		ASSERT( SIZE_8 == m_disp.GetSizeAttribute() );
		m_dwMask |= EA_DISP;
		break;
	case 2:	// 16-bit displacement
		op.GetInstruction().GetDisplacement(m_disp, TRUE /* signed */);
		ASSERT( SIZE_16 == m_disp.GetSizeAttribute() );
		m_dwMask |= EA_DISP;
		break;
	default: // case 3: is register direct addressing.
		ASSERT(0);
	}

	return TRUE;
}

BOOL 
CEffectiveAddress::BuildAddrModRM32(const COperand& op)
{
	MODRM modrm = op.GetInstruction().GetModRM();
	ASSERT( modrm.mod != 0x3 );	// don't handle the case of modRM specifying a register

	//
	// if modrm.rm is 0100b (0x4), there is a SIB byte following that encodes:
	//	base	-	SIB.base	*[if MOD is 0 and BASE is 0x5, no base register is used]
	//	index	-	SIB.index	*[if INDEX is 0x4, no index register (nor scaling factor) is used]
	//  scale	-	1 << SIB.ss
	//
	// Otherwise, the only register used is a base, which is encoded:
	//	base	-	MODRM.rm	*[if MOD is 0 and RM is 0x5, no base register is used]
	//
	// In all cases, the size of the displacement used (in bytes) is specified as:
	//  displacement size	-	MODRM.mod	*[if MOD is 0 and RM is 0x5, displacement is SIZE_32]
	//

	//
	// Find base, scale, and index
	//
	if ( 0x4 == modrm.rm )	{
		//
		// SIB used to specifiy base, scale, and index
		//
		ASSERT( op.GetInstruction().hasSIB() );
		SIB sib = op.GetInstruction().GetSIB();
		
		// read base from SIB
		if ( modrm.mod == 0 && sib.base == 0x5 )	{
			// no base
		} else {
			m_rNumBase = sib.base;
			m_dwMask |= EA_BASE;
		}

		// read index from SIB
		if ( sib.index == 0x4 )	{
			// no index
		} else {
			m_rNumIndex = sib.index;
			m_dwMask |= EA_INDEX;
		
			// read scaling factor from SIB
			m_scale = 1 << sib.ss;
			m_dwMask |= EA_SCALE;
		}


	} else {
		//
		// MODRM.rm used to select base; no index or scaling factor
		//
		if ( modrm.mod == 0x0 && modrm.rm == 0x5 )	{
			// special case: no base register at all (just displacement)
		} else {
			m_rNumBase = modrm.rm;
			m_dwMask |= EA_BASE;
		}
	}

	//
	// Find displacement size (actually, just do a sanity check since we already
	// know how big the displacement is from reading in the instruction)
	// if modrm.mod is 0, there is no displacement (unless modrm.rm is 0x5).
	//
	if ( modrm.mod != 0 || modrm.rm == 0x5 )	{
		ASSERT( op.GetInstruction().hasDisplacement() );
		op.GetInstruction().GetDisplacement(m_disp, TRUE /* signed */);
		m_dwMask |= EA_DISP;
	}

	// sanity checks
	if	(	( modrm.mod == 0x0 && modrm.rm == 0x5 )	||
			( modrm.mod == 0x2 ))	{
		ASSERT( SIZE_32 == m_disp.GetSizeAttribute() );
	} else if ( modrm.mod == 0x1 )	{
		ASSERT( SIZE_8 == m_disp.GetSizeAttribute() );
	}

	return TRUE;
}

BOOL
CEffectiveAddress::BuildAddrEsDi(const COperand& )
{
	// ES segment register is set in Build(); we just have to set up DI as the index
	m_rNumIndex = REG_IDX( REG_DI );
	m_dwMask |= EA_INDEX;
	return TRUE;
}

BOOL
CEffectiveAddress::BuildAddrDsSi(const COperand& )
{
	// DS segment register is set in Build(); we just have to set up SI as the index
	m_rNumIndex = REG_IDX( REG_SI );
	m_dwMask |= EA_INDEX;
	return TRUE;
}

BOOL
CEffectiveAddress::BuildAddrOffset(const COperand& op)
{
	//
	// If this address is specified by simply an offset, that offset
	// is specified in the immediate field of the instruction (NOT the
	// displacement field).  The immediate value is not signed, since
	// it just specifies an offset from the beginning of the segment
	//
	CImmediate imm;
	op.GetInstruction().GetImmediate(imm, FALSE /* unsigned */);
	m_disp.SetValue( imm.value32(), imm.GetSizeAttribute(), FALSE /* unsigned */ );
	m_dwMask |= EA_DISP;

	return TRUE;
}

BOOL
CEffectiveAddress::BuildAddrRelOffset(const COperand& op)
{
	//
	// If this address is specified by simply an offset, that offset
	// is specified in the immediate field of the instruction (NOT the
	// displacement field).  The immediate value is signed, since
	// it specifies an offset from [e]ip.
	//
	CImmediate imm;
	op.GetInstruction().GetImmediate(imm, TRUE /* signed */);
	m_disp.SetValue( imm.value32() + op.GetInstruction().GetVirtualAddress(), imm.GetSizeAttribute(), FALSE /* unsigned */ );
	m_dwMask |= EA_DISP;

	return TRUE;
}

BOOL
CEffectiveAddress::BuildAddrDirect(const COperand& )
{
	ASSERT(0);
	return FALSE;
}