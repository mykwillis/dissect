#include "project.h"
#include "CBasicBlock.h"

CReference *
AllocateReference(CTRL_FLOW_TYPE Type, DWORD Address)
{
	return new CReference(Type, Address);
}


CBasicBlock *
CBasicBlock::Split(CBasicBlock *bb /* new basic block to use */)
//++
// Split() is called when a control flow reference has been found
// that has a target contained by this basic block.  We shorten
// this basic block such that it ends just before the newly referenced
// address, and set up the new block (passed in) to start at
// the referenced address and end at the end of this original block
//--
{
	//
	// We have to split this block in two.  The attributes of the original block
	// get split up such that:
	//  - the new block inherits the flow (which includes edges out)
	//  - the old block keeps the edges in.

	//
	// Set up the new block to inherit the flow from this block by 
	// closing off the block at the end of the original block.
	//
	_ASSERT(m_bb.Size != 0);
	bb->ParseComplete( m_bb.Address + m_bb.Size, m_bb.Flow );

	//
	// Now, set the new size for the current block
	//
	m_bb.Size = bb->Address() - m_bb.Address;

	//
	// Remove the old successor blocks, since the new block has
	// taken them over.
	//
    PLIST_ENTRY Next = m_SuccList.Flink;
    while ((ULONG)Next != (ULONG)&m_SuccList) {
        CReference *Ref = CONTAINING_RECORD( Next, CReference, ListEntry );
        Next = Ref->ListEntry.Flink;
		RemoveEntryList(&Ref->ListEntry);
		delete Ref;
    }

	//
	// Replace our control flow with a FALL to the new block
	//
	CTRL_FLOW Flow;
	Flow.Type = CTRL_FALL;
	Flow.fall.FallTarget = bb->Address();
	m_bb.Flow = Flow;	// struct copy


	//
	// Insert the reference to the new block
	//
	CReference *Ref = AllocateReference(CTRL_FALL, bb->Address());
	InsertHeadList(&m_SuccList, &Ref->ListEntry);

	//
	// Add a reference to this block in the new block
	//
	bb->AddReference(CTRL_FALL, m_bb.Address);

	_ASSERT( m_bb.Size != 0 );
	return bb;
}


void
CBasicBlock::ParseComplete( DWORD LastAddress, const CTRL_FLOW &Flow )
{
	m_bb.Flow = Flow;
	m_bb.Size = LastAddress - m_bb.Address;
	_ASSERT( m_bb.Size != 0 );

	//
	// Insert a REFERENCE to every successor block
	//
	CReference *Ref;
	switch(m_bb.Flow.Type)	{
	case(CTRL_UJMP):
		Ref = AllocateReference(CTRL_UJMP, m_bb.Flow.ujmp.Target);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		break;
	case(CTRL_CJMP):
		Ref = AllocateReference(CTRL_CJMP, m_bb.Flow.cjmp.TrueTarget);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		Ref = AllocateReference(CTRL_FALL, m_bb.Flow.cjmp.FalseTarget);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		break;
	case(CTRL_IJMP):
		break;
	case(CTRL_CALL):
		Ref = AllocateReference(CTRL_CALL, m_bb.Flow.call.CallTarget);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		Ref = AllocateReference(CTRL_FALL, m_bb.Flow.call.FallTarget);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		break;
	case(CTRL_FALL):
		Ref = AllocateReference(CTRL_FALL, m_bb.Flow.fall.FallTarget);
		InsertHeadList(&m_SuccList, &Ref->ListEntry);
		break;
	case(CTRL_RET):
		break;
	default:
		_ASSERT(0);
		break;
	}


	//
	// Reverse the uCode list
	//
//	STATEMENT_LLIST *u1, *u2, *u3;
//	u1 = NULL;
//	u2 = m_StatementList;
//	while (u2)	{
//		u3 = u2->Next;	// save off next
//		u2->Next = u1;	// point back
//		u1 = u2;
//		u2 = u3;
//	}

}


#ifdef _DEBUG
const char *
CtrlFlowTypeNames[] =
{ "UJMP", "CJMP", "IJMP", "CALL", "FALL", "RET" };

//void
//DumpUCode(UCODE& uCode)
//{
//	switch( uCode.Type )	{
//	case UCODE_TYPE_UNKNOWN:
//	case UCODE_TYPE_CTRL:
//	case UCODE_TYPE_ASSIGNMENT:
//	default:
//		break;
//	}
//}

void CBasicBlock::Dump(IDisSymMgr *pISym)
{
	OLECHAR *Name;
	CComPtr<ISymbol> pISymbol;
	SYMBOL_INFO *SymbolInfo = NULL;
	if (FAILED(pISym->GetSymbolByAddress(&pISymbol, m_bb.Address)))
		Name = L"<unknown>";
	else	{
		if ( FAILED(pISymbol->GetSymbolInfo(&SymbolInfo)) )
			Name = L"<unknown>";
		else
			Name = SymbolInfo->Name;
	}
	printf("Address: %Xh %-30ws \n   Type: %-10s Refs: %d StackAdjustment: %d\n", 
		m_bb.Address, Name, CtrlFlowTypeNames[ m_bb.Flow.Type ], m_bb.EdgesIn, m_bb.StackAdjustment ); 

	if (SymbolInfo)
		pISymbol->ReleaseSymbolInfo(SymbolInfo);

//	STATEMENT_LLIST *u = m_uCodeList;
//	while (u)	{
//		DumpUCode(u->uCode);
//		u = u->Next;
//	}
}
#endif // _DEBUG


CBasicBlock::CBasicBlock( DWORD Address )
{
	memset(&m_bb, 0, sizeof(BASIC_BLOCK));
	m_bb.Address = Address;
	InitializeListHead(&m_PredList);
	InitializeListHead(&m_SuccList);
#ifdef USE_TREE
	InitializeTreeEntry(&TreeEntry, Address);
#endif

}

CBasicBlock::~CBasicBlock()
{
    PLIST_ENTRY Next = m_SuccList.Flink;
    while ((ULONG)Next != (ULONG)&m_SuccList) {
        CReference *Ref = CONTAINING_RECORD( Next, CReference, ListEntry );
        Next = Ref->ListEntry.Flink;
		RemoveEntryList(&Ref->ListEntry);
		delete Ref;
    }

    Next = m_PredList.Flink;
    while ((ULONG)Next != (ULONG)&m_PredList) {
        CReference *Ref = CONTAINING_RECORD( Next, CReference, ListEntry );
        Next = Ref->ListEntry.Flink;
		RemoveEntryList(&Ref->ListEntry);
		delete Ref;
    }
}
void
CBasicBlock::ParseFailed( DWORD LastAddress, int reason /* =0*/ )
{
	m_bb.Flags |= BB_PARSE_INCOMPLETE;
	m_bb.Size = LastAddress - m_bb.Address;
	_ASSERT(m_bb.Size != 0);
	m_bb.Flow.Type = CTRL_RET;	// BUGBUG: Need some better way to show this error
	reason;
}

void
CBasicBlock::AddReference( const CTRL_FLOW_TYPE FlowType, DWORD Address )
{
	CReference *Ref = AllocateReference(FlowType, Address);
	InsertHeadList(&m_PredList, &Ref->ListEntry);
	m_bb.EdgesIn++;
}

int
CBasicBlock::AdjustStack(int Adjustment)
{
	m_bb.StackAdjustment += Adjustment;	// may be negative
	return m_bb.StackAdjustment;
}

BOOL 
CBasicBlock::Contains(DWORD Address)
{
	return ( m_bb.Address <= Address && m_bb.Address + m_bb.Size > Address );
}