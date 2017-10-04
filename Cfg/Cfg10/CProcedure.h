#ifndef _CPROCEDURE_H
#define _CPROCEDURE_H

class CBasicBlock;

class CProcedure
{
public:
	PROCEDURE m_proc;
	int BasicBlockCount;
	int NumBasicBlockListElements;
	DWORD *BasicBlockList;
	OLECHAR *m_Name;

	CProcedure(DWORD Address, OLECHAR *Name)	{
		m_proc.Address = Address;
		m_proc.Size = 0;
		m_proc.NumberOfBasicBlocks = 0;

		m_Name = wcsdup(Name);
		BasicBlockCount = 0;
		NumBasicBlockListElements = 32;
		BasicBlockList = (DWORD *) malloc( NumBasicBlockListElements * sizeof(DWORD) );
	}
	~CProcedure()	{
		free(BasicBlockList);
		free(m_Name);
	}

	DWORD Address()	{ return m_proc.Address;	}
	DWORD Size() {	_ASSERT(m_proc.Size != 0); return m_proc.Size;	}
	// returns one past the last address contained in this block
	DWORD EndAddress() { return Address() + Size(); }
	BOOL Contains(DWORD Address);
	void EndParse();

	BOOL AddBasicBlock(CBasicBlock *bb);
	void AllocateProcedure(PROCEDURE *Proc);
	static void DestroyProcedure(PROCEDURE *Proc);
	LIST_ENTRY	ListEntry;	// entry on procedure list
private:
	LIST_ENTRY	m_BasicBlockList;
};

#endif // _CPROCEDURE_H
