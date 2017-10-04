#ifndef _COPERAND_TYPE
#define _COPERAND_TYPE

typedef enum	{
#define DO(_type, _size, _name)	\
	TYPE_##_type,
#include "OperandType.dat"
#undef DO
	TYPE_LAST
} OPERAND_TYPE;

//
// The OPERAND_TYPE_CODE enum lists all types such that
// TC_a == TC_BOUND, TC_b == TC_BYTE, etc.
//
typedef enum {
#define DO(_code, _name, _size16, _size32, _desc) TC_##_code, TC_##_name = TC_##_code,
#include "OperandTypeCode.dat"
#undef DO
	TC_LAST
} OPERAND_TYPE_CODE;

class COperandType
{
private:
	OPERAND_TYPE	m_type;
public:
	COperandType(OPERAND_TYPE_CODE code, SIZE_ATTRIBUTE attr);
	COperandType(OPERAND_TYPE type);
	
	operator OPERAND_TYPE() { return m_type; }

	static SIZE_ATTRIBUTE GetSize(OPERAND_TYPE type);
	SIZE_ATTRIBUTE GetSize(void) const
		{ return GetSize(m_type); }

	UINT	GetSizeBytes(void) const
		{ return GetSize()/8; }

	static PCSTR GetName(OPERAND_TYPE type);
	PCSTR	GetName(void) const
		{ return GetName(m_type); }

	COperandType& operator =(COperandType& op)
		{ m_type = op.m_type; return *this; }


};

class COperandTypeCode
{
private:
	OPERAND_TYPE_CODE	m_tc;
public:
	COperandTypeCode(OPERAND_TYPE_CODE tc);

	operator OPERAND_TYPE_CODE() { return m_tc; }

	static CHAR	GetCode(OPERAND_TYPE_CODE tc);
	CHAR GetCode(void) const
		{ return GetCode(m_tc); }

	static PCSTR GetName(OPERAND_TYPE_CODE tc);
	PCSTR	GetName(void) const
		{ return GetName(m_tc); }

	static PCSTR GetDescription(OPERAND_TYPE_CODE tc);
	PCSTR	GetDescription(void) const
		{ return GetDescription(m_tc); }

	static COperandType GetOperandType(OPERAND_TYPE_CODE tc, SIZE_ATTRIBUTE attr);
	COperandType GetOperandType(SIZE_ATTRIBUTE attr) const
		{ return GetOperandType(m_tc, attr); }

	static COperandType GetOperandType16(OPERAND_TYPE_CODE tc)
		{ return GetOperandType(tc, SIZE_16); }
	COperandType GetOperandType16(void) const
		{ return GetOperandType(m_tc, SIZE_16); }

	static COperandType GetOperandType32(OPERAND_TYPE_CODE tc)
		{ return GetOperandType(tc, SIZE_32); }
	COperandType GetOperandType32(void) const
		{ return GetOperandType(m_tc, SIZE_32); }
};


#endif // _COPERAND_TYPE