#include "project.h"
#include "CCfg.h"
#include <wchar.h>	// swprintf

#include "CBasicBlock.h"
#include "CProcedure.h"
#include "CExpression.h"

QUICK_ALLOCATOR BasicBlockAllocator;

//BB_LIST *bbListHead=NULL;
int bbCount=0;	// number of basic blocks
int ProcCount=0;

// BUGBUG:Try not to use this guy...
int
GetStackAdjustment(INSTRUCTION &inst);

STDMETHODIMP
GetCtrlFlow(INSTRUCTION& inst, CTRL_FLOW *Flow);
STDMETHODIMP
GenerateStatement(INSTRUCTION& inst, STATEMENT *Statement);
STDMETHODIMP
TranslateREGToREGUSE( REG& Reg, REGUSE *RegUse );

CCfg::CCfg()
{
#ifdef USE_TREE
	InitializeAVLTree(&m_BasicBlockTree);
#else
	InitializeListHead(&m_BasicBlockList);
#endif
	InitializeListHead(&m_ProcedureList);

	InitializeQuickAllocator(&BasicBlockAllocator, sizeof(CBasicBlock), 0x2000, 0x400);
}
CCfg::~CCfg()
{
#ifdef USE_TREE
	// we don't currently have any way to remove the entries from
	// the tree...
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList.Flink) {
        CBasicBlock *Block = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = Block->ListEntry.Flink;
		RemoveEntryList(&Block->ListEntry);
		//QuickRelease(Block);
    }

    Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList.Flink) {
        CProcedure *Proc = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Proc->ListEntry.Flink;
		RemoveEntryList(&Proc->ListEntry);
		delete Proc;
    }
#endif
	ReleaseQuickAllocator(&BasicBlockAllocator);
}

STDMETHODIMP
CCfg::Attach(IDisLdr *pILdr, IDisDis *pIDis, IDisSymMgr *pISym)
{
	m_pILdr = pILdr;
	m_pIDis = pIDis;
	m_pISym = pISym;
	return S_OK;
}

#if 0
void
CCfg::ForEachBasicBlock( BOOL(CCfg::*pFunc)(CBasicBlock *BasicBlock, DWORD Context), DWORD Context )
{
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		if (!(*pFunc)(BasicBlock, Context))
			return;
    }
	return NULL;
}
#endif

STDMETHODIMP
CCfg::Parse(DWORD Address)
{
	ParseBlock(NULL /*Proc */, Address);
	return S_OK;
}

STDMETHODIMP
CCfg::Clear()
{
#ifdef USE_TREE
	InitializeAVLTree(&m_BasicBlockTree);
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		RemoveEntryList(&BasicBlock->ListEntry);
	//	delete BasicBlock;
    }

    Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList.Flink) {
        CProcedure *Proc = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Proc->ListEntry.Flink;
		RemoveEntryList(&Proc->ListEntry);
		delete Proc;
    }
#endif
	ReleaseQuickAllocator(&BasicBlockAllocator);
	InitializeQuickAllocator(&BasicBlockAllocator, sizeof(CBasicBlock), 0x2000, 0x400);

	return NULL;
}

CBasicBlock *
CCfg::FindBasicBlock(DWORD Address)
{
#ifdef USE_TREE
	TREE_ENTRY *TreeEntry = FindTreeEntry(&m_BasicBlockTree, Address);
	if (!TreeEntry)
		return NULL;

	CBasicBlock *BasicBlock = CONTAINING_RECORD( TreeEntry, CBasicBlock, TreeEntry );
	return BasicBlock;
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		if (BasicBlock->Address() == Address)
			return BasicBlock;
    }
	return NULL;
#endif

}

CBasicBlock *
CCfg::FindContainingBasicBlock(DWORD Address)
{
#ifdef USE_TREE
	TREE_ENTRY *TreeEntry = FindTreeEntryEx(&m_BasicBlockTree, Address, SEARCH_LOWER_OR_EQUAL);
	if (!TreeEntry)
		return NULL;
	CBasicBlock *BasicBlock = CONTAINING_RECORD( TreeEntry, CBasicBlock, TreeEntry );
	if (BasicBlock->Contains(Address) 
#if 1 
		// this is for the case where a bad basic block is still in the tree
		|| BasicBlock->Address() == Address
#endif
		)
		return BasicBlock;
	return NULL;
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		if (BasicBlock->Contains(Address))
			return BasicBlock;
		if (BasicBlock->Address() > Address)
			return NULL;
    }
	return NULL;
#endif
}

DWORD
CCfg::FindNextBasicBlockAddress(DWORD Address)
{
#ifdef USE_TREE
	TREE_ENTRY *TreeEntry = FindTreeEntryEx(&m_BasicBlockTree, Address, SEARCH_GREATER);
	if (!TreeEntry)
		return NULL;
	CBasicBlock *BasicBlock = CONTAINING_RECORD( TreeEntry, CBasicBlock, TreeEntry );
	_ASSERT(BasicBlock->Address() > Address);	// must be strictly greater than
	return BasicBlock->Address();
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		if (BasicBlock->Address() > Address)
			return BasicBlock->Address();
    }
	return 0;
#endif
}



CBasicBlock *
CCfg::InsertBasicBlock(DWORD Address, BOOL Allocate, CBasicBlock *cbb)
{
#ifndef USE_TREE
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
		if (BasicBlock->Address() > Address)
			break;
        Next = BasicBlock->ListEntry.Flink;
    }
#endif
	CBasicBlock *NewBlock;
	if ( Allocate )	{
		CBasicBlock *blk = (CBasicBlock *)QuickAllocate(&BasicBlockAllocator);
		NewBlock = new (blk) CBasicBlock( Address );
	}
	else
		NewBlock = cbb;

#ifdef USE_TREE
	BOOL rc = InsertTreeEntry(&m_BasicBlockTree, &NewBlock->TreeEntry);
	_ASSERT(rc == TRUE);	// conflicting basic blocks!!
#else
	NewBlock->ListEntry.Flink = Next;
	NewBlock->ListEntry.Blink = Next->Blink;
	Next->Blink->Flink = &NewBlock->ListEntry;
	Next->Blink = &NewBlock->ListEntry;
#endif
	bbCount++;
	return NewBlock;
}

CBasicBlock *
CCfg::AllocateBasicBlock(DWORD Address)
{
#if GO_REALLY_SLOW
	_ASSERT( FindBasicBlock(Address) == NULL );
#endif
	return InsertBasicBlock(Address, TRUE, NULL);
}

void
CCfg::DeallocateBasicBlock(CBasicBlock *Block)
{
#ifdef USE_TREE
//	_ASSERT( FindTreeEntry(&m_BasicBlockTree, Block->Address()) == NULL );	// can't delete a block already in the tree
#else
	RemoveEntryList(&Block->ListEntry);
#endif
	Block->~CBasicBlock();
	//QuickRelease(Block);
	bbCount--;
}



CProcedure *
CCfg::FindProcedure(DWORD Address)
{
    PLIST_ENTRY Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList) {
        CProcedure *Procedure = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Procedure->ListEntry.Flink;
		if (Procedure->Address() == Address)
			return Procedure;
    }
	return NULL;

}

CProcedure *
CCfg::FindContainingProcedure(DWORD Address)
{
    PLIST_ENTRY Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList) {
        CProcedure *Procedure = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Procedure->ListEntry.Flink;
		if (Procedure->Contains(Address))
			return Procedure;
		if (Procedure->Address() > Address)
			return NULL;
    }
	return NULL;
}

DWORD
CCfg::FindNextProcedureAddress(DWORD Address)
{
    PLIST_ENTRY Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList) {
        CProcedure *Procedure = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Procedure->ListEntry.Flink;
		if (Procedure->Address() > Address)
			return Procedure->Address();
    }
	return 0;
}

CProcedure *
CCfg::InsertProcedure(DWORD Address, OLECHAR *Name, BOOL Allocate, CProcedure *cbb)
{
    PLIST_ENTRY Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList) {
        CProcedure *Procedure = CONTAINING_RECORD( Next, CProcedure, ListEntry );
		if (Procedure->Address() > Address)
			break;
        Next = Procedure->ListEntry.Flink;
    }
	
	CProcedure *NewProc;
	if ( Allocate )
		NewProc = new CProcedure( Address, Name );
	else
		NewProc = cbb;

	NewProc->ListEntry.Flink = Next;
	NewProc->ListEntry.Blink = Next->Blink;
	Next->Blink->Flink = &NewProc->ListEntry;
	Next->Blink = &NewProc->ListEntry;

	ProcCount++;
	return NewProc;
}

CProcedure *
CCfg::AllocateProcedure(DWORD Address, OLECHAR *Name)
{
#if GO_REALLY_SLOW
	_ASSERT( FindProcedure(Address) == NULL );
#endif
	return InsertProcedure(Address, Name, TRUE, NULL);
}

void
DeallocateProcedure(CProcedure *Proc)
{
	RemoveEntryList(&Proc->ListEntry);
	delete Proc;
	ProcCount--;
}






#define IS_BINARY_OP( Op )  ( (Op) > OP_BEGIN_BINARY && (Op) << OP_END_BINARY )
#define IS_UNARY_OP( Op )	( (Op) > OP_BEGIN_UNARY && (Op) << OP_END_UNARY )
#define IS_COPY_OP( Op )	( (Op) == OP_COPY )

#define IS_REGISTER( Operand )	( Operand .cls == OPERAND_CLASS_REG )

//
// GetRegsUsed() fills a passed in array with the REG values of 
// any registers USED (as opposed to DEFINED) by this instruction.
// Eventually, we can devise some way to enable the use of a bitmask
// to reduce the overhead.
//
// NumberOfRegs must be set to 3
//
STDMETHODIMP
GetRegsUsed(QUAD &Quad, REGUSE *Regs, int *NumberOfRegs)
{
	_ASSERT( *NumberOfRegs == 3 );

	switch (Quad.Type)	{
	case STATEMENT_TYPE_ASSIGNMENT:
		{
			OPERATION& Operation = Quad.Assignment.Operation;

			if ( IS_BINARY_OP( Operation ) )	{
				if ( IS_REGISTER( Quad.Assignment.Source[0] ) )
					TranslateREGToREGUSE( Quad.Assignment.Source[0].reg, Regs++ );
				if ( IS_REGISTER( Quad.Assignment.Source[1] ) )
					TranslateREGToREGUSE( Quad.Assignment.Source[1].reg, Regs++ );
			} else if ( IS_UNARY_OP( Operation ) || IS_COPY_OP( Operation ) )	{
				if ( IS_REGISTER( Quad.Assignment.Source[0] ) )
					TranslateREGToREGUSE( Quad.Assignment.Source[0].reg, Regs++ );
			} else {
				_ASSERT(0);	// invalid operation
			}
		}
		break;
	case STATEMENT_TYPE_CTRL:

	case STATEMENT_TYPE_COMPOUND:
		return E_FAIL;	// can't get regs used by compound statement

	default:
		_ASSERT(0);
	}

	return S_OK;
}

//++
//
// We assume that Block has alread been parsed completely.
//
//--
BOOL
CCfg::AddAllBasicBlocksToProc( CProcedure *Proc, CBasicBlock *Block )
{
	_ASSERT(Proc != NULL);
	_ASSERT(Block != NULL);

	DWORD Address = Block->Address();
	while (Block)	{
		if (!Proc->AddBasicBlock( Block ))
			return TRUE;	// already parsed

		CTRL_FLOW CtrlFlow;
		CtrlFlow = Block->m_bb.Flow;
		switch( CtrlFlow.Type )	{
			case CTRL_UJMP:
				Address = CtrlFlow.ujmp.Target;
				break;
			case CTRL_IJMP:
				Address = 0;	// end
				break;
			case CTRL_CJMP:
				Block = FindBasicBlock( CtrlFlow.cjmp.TrueTarget );
				if (Block)
					AddAllBasicBlocksToProc( Proc, Block );
				Address = CtrlFlow.cjmp.FalseTarget;
				break;
			case CTRL_CALL:
				Block = FindBasicBlock( CtrlFlow.call.CallTarget );
				if (Block)
					AddAllBasicBlocksToProc( Proc, Block );
				Address = CtrlFlow.call.FallTarget;
				break;
			case CTRL_RET:
				Address = 0;	// end
				break;
			case CTRL_FALL:
				Address = CtrlFlow.fall.FallTarget;
				break;
			default:
				_ASSERT(0);
		}
		Block = FindBasicBlock( Address );
	}
	return TRUE;
}

//++
// CBasicBlock *
// CCfg::ParseBlock(DWORD Address, IDisImg *Image)
//
// Parameters:
//	Address - The Virtual Address to parse.
//
// Returns:
//		a pointer to a CBasicBlock object beginning at Address
//
// Notes:
//		This function parses the basic block at Address and all
//		edges out of the basic block.
//--
CBasicBlock *
CCfg::ParseBlock(CProcedure *Proc, DWORD Address)
{
	CBasicBlock *Return = NULL;
	CBasicBlock *Block;

	//
	// Parse Loop.  Follow the flow of the code depth first, 
	// recursively calling this function when a conditional branch 
	// is encountered.
	//
	BOOL ContinueParse = TRUE;
	BOOL BeginNewBasicBlock = TRUE;
	DWORD AddressOfNextBlock;
	while (ContinueParse) {
		BOOL FoundAlreadyParsedBlock = FALSE;
		BOOL AddReferenceToNextBlock = FALSE;
		CTRL_FLOW_TYPE SavedCtrlFlowType;
		DWORD SavedAddress = 0;

		if (!Address)
			return Return;

		if ( BeginNewBasicBlock )	{
			//
			// We're starting a new basic block.  Make sure this hasn't
			// already been parsed.
			//
			Block = FindContainingBasicBlock(Address);
			if (Block)	{
				//
				// If address has already been parsed as leader, return the
				// existing block
				//
				if ( Block->Address() == Address )	{
					FoundAlreadyParsedBlock = TRUE;
				} else {
					//
					// Otherwise, this address was parsed in the middle of another
					// basic block.  Split the basic block and return
					// the new block which begins at this address.
					//
					Block = Block->Split( AllocateBasicBlock( Address ) );
#ifdef VERIFY_TREE
					_ASSERT( FindTreeEntryEx(&m_BasicBlockTree, Address, SEARCH_LOWER_OR_EQUAL ) == &Block->TreeEntry );
#endif
					FoundAlreadyParsedBlock = TRUE;
				}
			} else {
				//
				// This address hasn't already been parsed.  Allocate the block
				// and find the next block address in case we fall through.
				//
				Block = AllocateBasicBlock( Address );
#ifdef VERIFY_TREE
					_ASSERT( FindTreeEntryEx(&m_BasicBlockTree, Address, SEARCH_LOWER_OR_EQUAL ) == &Block->TreeEntry );
#endif
				AddressOfNextBlock = FindNextBasicBlockAddress( Address );
			}

			//
			// We return a pointer to the first basic block parsed, so save
			// it off the first time.
			//
			if (!Return)
				Return = Block;

			//
			// We avoid having to recurse on UJMPs by setting AddJumpReferenceToNextBlock
			// 
			if ( AddReferenceToNextBlock )	{
				_ASSERT(0 != SavedAddress);
				Block->AddReference( SavedCtrlFlowType, SavedAddress );
				AddReferenceToNextBlock = FALSE;
			}

			if ( FoundAlreadyParsedBlock )	{
				if ( Proc )
					AddAllBasicBlocksToProc( Proc, Block );
				break;	// return
			}
			
			if ( Proc )
				Proc->AddBasicBlock( Block );

		} else {
			//
			// We're continuing with the same basic block as before.
			// Make sure we haven't fallen through to the next block.
			//
			if ( AddressOfNextBlock && Address >= AddressOfNextBlock )	{
				//
				// If we have fallen into another basic block, close off this one.
				//
			
				// BUGBUG: There is the potential here that the last instruction
				// of the basic block we are currently parsing actually runs into
				// the first byte(s) of the next basic block.  This would cause a
				// situation whereby (basic block address) + (basic block size)
				// would actually be in the middle of the next basic block.  Chances
				// are that this would only happen in situations where we mistakenly
				// parsed data as code.
				//
				// Instead of having this problem, we set up the current basic
				// block to fall through to the next basic block, as opposed to
				// somewhere in the middle of it.  This could cause problems if
				// someone assumes the basic block size is exactly the number
				// of bytes required to correctly disassemble the block, but it
				// appears to be the best solution.
				//
				CTRL_FLOW Flow;
				Flow.Type = CTRL_FALL;
				Flow.fall.FallTarget = AddressOfNextBlock;	// NOT Address
				Block->ParseComplete( AddressOfNextBlock, Flow );	// NOT Address
				_ASSERT( Return != NULL );
				return Return;	// Return is always non-NULL
			}
		}

		//
		// Get a dereferencable pointer and disassemble the instruction
		//
		DWORD Ptr;
		INSTRUCTION inst;
		if ( FAILED(m_pILdr->ConvertVirtualAddressToPtr(Address, &Ptr)) ||
			 FAILED(m_pIDis->Disasm(Ptr, Address, &inst)) )	
		{
			if ( Address == Block->Address() )	{	// this block is worthless
				if (Return == Block)
					Return = NULL;
				DeallocateBasicBlock(Block);
				return Return;
			} else {
				// we can't just throw this block away, because we may have
				// already parsed successor nodes; they might have references
				// to this block
				Block->ParseFailed( Address );
				_ASSERT( Return != NULL );
				return Return;
			}
		}

		//
		// BUGBUG: There should really be another check here to make
		// sure that this instruction doesn't run into the beginning
		// of the next basic block.

		//
		// Account for movement of the stack
		//
		Block->AdjustStack( GetStackAdjustment(inst) );

		//
		// Choose our next move based on control flow type
		//
		CBasicBlock *TargetBlock;
		CProcedure *TargetProc;
		CTRL_FLOW CtrlFlow;
		GetCtrlFlow(inst, &CtrlFlow);
		switch(CtrlFlow.Type)	{
		case CTRL_UJMP:
			//
			// Unconditional Jump: This block is done, so loop
			// back and parse the target.
			//
			Block->ParseComplete( Address + inst.dwLen, CtrlFlow );
			Address = CtrlFlow.ujmp.Target;
			ContinueParse = TRUE;
			BeginNewBasicBlock = TRUE;
			SavedAddress = Address;
			SavedCtrlFlowType = CTRL_UJMP;
			break;
		case CTRL_IJMP:
			//
			// Indexed Jump: We don't know how to follow this yet
			//
			Block->ParseFailed( Address + inst.dwLen );
			ContinueParse = FALSE;
			break;
		case CTRL_CJMP:
			//
			// Conditional Jump: Recurse to parse the TrueTarget,
			// then loop back and parse the FalseTarget.
			//
			Block->ParseComplete( Address + inst.dwLen, CtrlFlow );
			TargetBlock = ParseBlock( Proc, CtrlFlow.cjmp.TrueTarget );
			if (TargetBlock)
				TargetBlock->AddReference( CTRL_CJMP, Address );
			Address = CtrlFlow.cjmp.FalseTarget;
			ContinueParse = TRUE;
			BeginNewBasicBlock = TRUE;
			break;
		case CTRL_CALL:
			//
			// Call: Recurse to parse the CallTarget, then loop
			// back and parse the FallTarget.
			//
			Block->ParseComplete( Address + inst.dwLen, CtrlFlow );
			//TargetBlock = ParseBlock( CtrlFlow.call.CallTarget );
			TargetProc = ParseProcedure( CtrlFlow.call.CallTarget );
			if (TargetProc)	{
				// BUGBUG: Later
				//	TargetProc->AddEdgeIn( Address );

				TargetBlock = FindBasicBlock( TargetProc->Address() );
				if (TargetBlock)	{
					TargetBlock->AddReference( CTRL_CALL, Address );
				}
			}
			Address = CtrlFlow.call.FallTarget;
			ContinueParse = TRUE;
			BeginNewBasicBlock = TRUE;
			break;
		case CTRL_RET:
			//
			// Return: We're outta here!
			//
			Block->ParseComplete( Address + inst.dwLen, CtrlFlow );
			ContinueParse = FALSE;
			break;
		case CTRL_FALL:
			//
			// Fall: Just keep going on this basic block.
			//
			Address = CtrlFlow.fall.FallTarget;
			ContinueParse = TRUE;
			BeginNewBasicBlock = FALSE;
			break;
		}

	} // while (ContinueParse)

	return Return;	// return the first basic block parsed
}

#if 0
STDMETHODIMP
CCfg::ProcessCrossRefs()
{
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
		switch(BasicBlock->CtrlFlowType())	{
		case CTRL_CJMP:
			TargetBlock1 = FindBasicBlock( BasicBlock->m_bb.cjmp.TrueTarget );
			TargetBlock2 = FindBasicBlock( BasicBlock->m_bb.cjmp.FalseTarget );
		case CTRL_UJMP:
		case CTRL_IJMP:
		case CTRL_CALL:
		case CTRL_RET:

		}
        Next = BasicBlock->ListEntry.Flink;
    }
	return S_OK;
}
#endif // if 0
STDMETHODIMP
CCfg::EnumBasicBlocks(IDisEnumBASIC_BLOCK ** ppEnum)
{
	typedef CComEnum<IDisEnumBASIC_BLOCK, &IID_IDisEnumBASIC_BLOCK, BASIC_BLOCK, _Copy<BASIC_BLOCK> > CEnumBASIC_BLOCKs;	
#ifdef USE_TREE
	BASIC_BLOCK *Blocks = new BASIC_BLOCK [m_BasicBlockTree.Count];
#else
	BASIC_BLOCK *Blocks = new BASIC_BLOCK [bbCount];
#endif

#ifdef USE_TREE
	int i=0;
	TREE_ENTRY *TreeEntry = FindFirstTreeEntry(&m_BasicBlockTree);
	while (TreeEntry)	{
        CBasicBlock *BasicBlock = CONTAINING_RECORD( TreeEntry, CBasicBlock, TreeEntry);
		Blocks[i++] = BasicBlock->m_bb;	// struct copy
		TreeEntry = FindNextTreeEntry(TreeEntry);
	}
#else
	int i=0;
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
        Next = BasicBlock->ListEntry.Flink;
		Blocks[i++] = BasicBlock->m_bb;	// struct copy
    }
#endif
	CComObject<CEnumBASIC_BLOCKs> *Enum = new CComObject<CEnumBASIC_BLOCKs>;
	Enum->Init(&Blocks[0], &Blocks[i], NULL, AtlFlagTakeOwnership);
	HRESULT hr = Enum->_InternalQueryInterface(IID_IDisEnumBASIC_BLOCK, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

STDMETHODIMP
CCfg::GetNextBasicBlock(DWORD Address, BASIC_BLOCK *BasicBlock)
{
	CBasicBlock *Block = FindBasicBlock( Address );
	if (!Block)	{
		Address = FindNextBasicBlockAddress( Address );
		Block = FindBasicBlock( Address );
	}

	if (Block)	{
		*BasicBlock = Block->m_bb;	// struct copy
		return S_OK;
	} else {
		return E_FAIL;
	}

}

#if 0
STDMETHODIMP
CCfg::EnumProcedures(IDisEnumPROCEDURE ** ppEnum)
{
	typedef CComEnum<IDisEnumPROCEDURE, &IID_IDisEnumPROCEDURE, PROCEDURE, _Copy<PROCEDURE> > CEnumPROCEDUREs;	
	PROCEDURE *Procs = new PROCEDURE [ProcCount];

	int i=0;
    PLIST_ENTRY Next = m_ProcedureList.Flink;
    while ((ULONG)Next != (ULONG)&m_ProcedureList) {
        CProcedure *Procedure = CONTAINING_RECORD( Next, CProcedure, ListEntry );
        Next = Procedure->ListEntry.Flink;
		Procs[i++] = Procedure->m_proc;	// struct copy BUGBUG
    }
	CComObject<CEnumPROCEDUREs> *Enum = new CComObject<CEnumPROCEDUREs>;
	Enum->Init(&Procs[0], &Procs[ProcCount], NULL, AtlFlagTakeOwnership);
	HRESULT hr = Enum->_InternalQueryInterface(IID_IDisEnumPROCEDURE, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}
#endif // if 0
CProcedure *
CCfg::ParseProcedure(DWORD Address, OLECHAR *Name /* = NULL */)
{
	if (!Address)
		return NULL;
	CProcedure *Proc = FindProcedure( Address );
	if ( Proc )	{
		return Proc;
	}
	Proc = AllocateProcedure( Address, Name );
	ParseBlock(Proc, Address);
	Proc->EndParse();
	return Proc;
}

STDMETHODIMP
CCfg::ParseProcedure(DWORD Address, PROCEDURE *Procedure)
{
	CProcedure *Proc = FindProcedure( Address );
	if (!Proc)	{
		ParseProcedure( Address );
		Proc = FindProcedure( Address );
		_ASSERT(Proc);
	}

	Proc->AllocateProcedure(Procedure);

	return S_OK;
}

STDMETHODIMP
CCfg::DestroyProcedure(PROCEDURE *Procedure)
{
	CProcedure::DestroyProcedure(Procedure);
	return S_OK;
}

#if 0
//++
//
// Proc - a CProcedure object that is assumed to have been
// set up with an Address and size.
//--
STDMETHODIMP
CCfg::I_ParseFunc(CProcedure *Proc, DWORD Address)
{
	CBasicBlock *Block = FindBasicBlock( Address );
	_ASSERT( Block );

	BOOL Continue = TRUE;
	while ( Continue )	{
		_ASSERT(NULL != Block);

		if ( !Proc->AddBasicBlock( Block ) )
			break;	// already parsed in this function

		switch( Block->CtrlFlowType() )	{
		case CTRL_CJMP:
			if ( !Proc->Contains(Block->m_bb.cjmp.TrueTarget) ||
				 !Proc->Contains(Block->m_bb.cjmp.FalseTarget) )	{
				Proc->MarkNotSimple();
				Continue = FALSE;
			} else {
				I_ParseFunc(Proc, Block->m_bb.cjmp.TrueTarget)
				Block = FindBasicBlock( Block->m_bb.cjmp.FalseTarget );
			}
			break;
		case CTRL_UJMP:
			if ( !Proc->Contains(Block->m_bb.ujmp.Target) )	{
				Proc->MarkNotSimple();
				Continue = FALSE;
			} else {
				Block = FindBasicBlock( Block->m_bb.ujmp.Target );
			}
			break;
		case CTRL_FALL:
			if ( !Proc->Contains(Block->m_bb.fall.FallTarget) )	{
				Proc->MarkNotSimple();
				Continue = FALSE;
			} else {
				Block = FindBasicBlock( Block->m_bb.fall.FallTarget );
			}
			break;
		case CTRL_CALL:
			if ( !Proc->Contains(Block->m_bb.call.FallTarget) )	{
				Proc->MarkNotSimple();
				Continue = FALSE;
			} else {
				Block = FindBasicBlock( Block->m_bb.call.FallTarget );
			}
			break;
		case CTRL_RET:
		case CTRL_IJMP:
			Continue = FALSE;
			break;
		default:
			_ASSERT(0);
			Continue = FALSE;
		}
	}

	return S_OK;

}
#endif // if 0


STDMETHODIMP
CCfg::GetEdgesIn(DWORD Address, DIS_REF *Refs, int *count)
{
	//
	// Find the containing basic block
	//
	CBasicBlock *Block = FindContainingBasicBlock(Address);
	
	//
	// If this address isn't a basic block leader, there are no
	// references to it (Except a fall from the previous instruction,
	// possibly)
	//
	if (!Block || Block->Address() != Address)	{
		*count = 0;
		return S_OK;
	}

	//
	// Just copy over all of the predecessor block information
	//
	int i=0;
    PLIST_ENTRY Next = Block->m_PredList.Flink;
    while ((ULONG)Next != (ULONG)&Block->m_PredList && i < *count) {
        CReference *Ref = CONTAINING_RECORD( Next, CReference, ListEntry );
		Refs[i++] = *Ref;	// struct copy
        Next = Ref->ListEntry.Flink;
    }

	*count = i;
	return S_OK;
}

STDMETHODIMP
CCfg::ParseAllSymbols()
{
	//
	// As a hack, we enumerate all of the modules that have been
	// loaded by the loader, and copy info about every code section
	// encountered into this array.
	//
	#define _MAX_CODE_SECTIONS	32
	IMG_SECTION SectionInfo[_MAX_CODE_SECTIONS];
	int NumberOfCodeSections = 0;
	DWORD dwGot;

	//
	// Enumerate the images
	//
	CComPtr<IEnumImages> pIImages;
	HRESULT h = m_pILdr->EnumImages(&pIImages);
	if ( FAILED(h) )
		return h;
	CComPtr<IDisImg> pIImg;
	h = pIImages->Next(1, &pIImg, &dwGot);
	while ( SUCCEEDED(h) && dwGot )	{
		//
		// Enumerate the IMG_SECTIONs in this module
		//
		CComPtr<IEnumSections> pISections;
		HRESULT h = pIImg->EnumSections(&pISections);
		if ( FAILED(h) )
			continue;
		h = pISections->Next(1, &SectionInfo[NumberOfCodeSections], &dwGot);
		while ( SUCCEEDED(h) && dwGot )	{
			if ( SectionInfo[NumberOfCodeSections].Type == IMG_SECTION_CODE )
				NumberOfCodeSections++;
			if ( NumberOfCodeSections >= _MAX_CODE_SECTIONS )
				break;
			h =  pISections->Next(1, &SectionInfo[NumberOfCodeSections], &dwGot);
		}
		if ( NumberOfCodeSections >= _MAX_CODE_SECTIONS )
			break;
		pIImg = NULL;	// release the reference on the smart pointer
		h = pIImages->Next(1, &pIImg, &dwGot);
	}


	//
	//
	// Now, enumerate all of the known symbols in the symbol manager.
	// For now, we really don't know which ones are code and which are
	// data, so we only parse the ones that appear in code sections.
	// This isn't going to be exactly accurate, since it is possible 
	// that someone could have embedded data in the code seg or code
	// in the data seg, but it's better than parsing all the data.
	//
	CComPtr<IEnumSymbols> pIEnum;
	h = m_pISym->EnumSymbols(&pIEnum);
	if ( FAILED(h) )	{
		return h;
	}

	CComPtr<ISymbol> pISymbol;
	h = pIEnum->Next(1, &pISymbol, &dwGot);
	while ( SUCCEEDED(h) && dwGot )	{
		SYMBOL_INFO *SymbolInfo;
		h = pISymbol->GetSymbolInfo(&SymbolInfo);
		//
		// Determine if this address is in a code sectin
		//
		BOOL AddressInCodeSection = FALSE;
		for (int i=0;i<NumberOfCodeSections;i++)	{
			IMG_SECTION &s = SectionInfo[i];
			if ( SymbolInfo->Address >= SectionInfo[i].Address
				&& SymbolInfo->Address < SectionInfo[i].Address + SectionInfo[i].Size )	{
				AddressInCodeSection = TRUE;
				break;
			}
		}

		if ( AddressInCodeSection )	{
			ParseProcedure(SymbolInfo->Address, SymbolInfo->Name);
		}

		pISymbol->ReleaseSymbolInfo(SymbolInfo);
		pISymbol = NULL;
		h =  pIEnum->Next(1, &pISymbol, &dwGot);
	}
	return S_OK;
}

BOOL
CheckOperandForDataReference(OPERAND &Operand, DWORD Address)
{
	switch(Operand.cls)	{
	case OPERAND_CLASS_REG:
	case OPERAND_CLASS_REGPAIR:
	case OPERAND_CLASS_PORT:
		return FALSE;
	case OPERAND_CLASS_IMM:
		if ( Operand.imm.size == SIZE_32 && Operand.imm.imm32 == Address )
			return TRUE;
		else
			return FALSE;
	case OPERAND_CLASS_DIRECT:
		if (Operand.direct.direct32 == Address)
			return TRUE;
		else
			return FALSE;
	case OPERAND_CLASS_MEM:
		// check the displacement
		if ( Operand.mem.mask & MEMPTR_USE_DISP32 && Operand.mem.disp32 == Address)
				return TRUE;
		else
			return FALSE;
	default:
		// BUGBUG: Did I miss an OPERAND_TYPE here???
		_ASSERT(0);
		return FALSE;
	}
}
BOOL
CheckInstructionForDataReference(INSTRUCTION &Instruction, DWORD Address)
{
	for (int i=0;i<Instruction.cOperands;i++)	{
		if (CheckOperandForDataReference(Instruction.op[i], Address))
			return TRUE;
	}
	return FALSE;
}

STDMETHODIMP
CCfg::GetDataReferences(DWORD Address, IEnumInstructions **ppEnum)
{
	INSTRUCTION *InstructionList;
	DWORD InstructionCount = 0;
	DWORD NumInstructionListElements = 32;
	InstructionList = (INSTRUCTION *) malloc( NumInstructionListElements * sizeof(INSTRUCTION) );
#ifdef USE_TREE
	TREE_ENTRY *TreeEntry = FindFirstTreeEntry(&m_BasicBlockTree);
	while (TreeEntry != NULL)	{
        CBasicBlock *BasicBlock = CONTAINING_RECORD( TreeEntry, CBasicBlock, TreeEntry );
#else
    PLIST_ENTRY Next = m_BasicBlockList.Flink;
    while ((ULONG)Next != (ULONG)&m_BasicBlockList) {
        CBasicBlock *BasicBlock = CONTAINING_RECORD( Next, CBasicBlock, ListEntry );
#endif

#if 1
		if (BasicBlock->m_bb.Size == 0)	{
#ifdef USE_TREE
			TreeEntry = FindNextTreeEntry(TreeEntry);
#else
			Next = BasicBlock->ListEntry.Flink;
#endif	// USE_TREE
			continue;
		}
#endif	// 1
		DWORD CurrentAddress= BasicBlock->Address();
		DWORD EndAddress	= BasicBlock->EndAddress();        
		
		//
		// Disassemble the code in this basic block looking for references
		//
		DWORD Ptr;
		if ( FAILED(m_pILdr->ConvertVirtualAddressToPtr(CurrentAddress, &Ptr)) )	{
			continue;	// hmm.  that's not good, though
		}
		
		while (CurrentAddress < EndAddress)	{
			INSTRUCTION Instruction;
			if (FAILED(m_pIDis->Disasm(Ptr, CurrentAddress, &Instruction)))
				break;
			if (CheckInstructionForDataReference(Instruction, Address))	{
				InstructionList[InstructionCount++] = Instruction;	// struct copy
				if (InstructionCount >= NumInstructionListElements)	{
					NumInstructionListElements += 32;
					InstructionList = (INSTRUCTION *) realloc( InstructionList, NumInstructionListElements * sizeof(INSTRUCTION) );
				}
			}

			Ptr += Instruction.dwLen;
			CurrentAddress += Instruction.dwLen;
		} // while (still in basic block)
#ifdef USE_TREE
		TreeEntry = FindNextTreeEntry(TreeEntry);
#else
		Next = BasicBlock->ListEntry.Flink;
#endif
    }	// while (More entries in basic block list)

	typedef CComEnum<IEnumInstructions, &IID_IEnumInstructions, INSTRUCTION, _Copy<INSTRUCTION> > CEnumInstructions;	
	CComObject<CEnumInstructions> *Enum = new CComObject<CEnumInstructions>;
	Enum->Init(&InstructionList[0], &InstructionList[InstructionCount], NULL, AtlFlagCopy);
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumInstructions, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

DWORD EntryPointCount = 0;
DWORD NumEntryPointListElements = 32;
DWORD *EntryPointList = (DWORD *) malloc( NumEntryPointListElements * sizeof(DWORD) );
void 
CCfg::MarkProcedureEntryPoint(DWORD Address)
{
	EntryPointList[EntryPointCount++] = Address;
	if (EntryPointCount >= NumEntryPointListElements)	{
		NumEntryPointListElements += 32;
		EntryPointList = (DWORD *) realloc( EntryPointList, NumEntryPointListElements * sizeof(DWORD) );
	}

}