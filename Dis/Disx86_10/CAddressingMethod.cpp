//
// Dissect Disassembler
// Copyright (c) 1998 RevEngr Systems, Inc.
// All Rights Reserved.
//
// CAddressingMethod.cpp
//
#include "project.h"
#include "CAddressingMethod.h"

struct {
	CHAR	cCode;
	PCSTR	szName;
	PCSTR	szDesc;
} AddressingMethodInfo[] =
{
#define DO(_code, _name, _desc) { #@_code, #_name, _desc },
#include "AddressingMethod.dat"
#undef DO
};

#define NUM_ADDRESSING_METHODS	(sizeof(AddressingMethodInfo) / sizeof(AddressingMethodInfo[0]))


CHAR
CAddressingMethod::GetCode(ADDRESSING_METHOD method)
{
	ASSERT(method < NUM_ADDRESSING_METHODS);
	return AddressingMethodInfo[method].cCode;
}

PCSTR
CAddressingMethod::GetName(ADDRESSING_METHOD method)
{
	ASSERT(method < NUM_ADDRESSING_METHODS);
	return AddressingMethodInfo[method].szName;
}

PCSTR
CAddressingMethod::GetDescription(ADDRESSING_METHOD method)
{
	ASSERT(method < NUM_ADDRESSING_METHODS);
	return AddressingMethodInfo[method].szDesc;
}
