#include "project.h"
#include "COperandType.h"

//
// The OPERAND_TYPE enum indexes into the OperandSizeInfo[] array
//
struct	{
	SIZE_ATTRIBUTE size;
	PCSTR	szName;	// name of this operand size, i.e., "byte"
} OperandTypeInfo[]	=
{
#define DO(_type, _size, _name)	\
	{ _size, _name },
#include "OperandType.dat"
#undef DO
};

struct {
	CHAR			cCode;	// The one-letter code given by Intel
	OPERAND_TYPE	type16;	// type of this operand when 16-bit operand-size attribute
	OPERAND_TYPE	type32;	// type of this operand when 32-bit operand-size attribute

	PCSTR			szName;	// the internal name of this type (BOUND, etc.)
	PCSTR			szDesc;	// text description of the type
} OperandTypeCodeInfo[] =
{
#define DO(_code, _name, _type16, _type32, _desc) \
	{ #@_code, TYPE_##_type16, TYPE_##_type32, #_name, _desc },
#include "OperandTypeCode.dat"
#undef DO
};


COperandType::COperandType(OPERAND_TYPE_CODE tc, SIZE_ATTRIBUTE attr)
{
	ASSERT( tc < TC_LAST );
	ASSERT( attr == SIZE_16 || attr == SIZE_32 );

	m_type = (attr == SIZE_16)	? OperandTypeCodeInfo[tc].type16 
								: OperandTypeCodeInfo[tc].type32;
}

SIZE_ATTRIBUTE
COperandType::GetSize(OPERAND_TYPE type)
{
	ASSERT(type < TYPE_LAST);
	return OperandTypeInfo[type].size;
}

PCSTR
COperandType::GetName(OPERAND_TYPE type)
{
	ASSERT(type < TYPE_LAST);
	return OperandTypeInfo[type].szName;
}

//
//
//
//
//

CHAR
COperandTypeCode::GetCode(OPERAND_TYPE_CODE tc)
{
	ASSERT(tc < TC_LAST);
	return OperandTypeCodeInfo[tc].cCode;
}

PCSTR
COperandTypeCode::GetName(OPERAND_TYPE_CODE tc)
{
	ASSERT(tc < TC_LAST);
	return OperandTypeCodeInfo[tc].szName;
}

PCSTR
COperandTypeCode::GetDescription(OPERAND_TYPE_CODE tc)
{
	ASSERT(tc < TC_LAST);
	return OperandTypeCodeInfo[tc].szDesc;
}

COperandType
COperandTypeCode::GetOperandType(OPERAND_TYPE_CODE tc, SIZE_ATTRIBUTE attr)
{
	ASSERT(tc < TC_LAST);
	ASSERT(attr < SIZE_LAST);

	COperandType type(tc, attr);

	return type;
}