#ifndef _CINSTRUCTION_H
#define _CINSTRUCTION_H

#define MAX_INSTRUCTION_LEN	16	// Intel defined maximum instruction length

// with the MS compiler:
// the ordering of data declared as bit fields is from low to high bit
typedef union {
	BYTE	modRM;
	struct {
		UINT	rm	:	3;	// reg or memory
		UINT	reg	:	3;	// reg or opcode extension
		UINT	mod	:	2;
	};
} MODRM, *PMODRM;

typedef	union {
	BYTE	sib;		// SIB byte
	struct {
		UINT	base : 3;
		UINT	index: 3;
		UINT	ss	 : 2;
	};
} SIB, *PSIB;

//
// Flags for the m_dwFlags member of CInstruction.  These flags
// tell which instruction fields contain valid values.
//
#define F_LOCKORREPEAT_P	0x1		// m_instrPrefix is present and valid
#define F_ADDR_SIZE_OP		0x2		// m_addrSizePrefix is present and valid
#define F_OP_SIZE_OP		0x4		// m_opSizePrefix
#define F_SEG_OP			0x8		// m_segOverride
#define F_OC1				0x10	// should always be set
#define F_OC2				0x20	// m_oc2
#define F_MODRM				0x40	// m_modrm
#define F_SIB				0x80	// m_sib
#define F_DISP				0x100	// m_dwDisp
#define F_IMM				0x200	// m_dwImm
#define F_DIR32				0x400	// m_dwDirect32
#define F_DIR48				0x800	// m_twDirect48

#define F_LEADER			0x1000	// instruction is the leader of a basic block


class COperand;
class CImmediate;
class CDisplacement;

class CInstruction : public IDisInstruction, public CUnknown
{
public:
	DECLARE_IUNKNOWN
	STDMETHOD(NondelegatingQueryInterface)(const IID& iid, void ** ppv)
	{
		if (iid == IID_IDisInstruction)	{
			return FinishQI(static_cast<IDisInstruction *>(this), ppv);
		} else {
			return CUnknown::NondelegatingQueryInterface(iid, ppv);
		}
	}

	//
	// IDisInstruction
	//
	STDMETHOD(GetINSTRUCTION)(INSTRUCTION *pInst);
	STDMETHOD(GetAnsiClassName)(unsigned char *pName, ULONG ulLen)
	{ strncpy((char *)pName, GetClassName(), ulLen); return S_OK; }


private:
	//
	// There is a lot of waste in this class that will want to be 
	// pinched when everything is working well.  Most of these fields
	// can be collapsed into 4-bits (offsets into m_instr)
	//
	PBYTE m_pBase;
	DWORD	m_dwVirtualAddress;
	OPCODE_DEF		m_ocDef;

	// An instruction can be at most 16 (MAX_INSTRUCTION_LEN) bytes; 
	BYTE	m_instr[MAX_INSTRUCTION_LEN];	// bytes making up instruction
	UINT	m_cbInstr;		// number of bytes in instruction

	BYTE	m_lockOrRepeatP;	// lock or repeat prefix
	BYTE	m_addrSizeOP;		// address-size override prefix
	BYTE	m_opSizeOP;			// operand-size override prefix
	BYTE	m_segOP;			// segment override prefix

	BYTE	m_oc1;		// opcode byte 1
	BYTE	m_oc2;		// opcode byte 2 (if m_oc1==0x0f)
	MODRM	m_modrm;	// ModR/M byte
	SIB		m_sib;		// SIB byte
	
	BYTE	m_displacement[4];	// (signed) displacement.
	UINT	m_cbDisp;			// number of bytes in displacement
	BYTE	m_immediate[4];		// unsigned immediate
	UINT	m_cbImm;			// number of bytes in displacement

	union {
		DWORD	m_dwDirect32;	// 16:16 ptr
		TWORD	m_twDirect48;	// 16:32 ptr
	};

	DWORD	m_dwFlags;	// use flags.  See notes above.

	COperand *m_pOperand[3];
public:
	UINT GetInstructionSize(void);
	DWORD GetVirtualAddress(void);

#ifdef _AFX
	CString GetCString(void);
	CString GetCStringNoCodeBytes(void);
#endif

	~CInstruction();

	PCSTR	GetGeneralRegisterName(int rNum) const;
	UINT  GetNumberOfOperands() const;
	CInstruction();
	// Access to instruction prefixes.
	// These functions throw a CDisException if the requested prefix
	// is not present in the instruction.
	BYTE	GetSegmentOverridePrefix	(void) const;
	BYTE	GetLockOrRepeatPrefix		(void) const;
	BYTE	GetOperandSizeOverridePrefix(void) const;
	BYTE	GetAddressSizeOverridePrefix(void) const;

	// Access to other instruction fields
	BYTE	GetOpcode1		(void) const;
	BYTE	GetOpcode2		(void) const;
	UINT	GetOpcodeSize(void) const { return BITTEST(m_dwFlags, F_OC2)?2:1; }

	MODRM	GetModRM		(void) const;
	SIB		GetSIB			(void) const;

	//DWORD	GetDisplacement		(void) const;
	CDisplacement&	GetDisplacement		(CDisplacement &disp, BOOL bSigned) const;
	UINT			GetDisplacementSize	(void) const { return m_cbDisp; }
	SIZE_ATTRIBUTE	GetDisplacementSizeAttribute(void) const
		{ return ByteToSizeAttribute( GetDisplacementSize() ); }

	//DWORD	GetImmediate	(void) const;
	CImmediate&		GetImmediate	(CImmediate &imm, BOOL bSigned) const;
	CImmediate&		GetImmediateAsAddressOffset	(CImmediate &imm, BOOL bSigned) const;
	UINT			GetImmediateSize(void) const { return m_cbImm; }
	SIZE_ATTRIBUTE	GetImmediateSizeAttribute(void) const
		{ return ByteToSizeAttribute( GetImmediateSize() ); }

	DWORD	GetDirect32(void) const;
	TWORD	GetDirect48(void) const;

	SIZE_ATTRIBUTE	ByteToSizeAttribute(UINT cb) const;

	
	SIZE_ATTRIBUTE	GetAddressSizeAttribute(void) const;
	SIZE_ATTRIBUTE	GetOperandSizeAttribute(void) const;

	UINT	GetOperandTypeSizeBytes( OPDEF operand );	// in bytes
private:
	BOOL	_OperandUsesModRM(int i);
	BOOL	_InstructionUsesModRM(void);
	BOOL	_InstructionUsesSIB(void);

	UINT	_GetDisplacementSize(void);
	UINT	_GetImmediateSize(void);

	BOOL	_ReadPrefix		(BYTE b);
	int		_ReadOpcode		(PBYTE pCode);
	void	_BuildOpcodeDef	(void);
	OPCODE_CLASS	_GetClass		(void) const;
	BOOL	_ReadModRM		(BYTE b);
	BOOL	_ReadSIB		(BYTE b);
	int		_ReadDisplacement(PBYTE pCode);
	int		_ReadImmediate	(PBYTE pCode);

	// returns the operand def for the given operand
	OPDEF	GetOperandDef(int i) const;

	void	Clear(void);
	void	Cleanup(void);
public:
	PCSTR	GetClassName			(void) const;
	OPCODE_CLASS	GetClass		(void) const
		{ return m_ocDef.cls; }
#ifdef _AFX
	CString	GetOperandAddressName	(int opNumber) const;
#endif // _AFX
	BOOL	isValid					(void) const { return TRUE; }

	UINT	Dis(PBYTE pCode, DWORD dwDisplayAddress = -1);

	BOOL	hasOpcodeExtension(void) const;
	BOOL	hasLockOrRepeatPrefix(void)	const
		{ return BITTEST(m_dwFlags, F_LOCKORREPEAT_P); }
	BOOL	hasSegmentOverridePrefix(void) const
		{ return BITTEST(m_dwFlags, F_SEG_OP);}
	BOOL	hasOperandSizeOverridePrefix(void) const
		{ return BITTEST(m_dwFlags, F_OP_SIZE_OP); }
	BOOL	hasAddressSizeOverridePrefix(void) const
		{ return BITTEST(m_dwFlags, F_ADDR_SIZE_OP); }
	
	BOOL	hasModRM(void) const	
		{ return BITTEST(m_dwFlags,F_MODRM); }
	BOOL	hasSIB(void) const		
		{ return BITTEST(m_dwFlags,F_SIB); }

	BOOL	hasDisplacement(void) const
		{ return BITTEST(m_dwFlags, F_DISP); }
	BOOL	hasImmediate(void) const
		{ return BITTEST(m_dwFlags, F_IMM); }

	BOOL	hasDirect32(void) const
		{ return BITTEST(m_dwFlags, F_DIR32); }
	BOOL	hasDirect48(void) const
		{ return BITTEST(m_dwFlags, F_DIR48); }
	void Dump(void);

	// returns TRUE if instruction is a conditional or unconditional jump
	BOOL	isJmp(void) const;

	PCHAR	GetJmpTarget(void) const;

	// returns TRUE if the instruction is the leader of a basic block
	BOOL	isBasicBlockLeader(void) const
		{ return BITTEST(m_dwFlags, F_LEADER); }

	void	SetBasicBlockLeader(void)
		{ m_dwFlags |= F_LEADER; }

protected:
	UINT _ReadDirect(PBYTE pCode);

};

#endif // _CINSTRUCTION_H