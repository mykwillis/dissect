#include "project.h"
#include "CInstruction.h"
#include "XDisException.h"
#include "COperand.h"
#include "CReg.h"
#include "CFundamentalDataType.h"
#include "COperandType.h"

PCSTR OpcodeNames[] =
{
#define DO(oc) #oc,
#include "Opcodes.dat"
#undef DO
};

//
// GetClassName() retrieves a pointer to the class name for this instruction
// Depends on _BuildOpcodeDef() having been called to set up m_ocDef
//
PCSTR
CInstruction::GetClassName(void) const
{
	//ASSERT_VALID_OPCODE_CLASS(m_ocDef.cls);
	return OpcodeNames[m_ocDef.cls];
}

//
// GetOperandDef() returns the OPDEF for a given operand.
// Depends on _BuildOpcodeDef() having been called to set up m_ocDef
//
OPDEF
CInstruction::GetOperandDef(int i) const
{
	return m_ocDef.op(i);
}

//
// _BuildOpcodeDef() fills in the m_ocDef OPCODE_DEF structure with the
// appropriate OPCODE_CLASS and OPDEFS for an instruction
// Depends on having read in opcode bytes, as well as modRM and SIB if present.
//
void
CInstruction::_BuildOpcodeDef()
{
	OPDEF wDef= OP_INVALID;

	//
	// An OPCODE_DEF is built for every instruction, which holds information
	// about the instruction's class (name), and up to three OPDEF structures,
	// which specify the operands of the instruction.
	//
	// Unfortunately, we can't just use the pre-built OPCODE_DEF structures
	// that exist in the OpcodeMapx arrays, because instructions with
	// opcode extensions have different operands depending on the value
	// of the nnn field of the ModR/M byte.  To deal with this, we build
	// an OPCODE_DEF for every instruction, putting the pieces together
	// for the extension case.
	//
	
	
	//
	// First, we have to locate the OPCODE_DEF structure that contains
	// the operand definition we're looking for.  Note that it very well
	// could be that the OPCODE_DEF structure holding the operand definition
	// is NOT the same structure that contains the OPCODE_CLASS (the name of
	// the instruction).  This could happen, for instance, when the operands
	// are defined in the ModR/M byte, but the OPCODE_CLASS is defined in either
	// of the "normal" OpcodeMap structures.
	//
	// In any case, this OPCODE_DEF structure we are looking for could
	// be:
	// 1) in the OpcodeMap1 array;
	// 2) in the OpcodeMap2 array, if the OPCODE_CLASS in OpcodeMap1 is OC_MAP_2;
	// 3) in an OpcodeMapModRM array, if the OPCODE_CLASS in either OpcodeMap1 or
	//		OpcodeMap2 is OC_MAP_MODRMx.
	//
	// The only special case that we have to deal with here is with OC_MAP_MODRM3
	// instructions.  The operands for these instructions have to be determined
	// on the fly.

	// go through all of the operands in this instruction.  Note that we
	// have to keep going even if we find OP_NONE, since we are building
	// our internal OPCODE_DEF structure.
	for (int i=0; i < 3 ; i++, wDef = OP_INVALID)	{
		// Initialize the search in OpcodeMap1
		OPCODE_DEF *pOpcodeDef = &OpcodeMap1[m_oc1];

		// this inner loop determines a single operand.  The operand might be
		// defined in the OpcodeMap array, or one of the OpcodeMapModRM arrays.
		// Additionally, all of this instruction's operands need not be defined
		// in the same place.
		// Most of the confusion comes from the Opcode Extensions (instructions
		// that use the OC_MAP_MODRMx tables).
		while (OP_INVALID == wDef)	{
			// Switch on the current OPCODE_DEF structure.  This struct could be in any
			// of the arrays listed above.
			switch ( pOpcodeDef->cls )	{
			case OC_INVALID:
				wDef = OP_NONE;
				//throw XDisException("Invalid opcode");
				//wDef = OP_NONE;
				break;
			case OC_MAP_2:
				// This operand is defined in the two-byte opcode cap
				pOpcodeDef = &OpcodeMap2[m_oc2];
				break;	// go back to switch on the class in OpcodeMap2
			
			
			//
			// It gets kind of messy here, since it is possible to have the operand
			// definition we're looking for be in either an OpcodeMapModRM array
			// or one of the OpcodeMapx arrays.
			//
			case OC_MAP_MODRM1:
			case OC_MAP_MODRM2:
				// Group 1 and 2 ModRM instructions always have their operands defined
				// by the OPCODE_DEF structure in the OpcodeMapX array.  That is to say,
				// we don't have to bother looking this instruction up in the OpcodeMapModRM
				// array, because all that would give us is the class name.
				wDef = pOpcodeDef->op(i);
				break;
			case OC_MAP_MODRM3:
				// This is the messiest of all cases.
				switch( m_modrm.reg )	{
				case 0:	// 000 - TEST
					if (0 == i)	{	// first operand is encoded in the oc1 map
						wDef = OpcodeMap1[m_oc1].op(0);
					} else if (1 == i){		// second operand has addressing immediate, type same
									// as first operand
						wDef = MK_OP( ADDR_I, OT_CODE( OpcodeMap1[m_oc1].op(0) ));
					} else {	// no third operand
						wDef = OP_NONE;
					}
					break;
				case 1:	// 001 - INVALID
					throw XDisException("Invalid Opcode");
					break;
				case 2:	// 010 - NOT
				case 3:	// 011 - NEG
					if (0 == i)	{	// first operand is encoded in oc1 map
						wDef = OpcodeMap1[m_oc1].op(0);
					} else	{	// only on operand
						wDef = OP_NONE;
					}
					break;
				case 4:	// 100 - MUL  AL/eAX
				case 5:	// 101 - IMUL AL/eAX
				case 6:	// 110 - DIV  AL/eAX
				case 7:	// 111 - IDIV AL/eAX
					if (0 == i)	{// first operand is AL or eAX
						if ( TC_BYTE == OT_CODE(OpcodeMap1[m_oc1].op(0)) )	{
							wDef = MK_REG_OP( REG_AL );
						} else {
							ASSERT( TC_WORD_OR_DBLWORD == OT_CODE(OpcodeMap1[m_oc1].op(0)));
							wDef = MK_REG_OP( REG_eAX );
						}
					} else if (1==i){	// second operand is given in the oc1 map
						wDef = OpcodeMap1[m_oc1].op(0);	// yes, the first position, not second
					} else {
						wDef = OP_NONE;
					}
					break;
				default:
					ASSERT(0);
				}
				break;

			case OC_MAP_MODRM4:
			case OC_MAP_MODRM5:
			case OC_MAP_MODRM6:
			case OC_MAP_MODRM7:
			case OC_MAP_MODRM8:
				// Group 4-8 ModRM instructions have their entire opcode and operand
				// definitions in the OpcodeMapModRM array.

				// Index into the two-dimensional OpcodeMapModRM array
				wDef = OpcodeMapModRM[pOpcodeDef->cls - OC_MAP_MODRM0] [m_modrm.reg].op(i);
				break;
			default:
				wDef = pOpcodeDef->op(i);
				break;
			} // switch
		} // while (OP_INVALID == wDef)
	
		ASSERT( OP_INVALID != wDef );
		m_pOperand[i] = new COperand(*this, wDef);
		m_ocDef.setOp(i, wDef); // might be OP_NONE
	} // for (all operands)

	// now, fill in the class field
	m_ocDef.cls = _GetClass();
}

//
// Reads the passed instruction prefix into the appropriate member variable,
// and sets flags accordingly.
// returns TRUE if the byte is a valid instruction prefix, FALSE otherwise.
// No dependancies.
//
BOOL
CInstruction::_ReadPrefix(BYTE prefix)
{
	//
	// we treat prefixes as opcodes in this context, since they have
	// entries in the OpcodeMap just like the opcodes.
	// Note that multiple prefixes of the same type produce undefined
	// behavior; we just take the last one.
	//
	OPCODE_CLASS o = OpcodeMap1[prefix].cls;
	switch(o)	{
	case OC_REP:
	case OC_REPNE:
	case OC_LOCK:
		// notify if prefix already read
		m_lockOrRepeatP = prefix;
		m_dwFlags |= F_LOCKORREPEAT_P;
		break;
	case OC_ADDR_SIZE:
		// notify if prefix already read
		m_addrSizeOP = prefix;
		m_dwFlags |= F_ADDR_SIZE_OP;
		break;
	case OC_OP_SIZE:
		// notify if prefix already read
		m_opSizeOP = prefix;
		m_dwFlags |= F_OP_SIZE_OP;
		break;
	case OC_SEG:
		// notify if prefix already read
		m_segOP = prefix;
		m_dwFlags |= F_SEG_OP;
		break;
	default:
		return FALSE;
	}

	return TRUE;
}

//
// hasOpcodeExtension() will return TRUE if this instruction uses the
// nnn bits of the ModR/M byte as an opcode extension.
// Depends on having already read in all (1 or 2) opcode bytes
//
BOOL
CInstruction::hasOpcodeExtension(void) const
{
	OPCODE_CLASS cls;
	
	//
	// Get the OPCODE_CLASS for this opcode, which will tell us whether
	// or not this opcode uses an extension.  Note that we don't use
	// m_ocDef.cls, since it may not be set up yet.
	//
	if ( 2 == GetOpcodeSize() )	{
		cls = OpcodeMap2[m_oc2].cls;
	} else {
		ASSERT( 1 == GetOpcodeSize() );	// opcodes are 1 or 2 bytes
		cls = OpcodeMap1[m_oc1].cls;
	}

	//
	// Opcodes that use the extension bits in the ModR/M byte are
	// marked with an OC_MAP_MODRMx value, where 'x' is the group
	// number to which the opcode belongs. (MODRM0 is not valid).
	//
	return ( cls > OC_MAP_MODRM0 && cls < OC_MAP_MODRM_LAST );

}

//
// _ReadOpcode() reads in all (either 1 or 2) opcode bytes for this
// instruction.  It may also read the ModRM byte if the opcode has
// an extension therein.
// Returns the number of bytes in this opcode (1 or 2).
// No dependencies.
//
int
CInstruction::_ReadOpcode(PBYTE pCode)
{
	//
	// Read in the first byte of the opcode
	//
	m_oc1 = *pCode++;
	m_dwFlags |= F_OC1;

	//
	// If opcode has two bytes, read in the second byte
	//
	if ( OpcodeMap1[m_oc1].cls == OC_MAP_2 )	{
		m_oc2 = *pCode++;
		m_dwFlags |= F_OC2;
	}

	//
	// Some opcodes use the bits 5,4, and 3 of the ModR/M byte
	// (so-called nnn bits) as an extension to the opcode.
	// These opcodes are referred to as "Group 1" or "Group 2" etc.
	// If this opcode has an extension, the ModR/M byte will
	// immediately follow the last opcode byte.
	//
	if ( hasOpcodeExtension() )	{
		m_modrm.modRM = *pCode;	// dont advance code pointer; the ModR/M byte is accounted for later
		m_dwFlags |= F_MODRM;
	}
	
	//
	// Return either 1 or 2, depending on opcode size (we ignore opcode
	// extensions here)
	//
	return BITTEST(m_dwFlags, F_OC2) ? 2 : 1;
	
}

//
// Dis() disassembles the instruction at pCode.
// Returns number of bytes in instruction.
//
UINT
CInstruction::Dis(PBYTE pCode, DWORD dwVirtualAddress /* = -1 */)
{
	//
	// Clear out the state
	//
	Cleanup();

	m_pBase = pCode;
	m_dwVirtualAddress = dwVirtualAddress == -1 ? (DWORD)pCode : dwVirtualAddress;


	//
	// copy over the next 16 bytes.  Even though most of these bytes will
	// be stored individually in one of our data members, we need to be
	// able to store the sequence in which they occur.  For instance, 
	// instruction prefix bytes can occur in any order.
	//
	memcpy(m_instr, pCode, MAX_INSTRUCTION_LEN);
	
	//
	// read any valid instruction prefixes.  _ReadPrefix() returns FALSE
	// when it encounters an invalid prefix.
	//
	while ( _ReadPrefix( m_instr[m_cbInstr] ) )
		m_cbInstr++;

	//
	// Read in the opcode byte(s).  ReadOpcode returns number of bytes in opcode
	//
	m_cbInstr += _ReadOpcode( &m_instr[m_cbInstr] );

	//
	// build our OPCODE_DEF structure (m_ocDef) from info in the OpcodeMap 
	// arrays.
	//
	_BuildOpcodeDef();

	//
	// From this point on, we know everything about this instruction,
	// including its class and operand types.
	//

	m_cbInstr += _ReadModRM(m_instr[m_cbInstr]);	// returns 0 if no ModR/M
	m_cbInstr += _ReadSIB(m_instr[m_cbInstr]);		// returns 0 if no SIB

	//
	// If an operand specified a displacement to follow the opcodes, it
	// will always come before any immediate value.  _ReadDisplacement()
	// and _ReadImmediate() both return the number of bytes (possibly 0)
	// that they read in.
	//
	m_cbInstr += _ReadDisplacement( &m_instr[m_cbInstr] );
	m_cbInstr += _ReadImmediate( &m_instr[m_cbInstr] );

	//
	// Two special instructions use a direct addressing mode, where an
	// actual far pointer is encoded directly after the opcode.  Check
	// for this case
	//
	m_cbInstr += _ReadDirect( &m_instr[m_cbInstr] );

	//
	// If we didn't get a valid opcode, return 0
	//
	if ( GetClass() == OC_INVALID )
		return 0;

	//
	// If we got a valid opcode, but the instruction was not formed
	// properly, return 0;
	// BUGBUG: isValid() is not yet implemented!
	if ( !isValid() )
		return 0;

	//
	// Return the total number of bytes in this instruction
	//
	return m_cbInstr;
}

//
// _OperandUsesModRM() will return TRUE if the operand specified as a
// parameter uses an addressing mode that requires the presence of a
// ModRM byte to follow the opcode.
// Depends on _BuildOpcodeDef() having been called.
//
BOOL
CInstruction::_OperandUsesModRM(int i)
{
	OPDEF o = m_ocDef.op(i);

	if ( !OP_IS_VALID(o) )
		return FALSE;

	//
	// If this operand is a hardcoded register, it does not require ModR/M
	//
	if ( OPERAND_IS_ENCODED_REG(o) )
		return FALSE;

	switch ( OPERAND_ADDRESSING(o) )	{
	case ADDR_DIRECT:

	case ADDR_REG_CONTROL:	// modRM selects a control register
	case ADDR_REG_DEBUG:	// modRM selects a debug register
	case ADDR_REG_OR_MEM:	// modRM follows; either a gen reg or mem addr
	case ADDR_MMX_OR_MEM:	// modRM follows; either an MMX reg or mem addr
	case ADDR_REG_GEN:		// modRM selects a general register
	case ADDR_REG_MMX:		// modRM selects an MMX register
	case ADDR_MEM:			// modRM byte refers only to memory e.g. BOUND, LES, LFS, etc.
	case ADDR_MOD_REG_GEN:	// the mod field of the modRM byte refers to general register
	case ADDR_REG_SEG:		// modRM selects a segment register
	case ADDR_REG_TEST:		// modRM selects a test register
		return TRUE;
	default:
		return FALSE;
	}
}

//
// _InstructionUsesModRM() will return TRUE if this instruction has a 
// ModRM byte.
// Depends on _ReadOpcode() and _BuildOpcodeDef() having been called.
//
BOOL
CInstruction::_InstructionUsesModRM()
{
	//
	// The ModRM byte could be used either as an opcode extension, or an
	// extra operand specification (or both)
	//

	if ( hasOpcodeExtension() )
		return TRUE;

	for (int i=0;i<3;i++)	{
		if ( _OperandUsesModRM(i) )	{
			return TRUE;
		}
	}
	return FALSE;
}

//
// _InstructionUsesSIB() will return TRUE if this instruction has a SIB byte
// Depends on _ReadModRM() having been called.
//
BOOL
CInstruction::_InstructionUsesSIB()
{
	//
	// a SIB byte is only required in the based indexed and scaled indexed forms
	// of 32-bit addressing
	//
	if ( SIZE_16 == GetAddressSizeAttribute() )
		return FALSE;

	//
	// SIB bytes are always preceeded by a ModR/M byte
	//
	if ( !(m_dwFlags & F_MODRM) )
		return FALSE;

	//
	// SIB is used if rm field is 0100b and mod field is NOT 011b
	// (those are just the rules!)
	//
	if ( m_modrm.mod == 0x3 )
		return FALSE;

	if ( m_modrm.rm != 0x4 )
		return FALSE;

	return TRUE;
}

//
// _ReadModRM() returns TRUE if the instruction uses ModRM, and reads 
// the given byte if so.
// Depends on _ReadOpcode() and _BuildOpcodeDef() having been called.
//
BOOL
CInstruction::_ReadModRM(BYTE modrm)
{
	// Note that _ReadOpcode may have already read in the modrm byte
	// if it is needed for an opcode extension for this instruction.
	// It really doesn't hurt to do it again in this case, though.
	if ( _InstructionUsesModRM() )	{
		m_modrm.modRM = modrm;
		m_dwFlags |= F_MODRM;
		return TRUE;
	}
	return FALSE;
}

//
// _ReadSIB() returns TRUE if the instruction uses a SIB byte, and reads 
// the given byte if so.
// Depends on _ReadModRM() having been called.
//
BOOL
CInstruction::_ReadSIB(BYTE sib)
{
	if ( _InstructionUsesSIB() )	{
		m_sib.sib = sib;
		m_dwFlags |= F_SIB;
		return TRUE;
	}
	return FALSE;
}

//
// _GetDisplacementSize() returns the number of bytes needed by
// this instruction to specify a displacement (possibly 0).
// Depends on _ReadModRM() having been called.
//
UINT
CInstruction::_GetDisplacementSize()
{

	//
	// Only instructions with a ModRM byte can have displacements
	//
	if ( !hasModRM() )
		return 0;

	//
	// This switch calculates the number of bytes needed for displacement
	// by applying the rules given in the Instruction Format of the
	// Intel manuals.  The mod field of ModRM is the key to finding
	// displacement size (if there is one).
	//
	UINT size;
	switch( m_modrm.mod )	{
	case 0x00:
		if ( 0x6 == m_modrm.rm && SIZE_16 == GetAddressSizeAttribute() )
			size = 2;	// 16 bits
		else if ( 0x5 == m_modrm.rm && SIZE_32 == GetAddressSizeAttribute() )
			size = 4;	// 32 bits
		else if ( 0x4 == m_modrm.rm && 0x5 == m_sib.base && SIZE_32 == GetAddressSizeAttribute() )
			size = 4;	// 32 bits
		else
			size = 0;

		break;
	case 0x1:
		// If Mod is 01b, there is an 8 bit (always) displacement 
		size = 1;
		break;
	case 0x2:
		// If Mod is 10b, there is a default-size displacement
		size = (GetAddressSizeAttribute() == SIZE_16) ? 2 : 4;
		break;
	default:
		// If Mod is 11b, there is no displacement (this is register
		// direct addressing).
		size =0;
		break;
	}

	return size;
}


int 
CInstruction::_ReadDisplacement(PBYTE p)
{
	m_cbDisp = _GetDisplacementSize();
	if (m_cbDisp)	{
		memcpy(&m_displacement, p, m_cbDisp);
		m_dwFlags |= F_DISP;
	}
	return m_cbDisp;
}

UINT
CInstruction::_GetImmediateSize()
{
	//
	// Only one of the operands can use (or be) an immediate,
	// so we loop through all three looking for one that is.
	// we only return 0 after being sure none of the operands use
	// it

	for (int i=0;i<3;i++)	{
		switch ( OPERAND_ADDRESSING(m_ocDef.op(i)) )	{
		case ADDR_IMM:
			// Here's the straight up immediate...
		case ADDR_RELOFFSET:
			// This is the case for instructions like JMP; the
			// immediate that follows is to be added to the PC
		case ADDR_OFFSET:
			// Exact offset of operand is encoded as an immediate
			return GetOperandTypeSizeBytes( m_ocDef.op(i) );
		case ADDR_DIRECT:
			// The address of the operand is encoded in the instruction.
			// this basically translates to either a 4- or 6-byte immediate,
			// which is the direct address used by the instruction.  We only
			// have space for a 4-byte value, though.
			// instead of cluttering this code, we will check for the
			// case of a direct operand later.
			// return 0;
		default:
			break;
		}
	}
	return 0;
}

int
CInstruction::_ReadImmediate(PBYTE p)
{
	m_cbImm = _GetImmediateSize();
	if (m_cbImm)	{
		memcpy(m_immediate, p, m_cbImm);
		m_dwFlags |= F_IMM;
	}
	return m_cbImm;

}

BYTE
CInstruction::GetSegmentOverridePrefix	(void) const
{
	if ( !hasSegmentOverridePrefix() )
		throw XDisException("SegOP not present");

	return m_segOP;

}
BYTE
CInstruction::GetLockOrRepeatPrefix(void) const
{
	if ( !hasLockOrRepeatPrefix() )
		throw XDisException("LockOrRepeatP not present");
	
	return m_lockOrRepeatP;
}
BYTE
CInstruction::GetOperandSizeOverridePrefix(void) const
{
	if ( !hasOperandSizeOverridePrefix() )
		throw XDisException("OpSizeOP not present");

	return m_opSizeOP;

}
BYTE
CInstruction::GetAddressSizeOverridePrefix(void) const
{
	if ( !hasAddressSizeOverridePrefix() )
		throw XDisException("AddrSizeOP not present");

	return m_addrSizeOP;

}

BYTE
CInstruction::GetOpcode1(void) const
{
	return m_oc1;
}
BYTE
CInstruction::GetOpcode2(void) const
{
	if ( GetOpcodeSize() != 2 )
		throw XDisException("Opcode2 not present");

	return m_oc2;
}

MODRM
CInstruction::GetModRM (void) const
{
	if ( !hasModRM() )
		throw XDisException("ModRM not present");

	return m_modrm;
}

SIB
CInstruction::GetSIB (void) const
{
	if ( !hasSIB() )
		throw XDisException("SIB not present");
	
	return m_sib;
	
}

//DWORD
//CInstruction::GetDisplacement(void) const
//{
//	if (!m_cbDisp)
//		throw XDisException("Displacement not present");

//	return m_displacement;
//
//}

//CDisplacement&
//CInstruction::GetDisplacement(CDisplacement& disp) const
//{
//	if (!m_cbDisp)
//		throw XDisException("Displacement not present");

	// ASSUMING that displacements are always signed
//	disp.SetValue(	GetDisplacement(), 
//					ByteToSizeAttribute( GetDisplacementSize() ), 
//					TRUE /* signed */ );

//	return disp;
//}

//DWORD 
//CInstruction::GetImmediate(void) const
//{
//	if (!m_cbImm)
//		throw XDisException("Immediate not present");
//
//	return m_immediate;
//}

CImmediate&
CInstruction::GetImmediate(CImmediate& imm, BOOL bSigned ) const
{
	if (!m_cbImm)
		throw XDisException("Immediate not present");

	//
	// Even though we don't properly sign-extend to DWORD here,
	// CImmediate will take care of fixing up after us...
	//
	DWORD dwImm;
	switch( GetImmediateSizeAttribute() )	{
	case SIZE_8:
		dwImm = (DWORD) (*(BYTE *)m_immediate);
		break;
	case SIZE_16:
		dwImm = (DWORD) (*(WORD *)m_immediate);
		break;
	case SIZE_32:
		dwImm = (DWORD) (*(DWORD *)m_immediate);
		break;
	default:
		ASSERT(0);
	}		

	imm.SetValue( 
		dwImm,
		GetImmediateSizeAttribute(), 
		bSigned);

	return imm;
}

CImmediate&
CInstruction::GetImmediateAsAddressOffset(CImmediate& imm, BOOL bSigned ) const
{
	if (!m_cbImm)
		throw XDisException("Immediate not present");

	//
	// Even though we don't properly sign-extend to DWORD here,
	// CImmediate will take care of fixing up after us...
	//
	DWORD dwImm;
	switch( GetImmediateSizeAttribute() )	{
	case SIZE_8:
		dwImm = (DWORD) (*(BYTE *)m_immediate);
		break;
	case SIZE_16:
		dwImm = (DWORD) (*(WORD *)m_immediate);
		break;
	case SIZE_32:
		dwImm = (DWORD) (*(DWORD *)m_immediate);
		break;
	default:
		ASSERT(0);
	}		

	imm.SetValue( 
		dwImm,
		GetAddressSizeAttribute(), 
		bSigned);

	return imm;
}


CDisplacement&
CInstruction::GetDisplacement(CDisplacement& imm, BOOL bSigned ) const
{
	if (!m_cbDisp)
		throw XDisException("Displacement not present");

	//
	// Even though we don't properly sign-extend to DWORD here,
	// CDisplacement will take care of fixing up after us...
	//
	DWORD dwDisp;
	switch( GetDisplacementSizeAttribute() )	{
	case SIZE_8:
		dwDisp = (DWORD) (*(BYTE *)m_displacement);
		break;
	case SIZE_16:
		dwDisp = (DWORD) (*(WORD *)m_displacement);
		break;
	case SIZE_32:
		dwDisp = (DWORD) (*(DWORD *)m_displacement);
		break;
	default:
		ASSERT(0);
	}		

	imm.SetValue( 
		dwDisp,
		GetDisplacementSizeAttribute(), 
		bSigned);

	return imm;
}



DWORD
CInstruction::GetDirect32(void) const
{
	ASSERT( hasDirect32() );
	return m_dwDirect32;
}

TWORD
CInstruction::GetDirect48(void) const
{
	ASSERT( hasDirect48() );
	return m_twDirect48;
}

UINT
CInstruction::GetOperandTypeSizeBytes(OPDEF op)
{
	COperandType type( OT_CODE(op), GetOperandSizeAttribute() );
	return type.GetSizeBytes();
}

CInstruction::CInstruction() : CUnknown(NULL)
{
	Clear();
}

void
CInstruction::Clear()
{
	m_addrSizeOP = 0;
	m_cbDisp =0;
	m_cbImm = 0;
	m_cbInstr = 0;
	m_dwFlags = 0;
	memset(m_displacement, 0, sizeof(m_displacement) );
	memset(m_immediate, 0, sizeof(m_immediate) );
	memset(m_instr, 0, sizeof(m_instr));
	m_lockOrRepeatP = 0;
	m_modrm.modRM = 0;
	m_oc1 = 0;
	m_oc2 = 0;
	memset(&m_ocDef, 0, sizeof(m_ocDef));
	m_opSizeOP = 0;
	m_pBase = NULL;
	m_dwVirtualAddress = 0;
	m_segOP = 0;
	m_sib.sib = 0;

	for (int i=0;i<3;i++)	{
		m_pOperand[i] = 0;
	}
}

void
CInstruction::Cleanup()
{
	for (int i=0;i<3;i++)	{
		delete m_pOperand[i];
		m_pOperand[i] = 0;
	}
	Clear();
}

void
CInstruction::Dump()
{
#if 0
	char buf[256];
	char buf2[256];

	sprintf(buf, "%X: ", (DWORD) GetVirtualAddress() );
	for (int j=0;j<(int)m_cbInstr;j++)	{
		sprintf(buf2, "%2X ", (DWORD)m_instr[j]);
		strcat(buf, buf2);
	}

	sprintf(buf2, "%s ", GetClassName());
	
	for (UINT i=0;i<GetNumberOfOperands();i++)	{
		char opAddr[128];

		GetOperandAddressName(i, opAddr, 128);
		sprintf(buf2, " [%s]%s ", m_pOperand[i]->GetTypeName(), opAddr);
		strcat(buf, buf2);
	}
	strcat(buf, "\n");

	OutputDebugString(buf);

	strcat(buf, "ModRM: ");
	if (hasModRM())	{
		sprintf(buf2, "%-2Xh\n", (BYTE)GetModRM().modRM);
		strcat(buf, buf2);
	} else	{
		strcat(buf, "none\n");
	}

	strcat(buf, "SIB  : ");
	if (hasSIB())	{
		sprintf(buf2, "%-2X\n", (BYTE)GetSIB().sib);
		strcat(buf, buf2);
	} else	{
		strcat(buf, "none\n");
	}

	OutputDebugString(buf);
#endif // if 0
}

UINT
CInstruction::GetNumberOfOperands() const
{
	UINT i=0;
	while ( GetOperandDef(i) != OP_NONE )	{
		ASSERT( OP_UNKNOWN != GetOperandDef(i) );
		i++;
	}
	return i;

}

PCSTR 
CInstruction::GetGeneralRegisterName(int rNum) const
{
	if ( SIZE_32 == GetOperandSizeAttribute() )
		return CReg::Name32(rNum);
	else
		return CReg::Name16(rNum);
}

#ifdef _AFX
CString
CInstruction::GetOperandAddressName	(int opNumber) const
{
	return m_pOperand[opNumber]->GetAddressString();
}
#endif // _AFX

CInstruction::~CInstruction()
{
	Cleanup();
}

#ifdef _AFX
CString
CInstruction::GetCString(void)
{
	CString inst;
	char buf[256];
	
	/*
	0         1         2         3         4         5         6
	0123456789012345678901234567890123456789012345678901234567890
	12345678: x1 x2 x3 x4 x5 x6 x7 x8       CMOVNLE   eax, dword ptr [323322]
	*/
//	sprintf(buf, "%08X: ", (DWORD)m_pBase);
//	for (UINT i=0;i<m_cbInstr;i++)	{
//		char b[8];
//		sprintf(b, "%02X ", m_instr[i]);
//		strcat(buf, b);
//	}

//	int pos = strlen(buf);
//	char *ch = buf + pos;
	// fill in blanks to 40...
//	while (pos < 40)
//		buf[pos++] = ' ';
	int pos = 0;
	UINT i;
	strcpy(&buf[pos], GetClassName());
	pos = strlen(buf);
	while (pos < 10)
		buf[pos++] = ' ';

	buf[pos] = 0;

	for (i=0;i<GetNumberOfOperands();i++)	{
		strcat((char *)buf, m_pOperand[i]->GetCString());
		strcat((char *)buf, ", ");
	}
	// erase the last ", "
	if ( GetNumberOfOperands() )	{
		pos = strlen(buf);
		buf[pos-2] = 0;
	}
	
	inst = buf;
	return inst;
}
#endif // _AFX

DWORD
CInstruction::GetVirtualAddress(void)
{
	return m_dwVirtualAddress;
}


UINT 
CInstruction::GetInstructionSize(void)
{
	return m_cbInstr;
}

//
// _GetClass() determines the OPCODE_CLASS for this instruction
// by pulling it out of one of the OpcodeMap arrays.  The result of
// this calculation is cached in m_ocDef.cls.
//
OPCODE_CLASS
CInstruction::_GetClass(void) const
{
	OPCODE_CLASS oc = OC_NULL;
	OPCODE_DEF *pOpcodeMap = &OpcodeMap1[0];
	BYTE		byte = m_oc1;
	_ASSERT(m_dwFlags & F_OC1);	// make sure we've read this in

	while (OC_NULL == oc) {

	//
	// If this instruction doesn't have an opcode extension, we'll be able
	// to pull the OPCODE_CLASS right out of either OpcodeMap1 or OpcodeMap2.
	// If, however, it uses ModRM, we'll find it in one of the OpcodeMapModRM
	// arrays.
	//
	switch ( pOpcodeMap[byte].cls )	{
		case OC_MAP_2:
			//
			// This operand's class is defined in the two-byte opcode map
			//
			pOpcodeMap = &OpcodeMap2[0];
			byte = m_oc2;
			_ASSERT(m_dwFlags & F_OC2);	// make sure we've read this in
			break;	// go back to switch on the class in OpcodeMap2
		case OC_MAP_MODRM1:
		case OC_MAP_MODRM2:
		case OC_MAP_MODRM3:
		case OC_MAP_MODRM4:
		case OC_MAP_MODRM5:
		case OC_MAP_MODRM6:
		case OC_MAP_MODRM7:
		case OC_MAP_MODRM8:
		case OC_MAP_MODRM9:
		case OC_MAP_MODRMA:
			//
			// This operand is defined in the opcode-extension map. The statement
			// below just points pOpcodeMap to the appropriate OpcodeMapModRM array.
			//
			pOpcodeMap = &OpcodeMapModRM[ pOpcodeMap[byte].cls - OC_MAP_MODRM0 ][0];
			byte = m_modrm.reg;
			break;	// go back to switch on the class in OpcodeMapModRM
		default:
			//
			// We get to the default case as soon as we find an OPCODE_CLASS that
			// is not OC_MAP_2 or one of the OC_MAP_MODRMx's.
			//
			oc = pOpcodeMap[byte].cls; // gotcha
			break;
		} // switch
	} // while (OP_NULL == oc)

	return oc;
}

// ALERT!!! these guys assume we're in a 32-bit code- and data-segment!
SIZE_ATTRIBUTE
CInstruction::GetAddressSizeAttribute(void) const
{
	if ( hasAddressSizeOverridePrefix() )
		return SIZE_16;
	else
		return SIZE_32;
}

SIZE_ATTRIBUTE
CInstruction::GetOperandSizeAttribute(void) const
{
	if ( hasOperandSizeOverridePrefix() )
		return SIZE_16;
	else
		return SIZE_32;
}

SIZE_ATTRIBUTE
CInstruction::ByteToSizeAttribute(UINT cb) const
{
	switch(cb)	{
	case 0:
		ASSERT(0);
		return SIZE_LAST;
	case 1:
		return SIZE_8;
	case 2:
		return SIZE_16;
	case 3:
		ASSERT(0);
		return SIZE_LAST;
	case 4:
		return SIZE_32;
	default:
		ASSERT(0);
		return SIZE_LAST;
	}
}

BOOL
CInstruction::isJmp(void) const
{
	// conditional jumps have opcodes that are either
	// 1) one-byte opcodes in range [0x70,0x7f], or
	// 2) two-byte opcodes with oc1 == 0x0f and oc2 in range [0x80, 0x8f]
	if	(
		( OC_JMP == m_ocDef.cls ) ||
		( m_oc1 >= 0x70 && m_oc1 <= 0x7f ) ||
		( 0x0f == m_oc1 && m_oc2 >= 0x80 && m_oc2 <= 0x8f )
		)
		return TRUE;
	else
		return FALSE;

}

PCHAR
CInstruction::GetJmpTarget(void) const
{
	ASSERT( isJmp() );

	PCHAR pc=0;
	return pc;
}
#if 0
	if (!isJmp())
		throw XDisException("Instruction isn't JMP!");

	// jmp target is always operand 0

	if ( m_oc1 >= 0x70 && m_oc1 <= 0x7f )	{
		// short-displacement jumps
		CDisplacement disp;
		GetDisplacement(disp);
		ASSERT( SIZE_8 == disp.GetSize() );
		disp.SetSigned(TRUE);
		disp.SetSize( SIZE_32 );	// sign-extend to 32 bits
		pc = GetBaseAddress() + GetInstructionSize() + disp.GetValue();
	} else if ( 0x0f == m_oc1 && m_oc2 >= 0x80 && m_oc2 <= 0x8f )	{
		// long-displacement jumps
		CDisplacement disp;
		GetDisplacement(disp);
		ASSERT( GetAddressSizeAttribute() == disp.GetSize() ); // default size
		disp.SetSigned(TRUE);
		disp.SetSize( SIZE_32 );	// sign-extend to 32 bits
		pc = GetBaseAddress() + GetInstructionSize() + disp.GetValue();
	}

#endif

#ifdef _AFX
CString
CInstruction::GetCStringNoCodeBytes(void)
{
	CString inst;
	char buf[256];
	
	/*
	0         1         2         3         4         5         6
	0123456789012345678901234567890123456789012345678901234567890
	12345678: CMOVNLE   eax, dword ptr [323322]
	*/
	sprintf(buf, "%08X: ", (DWORD) GetVirtualAddress() );
	strcpy(&buf[10], GetClassName());
	int pos = strlen(buf);
	while (pos < 20)
		buf[pos++] = ' ';

	buf[pos] = 0;
	for (UINT i=0;i<GetNumberOfOperands();i++)	{
		strcat((char *)buf, m_pOperand[i]->GetCString());
		strcat((char *)buf, ", ");
	}
	// erase the last ", "
	if ( GetNumberOfOperands() )	{
		pos = strlen(buf);
		buf[pos-2] = 0;
	}
	
	inst = buf;
	return inst;
}
#endif // _AFX

//#if USE_COM_INTERFACE
STDMETHODIMP
CInstruction::GetINSTRUCTION(INSTRUCTION *pInst)
{
	ASSERT( pInst );

	pInst->op[0].cls = OPERAND_CLASS_NONE;
	pInst->op[1].cls = OPERAND_CLASS_NONE;
	pInst->op[2].cls = OPERAND_CLASS_NONE;

	strncpy((char *)&pInst->AnsiName, (PCSTR)GetClassName(), 16);
	pInst->dwLen = GetInstructionSize();
	memcpy(pInst->bytes, m_pBase, GetInstructionSize());
	pInst->cOperands = GetNumberOfOperands();
	pInst->hoc = (HOPCODE_CLASS) GetClass();
	pInst->dwVirtualAddress = GetVirtualAddress();

	switch (GetNumberOfOperands())	{
	case 3:
		m_pOperand[2]->GetOPERAND(&pInst->op[2]);
		// fall through
	case 2:
		m_pOperand[1]->GetOPERAND(&pInst->op[1]);
		// fall through
	case 1:
		m_pOperand[0]->GetOPERAND(&pInst->op[0]);
		// fall through
	case 0:
		break;
	default:
		ASSERT(0);
		;
	} // switch

	return S_OK;
}
//#endif // USE_COM_INTERFACE

UINT CInstruction::_ReadDirect(PBYTE pCode)
{
	//
	// although i'm quite sure only two instructions use ADDR_DIRECT,
	// and the operand that uses it is always the first (and only),
	// i want to make sure this works for a while...
	//
	for (int i=0;i<3;i++)	{
		switch ( OPERAND_ADDRESSING(m_ocDef.op(i)) )	{
		case ADDR_DIRECT:
			if ( GetAddressSizeAttribute() == SIZE_16 )	{
				// 16:16 direct address
				m_dwDirect32 = *(DWORD *)pCode;
				m_dwFlags |= F_DIR32;
				return 4;
			} else {
				// 16:32 direct address
				ASSERT(GetAddressSizeAttribute() == SIZE_32 );
				m_twDirect48.wHi = *(WORD *)pCode;
				m_twDirect48.dwLo = *(DWORD *)(pCode + 2);
				m_dwFlags |= F_DIR48;
				return 6;
			}
		default:
			break;
		}
	}
	
	return 0;

}
