#include "project.h"
#include "CProcedure.h"
#include "CBasicBlock.h"
#include "QuickAlloc.h"

BOOL
CProcedure::AddBasicBlock( CBasicBlock *Block )	
{
	_ASSERT( Block != NULL );
	DWORD Address = Block->Address();
	for (int i=0;i<BasicBlockCount;i++)	{
		if (BasicBlockList[i] == Address)
			return FALSE;
	}
	BasicBlockList[BasicBlockCount++] = Address;
	if (BasicBlockCount >= NumBasicBlockListElements)	{
		NumBasicBlockListElements += 32;
		BasicBlockList = (DWORD *) realloc( BasicBlockList, NumBasicBlockListElements * sizeof(DWORD) );
	}
	return TRUE;
}

void
CProcedure::AllocateProcedure(PROCEDURE *Proc)
{
	Proc->Address = m_proc.Address;
	Proc->Size = m_proc.Size;
#if 0
	Proc->NumberOfBasicBlocks = m_proc.NumberOfBasicBlocks;
	Proc->BasicBlocks = new DWORD[Proc->NumberOfBasicBlocks];
	
	BB_LIST *ListIterator;
	DWORD i=0;
	for (	ListIterator = bbList ; 
			ListIterator != NULL  ; 
			ListIterator = ListIterator->Next)	{
		Proc->BasicBlocks[i++] = ListIterator->This->m_bb.Address;
	}
#else
	Proc->NumberOfBasicBlocks = 0;
	Proc->BasicBlocks = 0;
#endif
}
	
void
CProcedure::DestroyProcedure(PROCEDURE *Proc)
{
//	delete [] Proc->BasicBlocks;
}

BOOL 
CProcedure::Contains(DWORD Address)
{
	return ( this->Address() <= Address && EndAddress() > Address );
}

void
CProcedure::EndParse()
{
	m_proc.NumberOfBasicBlocks = BasicBlockCount;
//	m_proc.
}