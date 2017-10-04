#ifndef _CBASICBLOCK_H
#define _CBASICBLOCK_H

typedef struct tagSTATEMENT_LLIST
{
	STATEMENT Statement;
	struct tagSTATEMENT_LLIST *Next;
} STATEMENT_LLIST;

class CReference : public DIS_REF
{
public:
	LIST_ENTRY ListEntry;
	CReference(CTRL_FLOW_TYPE Type, DWORD Address)	{
		this->Type = Type;
		this->Address = Address;
	}
};


interface IDisSymMgr;
class CBasicBlock
{
public:
	BASIC_BLOCK m_bb;
#ifdef USE_TREE
	TREE_ENTRY	TreeEntry;
#else
	LIST_ENTRY	ListEntry;	// anchor for global basic block list
#endif

	LIST_ENTRY  m_SuccList;	// head of the successor list
	LIST_ENTRY	m_PredList;	// head of the predecessor list

	CBasicBlock *m_Successors;
	//
	// Methods
	//
	CBasicBlock( DWORD Address );
	~CBasicBlock();
	DWORD Address()	{ return m_bb.Address;	}
	DWORD Size() {	_ASSERT(m_bb.Size != 0); return m_bb.Size;	}
	// returns one past the last address contained in this block
	DWORD EndAddress() { return Address() + Size(); }
	CTRL_FLOW_TYPE CtrlFlowType() { return m_bb.Flow.Type; }
	BOOL Contains(DWORD Address);

	void ParseFailed( DWORD LastAddress, int reason=0 );
	void ParseComplete( DWORD LastAddress, const CTRL_FLOW &Flow );
	void AddReference( const CTRL_FLOW_TYPE FlowType, DWORD Address );
	CBasicBlock * Split(CBasicBlock *bb /* new basic block to use */);
	int AdjustStack(int Adjustment);
	void *operator new(size_t n, void *p)
	{ UNUSED_ARG(n); return p; }

#ifdef _DEBUG
	void Dump(IDisSymMgr *pISym);
#endif // _DEBUG
private:
	void operator delete(void *p)	// no one should delete a basic block directly
	{ UNUSED_ARG(p); }
};

#endif // _CBASICBLOCK_H