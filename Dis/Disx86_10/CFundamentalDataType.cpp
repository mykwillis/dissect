#include "project.h"
#include "CFundamentalDataType.h"

#ifndef ASSERT
#define ASSERT(x)
#endif 

CFundamentalDataType::CFundamentalDataType()
{
	SetValue((DWORD)0, SIZE_LAST, FALSE);
}
CFundamentalDataType::CFundamentalDataType(DWORD dwImm, SIZE_ATTRIBUTE size, BOOL bSigned)
{
	SetValue(dwImm, size, bSigned);
}
CFundamentalDataType::CFundamentalDataType(DWORD dwImm, BOOL bSigned)
{
	SetValue(dwImm, SIZE_32, bSigned);
}
CFundamentalDataType::CFundamentalDataType(WORD wImm, BOOL bSigned)
{
	SetValue( (DWORD) wImm, SIZE_16, bSigned);
}
CFundamentalDataType::CFundamentalDataType(BYTE bImm, BOOL bSigned)
{
	SetValue( (DWORD) bImm, SIZE_8, bSigned);
}

CHAR
CFundamentalDataType::GetSign(void) const
{
	return GetSignBit() == 1 ? '-' : '+';
}

BOOL
CFundamentalDataType::GetSignBit(void) const
{
	// we rely on the fact that every signed value has already
	// been sign-extended to a DWORD size
	return m_dwImm & 0x80000000 ? 1 : 0;
}

BOOL
CFundamentalDataType::isSigned(void) const
{
	return m_bSigned;
}

BOOL
CFundamentalDataType::isNegative(void) const
{
	if (!isSigned()) return FALSE;
	return GetSignBit() == 1;
}

BOOL
CFundamentalDataType::isPositive(void) const
{
	if (!isSigned()) return TRUE;
	return GetSignBit() == 0;
}

DWORD
CFundamentalDataType::GetMask(void) const
{
	switch(m_size)	{
	case SIZE_8:
		return 0xff;
	case SIZE_16:
		return 0xffff;
	case SIZE_32:
		return 0xffffffff;
	default:
		ASSERT(0);
		return 0;
		break;
	}
}
DWORD
CFundamentalDataType::GetMagnitude(void) const
{
	DWORD dwMag;
	if (isNegative())	{
		dwMag = ~m_dwImm + 1;	// two's complement; negate and add one
	} else {
		dwMag = m_dwImm;
	}

	return dwMag;
}

#ifdef _AFX
CString
CFundamentalDataType::GetCString(void) const
{
	CString str;
	char tmp[9];

	if (isSigned())
		str += GetSign();

	// get the magnitude into tmp
	itoa( GetMagnitude(), (char *)tmp, 0x10 );

	// tack on enough zeros
	for (int i=strlen(tmp); i < (int)m_size / 4 ; i++)
		str += "0";

#ifdef DUMPBIN_EMULATION
	char *c = tmp;
	strupr(tmp);
	BOOL bNoH = FALSE;
	while( *c )	{
		if ( *c >= 'A' && *c <= 'F' )
			bNoH = TRUE;
		c++;
	}
	if (!bNoH)
#endif
		strcat((char *)tmp, "h");

	str += tmp;

	return str;
}
#endif // _AFX

//
// default promotion to DWORD from a smaller type will be handled
// correctly by this routine.
// I.e., 
//	SetValue((DWORD) SignedByteValue, SIZE_8, TRUE);
// will work fine.
//
CFundamentalDataType&	
CFundamentalDataType::SetValue(DWORD dwImm, SIZE_ATTRIBUTE size, BOOL bSigned)
{
	if (bSigned)	{
		switch(size)	{
		case SIZE_8:
			m_dwImm = (DWORD)(SDWORD)(SBYTE)dwImm;
			break;
		case SIZE_16:
			m_dwImm = (DWORD)(SDWORD)(SWORD)dwImm;
			break;
		case SIZE_32:
			m_dwImm = dwImm;
			break;
		default:
			ASSERT(0);
			m_dwImm = dwImm;
			break;
		} // switch
	} else {
		// unsigned
		m_dwImm = dwImm;
	}
	m_size = size;
	m_bSigned = bSigned;
	return *this;
}

CFundamentalDataType&	
CFundamentalDataType::SetValue(BYTE b, BOOL bSigned)
{
	return SetValue(b, SIZE_8, bSigned);
}
CFundamentalDataType&	
CFundamentalDataType::SetValue(WORD wImm, BOOL bSigned)
{
	return SetValue(wImm, SIZE_16, bSigned);
}
CFundamentalDataType&	
CFundamentalDataType::SetValue(DWORD dwImm, BOOL bSigned)
{
	return SetValue(dwImm, SIZE_32, bSigned);
}

CFundamentalDataType&	
CFundamentalDataType::SetValue(BYTE imm[4], SIZE_ATTRIBUTE size, BOOL bSigned)
{
	switch(size)	{
	case SIZE_8:
		return SetValue( (DWORD) (*(BYTE *)imm), size, bSigned );
	case SIZE_16:
		return SetValue( (DWORD) (*(WORD *)imm), size, bSigned );
	case SIZE_32:
		return SetValue( (DWORD) (*(DWORD *)imm), size, bSigned );
	default:
		ASSERT(0);
	}
	return *this;
}