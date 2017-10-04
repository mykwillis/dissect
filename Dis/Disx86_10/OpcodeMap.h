#ifndef _OPCODE_MAP_H
#define _OPCODE_MAP_H
/*
 * Addressing Method
 * The addressing method for each operand of an instruction is determined
 * by one of the below schemes.  These are taken from the Intel486 Programmer's
 * Reference Guide, Appendix A.
 *
 */

/*
 * What's Really Going On Here.
 *
 * For each operand of any instruction, we set aside a word of memory
 * to tell how to find out what the operand is.  For the most part, there's
 * no rhyme or reason to this; it's just the way the Intel opcodes are
 * defined.
 * So, each operand is specified by either:
 *  1)	both an addressing mode (ADDR_xxx) and a type (TYPE_xxx).  The ADDR_xxx
 *		value tells how to find the actual operand; for example, the value 
 *		ADDR_REG_CONTROL implies that the actual operand is the control register
 *		specified by a modRM byte which follows the instruction.  The TYPE_xxx
 *		value tells the size of the operand; for example, TYPE_FAR_PTR is either
 *		32 or 48 bits, depending on the size attribute.
 *	2)	A general register value.  This is the case if the opcode has a register
 *		"hard-coded" into it.  In this case, the high bit of the operand word
 *		will be clear, as shown below.
/*

  [ 1000 tttt AAAA AAAA ]
              ^^^^ ^^^^---- Addressing Method (ADDR_xxx)
         ^^^^ ---- Type (TYPE_xxx)
     ^^^ ---- (unused; must be zero)

  // 16 bit general register specified in opcode
  [ 0xxx xxxx 0000 0rrr ]

  // 32 bit general register specified in opcode
  [ 0xxx xxxx 0001 0rrr ]

  // 16- or 32-bit general register specified in opcode, depending on opsizeattr
  [ 0xxx xxxx 0010 0rrr ]

  // 8-bit low general register specified in opcode
  [ 0xxx xxxx 0100 0rrr ]
  
  // 8-bit high general register specified in opcode
  [ 0xxx xxxx 0101 0rrr ]


*/

typedef enum {
#define DO(_code, _name, _desc) ADDR_##_code,  ADDR_##_name = ADDR_##_code,
#include "AddressingMethod.dat"
#undef DO
	ADDR_LAST
} ADDRESSING_METHOD;

//#include "COperandType.h"
//
// An OPCODE_CLASS specifies a given class of opcode (duh), i.e.,
// all MOV instructions, regardless of arguments or format, are in
// the OC_MOV class.  Aside from these standard opcode classes,
// which are defined in opcodes.dat, we define a few "meta-classes"
// which specify how to locate the actual opcode class.
//
typedef enum {
#define DO(oc) OC_##oc,
#include "Opcodes.dat"
#undef DO
	OC_NULL,
	OC_MAP_2,		// next byte of instruction must be looked up in OpcodeMap2
	OC_MAP_MODRM0,	// This value is INVALID.  Used as base for following values.
	OC_MAP_MODRM1,	// reg field of following modRM byte indexes OpcodeMapModRM[1]
	OC_MAP_MODRM2,	// reg field of following modRM byte indexes OpcodeMapModRM[2]
	OC_MAP_MODRM3,	// reg field of following modRM byte indexes OpcodeMapModRM[3]
	OC_MAP_MODRM4,	// reg field of following modRM byte indexes OpcodeMapModRM[4]
	OC_MAP_MODRM5,	// reg field of following modRM byte indexes OpcodeMapModRM[5]
	OC_MAP_MODRM6,	// reg field of following modRM byte indexes OpcodeMapModRM[6]
	OC_MAP_MODRM7,	// reg field of following modRM byte indexes OpcodeMapModRM[7]
	OC_MAP_MODRM8,	// reg field of following modRM byte indexes OpcodeMapModRM[8]
	OC_MAP_MODRM9,	// reg field of following modRM byte indexes OpcodeMapModRM[9]
	OC_MAP_MODRMA,	// reg field of following modRM byte indexes OpcodeMapModRM[10]
	OC_MAP_MODRM_LAST,	// end of MODRM opcodes
	OC_LAST,			// end of real Opcode names
} OPCODE_CLASS;

//
// General registers.
#define REG_WORD_MASK	((BYTE)0x00)
#define REG_AX	0x00
#define REG_CX	0x01
#define REG_DX	0x02
#define REG_BX	0x03
#define REG_SP	0x04
#define REG_BP	0x05
#define REG_SI	0x06
#define REG_DI	0x07

#define REG_DWORD_MASK	((BYTE)0x10)
#define REG_EAX	0x10
#define REG_ECX	0x11
#define REG_EDX	0x12
#define REG_EBX	0x13
#define REG_ESP	0x14
#define REG_EBP	0x15
#define REG_ESI	0x16
#define REG_EDI	0x17

#define REG_WORD_OR_DWORD_MASK	((BYTE)0x20)
#define REG_DEFAULT_MASK	REG_WORD_OR_DWORD_MASK
#define REG_eAX	0x20
#define REG_eCX	0x21
#define REG_eDX	0x22
#define REG_eBX	0x23
#define REG_eSP	0x24
#define REG_eBP	0x25
#define REG_eSI	0x26
#define REG_eDI	0x27

#define REG_BYTE_MASK	((BYTE)0x40)
#define REG_AL	0x40
#define REG_CL	0x41
#define REG_DL	0x42
#define REG_BL	0x43

#define REG_AH	0x44
#define REG_CH	0x45
#define REG_DH	0x46
#define REG_BH	0x47

#define REG_SEG_MASK	((BYTE)0x80)
#define REG_CS	0x80
#define REG_DS	0x81
#define REG_ES	0x82
#define REG_FS	0x83
#define REG_GS	0x84
#define REG_SS	0x85


// Addressing method is in the bottom byte
#define OPERAND_ADDRESSING(operand)		((ADDRESSING_METHOD)((WORD)operand & 0x00ff))
// Addressing type is in third most-sig nibble
#define OT_CODE(operand)			((OPERAND_TYPE_CODE)(((WORD)operand & 0x0f00) >> 8))
// If bit 0x8000 is set, the register is NOT encoded in the opcode
#define OPERAND_IS_ENCODED_REG(operand)	((BOOL)((WORD)operand & 0x8000)?0:1)

#define OPERAND_ENCODED_REG(operand)	((WORD)operand & 0x00ff)

// returns the standardized index for the encoded register
#define OPERAND_ENCODED_REG_IDX(operand)	((WORD)operand & 0x000f)
#define OPERAND_IS_BYTE_REG(operand)	((BOOL)((WORD)operand & REG_BYTE_MASK)?1:0)
#define OPERAND_IS_WORD_REG(operand)	((BOOL)((WORD)operand == OPERAND_ENCODED_REG_IDX(operand))?1:0)
#define OPERAND_IS_SEG_REG(operand)		((BOOL)((WORD)operand & REG_SEG_MASK)?1:0)
#define OPERAND_IS_DEFAULT_REG(operand)	((BOOL)((WORD)operand & REG_DEFAULT_MASK)?1:0)
// OPERAND_IS_DEBUG_REG and OPERAND_IS_CONTROL_REG don't exists, since these
// registers are never encoded directly into the instruction

#define REG_IDX(_reg)	((WORD)_reg & 0x000f)
#define MK_OP(_addr, _type)	((WORD)(BYTE)_type << 8 | (WORD)(BYTE)_addr | 0x8000)
#define MK_REG_OP(_reg)	(_reg)
#define OP_NONE		(WORD)-1
#define OP_UNKNOWN	(WORD)-2
#define OP_INVALID	(WORD)-3
#define OP_IS_VALID(_o)	((BOOL)(_o != OP_NONE && _o != OP_UNKNOWN && _o != OP_INVALID))

typedef WORD OPDEF;	// operand def
typedef struct {
	OPCODE_CLASS	cls;		// opcode class, i.e., ADD, AND, etc
	OPDEF	op1;		// 
	OPDEF	op2;		// 
	OPDEF	op3;

	OPDEF op(int i) const	{
		switch(i)	{
		case 0:
			return op1;
		case 1:
			return op2;
		case 2:
			return op3;
		default:
			return OP_NONE;
		}
	}
	void setOp(int i, OPDEF op)	{
		switch(i)	{
		case 0:
			op1 = op;
			break;
		case 1:
			op2 = op;
			break;
		case 2:
			op3 = op;
			break;
		default:
			break;
		}
		return;
	}
} OPCODE_DEF;

//
// Array of single-byte opcode instructions
//
extern OPCODE_DEF OpcodeMap1[0x100];

//
// Array of double-byte opcode instructions
//
extern OPCODE_DEF OpcodeMap2[0x100];

//
// Array of opcodes that use ModR/M opcode extensions
//
extern OPCODE_DEF OpcodeMapModRM[9][8];

#endif // OPCODE_MAP_H