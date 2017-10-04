#ifndef _QUICK_ALLOC_H
#define _QUICK_ALLOC_H

typedef struct _QALLOC_BLOCK
{
	LIST_ENTRY	ListEntry;
	UINT	NumberOfElements;
	UINT	NextAvailableElement;
} QALLOC_BLOCK;

typedef struct _QUICK_ALLOCATOR	{
	LIST_ENTRY	BlockList;		// head of the list of QALLOC_BLOCKs
	UINT		ChunkCount;		// number of elements to allocate per list
	UINT		ElementSize;	// total bytes to allocate for each element
} QUICK_ALLOCATOR;

void
InitializeQuickAllocator(
		QUICK_ALLOCATOR *Allocator, 
		UINT ElementSize, 
		UINT InitialCount, 
		UINT ChunkCount);

void *
QuickAllocate(QUICK_ALLOCATOR *Allocator);

// Not yet implemented
//void *
//QuickRelease(QUICK_ALLOCATOR *Allocator, void *Element);

void
ReleaseQuickAllocator(QUICK_ALLOCATOR *Allocator);

#endif 