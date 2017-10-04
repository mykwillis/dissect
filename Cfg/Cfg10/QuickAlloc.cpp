#include "project.h"
#include "QuickAlloc.h"

void
InitializeQuickAllocator(QUICK_ALLOCATOR *Allocator, UINT ElementSize, UINT InitialCount, UINT ChunkCount)
{
	QALLOC_BLOCK *Block;

	//
	// Initialize the QUICK_ALLOCATOR structure
	//
	Allocator->ElementSize = ElementSize;
	Allocator->ChunkCount = ChunkCount;
	InitializeListHead(&Allocator->BlockList);

	//
	// Allocate the initial block
	//
	Block = (QALLOC_BLOCK *) malloc( sizeof(QALLOC_BLOCK) + (ElementSize * InitialCount) );
	Block->NumberOfElements = InitialCount;
	Block->NextAvailableElement = 0;
	InsertHeadList(&Allocator->BlockList, &Block->ListEntry);
}

void *
QuickAllocate(QUICK_ALLOCATOR *Allocator)
{
	QALLOC_BLOCK *Block = CONTAINING_RECORD( GetHeadList(&Allocator->BlockList), QALLOC_BLOCK, ListEntry );
	_ASSERT(Block->NextAvailableElement != (UINT)-1);
	void *Element = (PBYTE)(Block+1)+(Block->NextAvailableElement * Allocator->ElementSize);
	if (++(Block->NextAvailableElement) == Block->NumberOfElements)	{
		Block->NextAvailableElement = (UINT)-1;
		Block = (QALLOC_BLOCK *) malloc( sizeof(QALLOC_BLOCK) + (Allocator->ElementSize * Allocator->ChunkCount) );
		Block->NumberOfElements = Allocator->ChunkCount;
		Block->NextAvailableElement = 0;
		InsertHeadList(&Allocator->BlockList, &Block->ListEntry);
	}

	return Element;
}

// Not yet implemented
//void *
//QuickRelease(QUICK_ALLOCATOR *Allocator, void *Element);

void
ReleaseQuickAllocator(QUICK_ALLOCATOR *Allocator)
{
    PLIST_ENTRY Next = Allocator->BlockList.Flink;
    while ((ULONG)Next != (ULONG)&Allocator->BlockList) {
        QALLOC_BLOCK *Block = CONTAINING_RECORD( Next, QALLOC_BLOCK, ListEntry );
		Next = Block->ListEntry.Flink;
		free( Block );
    }
}
