#ifndef _COPERAND_H
#define _COPERAND_H

#include "COperandType.h"

class CInstruction;
class CReg;
class CEffectiveAddress;
class CImmediate;
class COperandType;

class COperand
{
private:
	CInstruction&	m_inst;
	OPDEF			m_opDef;

	// returns the name of the register that is this operand, if the
	// register is specified in the opcode itself.
	PCSTR GetEncodedRegisterString() const;

#ifdef _AFX
	CString	GetModRMAddressString() const;
	CString GetModRMAddressName16() const;
	CString GetModRMAddressName32() const;
	
	CString	GetSIBAddressString() const;
#endif // _AFX

public:
	SIZE_ATTRIBUTE GetSize(void) const;
	COperand(CInstruction &inst, OPDEF m_opDef);

#ifdef _AFX
	CString GetAddressString(void) const;
	CString GetCString(void) const;
#endif // _AFX

	PCSTR GetTypeName(void) const;


	
	// TRUE if this operand is encoded into the instruction
	BOOL isDirect(void) const;

	// TRUE if this operand is a memory location specified through indirection (pointer)
	BOOL isIndirect(void) const;
	
	// TRUE if this operand is a general register
	BOOL isGeneralRegister(void) const;

	// TRUE if this operand is a stack variable
	BOOL isStackPointer(void) const;

	// TRUE if operand is register
	BOOL isRegister(void) const;

	// TRUE if operand is immediate
	BOOL isImmediate(void) const;

	// TRUE if operand is a pointer
	BOOL isPointer(void) const;

	// returns CReg for this operand in reg, if isRegister()
	CReg&	GetRegister(CReg& reg) const;

	// returns CImmediate for this operand in imm, if isImmediate()
	CImmediate&	GetImmediate(CImmediate& imm);

	// returns CEffectiveAddress for this operand in ea, if isMemory()
	CEffectiveAddress&	GetEffectiveAddress(CEffectiveAddress& ea) const;

	ADDRESSING_METHOD	GetAddressingMethod(void) const;
	OPERAND_TYPE		GetOperandType(void) const;
	COperandType&		GetOperandType(COperandType& ot) const;

	CInstruction&		GetInstruction(void) const
		{ return m_inst; }

	OPERAND *	GetOPERAND(OPERAND *pOp) const;
	// we need an equality operand...we may need to allow for
	// extra context, so that we can evaluate, for instance, if
	// [eax] == [ecx]...
	//operator ==(COperand& op)
};

#endif // _COPERAND_H