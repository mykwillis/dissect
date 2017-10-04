#ifndef _CEADDR_H
#define _CEADDR_H

#include "CFundamentalDataType.h"
#include "CReg.h"

#define EA_BASE		0x0001
#define EA_INDEX	0x0002
#define EA_SCALE	0x0004
#define EA_DISP		0x0008
#define EA_SEG		0x0010
#define EA_SEG_OVERRIDE		0x0020	// segment is override

class CContext;
class COperand;
class CReg;

class CEffectiveAddress
{
private:
	BOOL	BuildAddrModRM(const COperand& op) ;
	BOOL		BuildAddrModRM16(const COperand& op) ;
	BOOL		BuildAddrModRM32(const COperand& op) ;
	BOOL	BuildAddrDirect(const COperand& op) ;
	BOOL	BuildAddrOffset(const COperand& op) ;
	BOOL	BuildAddrRelOffset(const COperand& op) ;
	BOOL	BuildAddrDsSi(const COperand& op) ;
	BOOL	BuildAddrEsDi(const COperand& op) ;

	// all of these register indexes can be collapsed into bitfields to save space...
	int m_rNumSeg;		// segment register used (may be implicit or explicit)
	int m_rNumBase;		// base register
	int m_rNumIndex;	// index register (cannot be esp)
	int m_scale;		// scale factor (0,1,2,3)
	CDisplacement	m_disp;	// displacement (0-,8-,16-, or 32-bit)

	// set of bits determining which of base/index/scale/displacement are used
	DWORD	m_dwMask;

	// determines whether 16 or 32 bit addressing is being used
	SIZE_ATTRIBUTE  m_addrSize;

	CContext *m_pContext;

public:
	CEffectiveAddress();
	CEffectiveAddress(COperand &op, CContext *pContext);
	BOOL Build(const COperand& op);
	void	SetContext(CContext *pContext)	// NULL OK
		{ m_pContext = pContext; }
	void	Clear(void);

	BOOL	hasBase(void) const
		{ return BITTEST(m_dwMask, EA_BASE); }
	BOOL	hasIndex(void) const
		{ return BITTEST(m_dwMask, EA_INDEX); }
	BOOL	hasScalingFactor(void) const
		{ return BITTEST(m_dwMask, EA_SCALE); }
	BOOL	hasDisplacement(void) const
		{ return BITTEST(m_dwMask, EA_DISP); }
	BOOL	hasSegment(void) const
		{ return BITTEST(m_dwMask, EA_SEG); }
	BOOL	hasSegmentOverride(void) const
		{ return BITTEST(m_dwMask, EA_SEG_OVERRIDE); }

	CReg&	GetBase(CReg& reg) const
		{ hasBase() ? reg.SetNumGeneral(m_rNumBase, m_addrSize) : reg.SetType( REGTYPE_NONE ); return reg; }
	CReg&	GetIndex(CReg& reg) const
		{ hasIndex() ? reg.SetNumGeneral(m_rNumIndex, m_addrSize) : reg.SetType( REGTYPE_NONE ); return reg; }
	CReg&	GetSegment(CReg& reg) const
		{ hasSegment() ? reg.SetNum(m_rNumSeg), reg.SetType( REGTYPE_SEG ) : reg.SetType( REGTYPE_NONE ); return reg;}
	int		GetScalingFactor(void) const
		{ return hasScalingFactor() ? m_scale : 1; }
	CDisplacement&	GetDisplacement(CDisplacement& disp) const
		{ hasDisplacement() ? disp.SetValue(m_disp.value32(), m_disp.GetSizeAttribute(), m_disp.isSigned()) : disp.SetValue((DWORD)0, SIZE_LAST, FALSE); return disp;	}

	DWORD	GetDisplacement(void) const
		{ return hasDisplacement() ? DWORD(m_disp) : 0; }

	SIZE_ATTRIBUTE	GetSizeAttribute(void) const
		{ return m_addrSize; }

};


#endif // _CEADDR_H