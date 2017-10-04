#ifndef _CFundamentalDataType_H
#define _CFundamentalDataType_H

typedef signed char			SBYTE;	// signed byte
typedef signed short int	SWORD;	// signed word
typedef signed long int		SDWORD;	// signed dword
//
// Regardless of the actual type of the value being represented,
// CFundamentalDataType always maintains the value in a 32-bit DWORD.
// If the value is signed, it is sign-extended to 32 bits, otherwise
// it is 0-extended to 32 bits.  Truncation to sizes of 8- and 16-bits
// can then be safely done without regard to the sign, and the sign
// of signed values can be determined simply by testing the high
// bit of the DWORD.
//
class CFundamentalDataType
{
private:
	DWORD			m_dwImm;	// extended value
	SIZE_ATTRIBUTE	m_size;		// size of the represented value
	BOOL			m_bSigned;	// TRUE if value is to be treated as signed

	DWORD	GetMask(void) const;
public:
	CFundamentalDataType();
	CFundamentalDataType(DWORD dwImm, SIZE_ATTRIBUTE size, BOOL bSigned);
	CFundamentalDataType(DWORD dwImm, BOOL bSigned);
	CFundamentalDataType(WORD wImm,	BOOL bSigned);
	CFundamentalDataType(BYTE bImm,	BOOL bSigned);

	BOOL	isSigned(void) const;
	BOOL	isNegative(void) const;
	BOOL	isPositive(void) const;

	CHAR	GetSign(void) const;	// returns '+' or '-'
	BOOL	GetSignBit(void) const;	// returns 1 or 0
	DWORD	GetMagnitude(void) const;

	SIZE_ATTRIBUTE	GetSizeAttribute(void) const
		{ return m_size; }

	CFundamentalDataType&	SetValue(DWORD dwImm, SIZE_ATTRIBUTE size, BOOL bSigned);
	CFundamentalDataType&	SetValue(BYTE b, BOOL bSigned);
	CFundamentalDataType&	SetValue(WORD wImm, BOOL bSigned);
	CFundamentalDataType&	SetValue(DWORD dwImm, BOOL bSigned);
	CFundamentalDataType&	SetValue(BYTE imm[4], SIZE_ATTRIBUTE size, BOOL bSigned);

	//BUGBUG: this probably isn't sign safe?
	CFundamentalDataType&	operator +=(DWORD dwVal)
		{ m_dwImm += dwVal; return *this; }

	operator DWORD() const
		{ return m_dwImm; }

	//
	// Unsigned values
	//
	BYTE	value8(void) const
		{ return (BYTE) m_dwImm; }
	WORD	value16(void) const
		{ return (WORD) m_dwImm; }
	DWORD	value32(void) const
		{ return (DWORD) m_dwImm; }

	//
	// Signed values
	//
	SBYTE	svalue8(void) const
		{ return (SBYTE) m_dwImm; }
	SWORD	svalue16(void) const
		{ return (SWORD) m_dwImm; }
	SDWORD	svalue32(void) const
		{ return (SBYTE) m_dwImm; }

#ifdef _AFX
	CString	GetCString(void) const;
#endif // _AFX
};

class CImmediate : public CFundamentalDataType
{
};

class CDisplacement : public CFundamentalDataType
{
};

#endif // _CFundamentalDataType_H