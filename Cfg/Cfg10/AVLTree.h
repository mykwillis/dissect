#ifndef _AVLTREE_H
#define _AVLTREE_H

typedef struct _TREE_ENTRY
{
	struct _TREE_ENTRY *LChild;
	struct _TREE_ENTRY *RChild;
	struct _TREE_ENTRY *Parent;
	DWORD Key;
	int BalanceFactor;
} TREE_ENTRY;

typedef struct _AVL_TREE
{
	TREE_ENTRY *Root;
	DWORD	Count;
} AVL_TREE;

//	VOID
//	InitializeAVLTree(
//		AVL_TREE *Tree
//		);

#define InitializeAVLTree(Tree)	\
	(Tree)->Root = NULL;			\
	(Tree)->Count =0;


//	VOID
//	InitializeTreeEntry(
//		TREE_ENTRY *TreeEntry,
//		DWORD Key
//		);

#define InitializeTreeEntry(TreeEntry, _Key)		\
	(TreeEntry)->Key = _Key;						\
	(TreeEntry)->BalanceFactor =0;				\
	(TreeEntry)->LChild = (TreeEntry)->RChild = (TreeEntry)->Parent = 0;

BOOL
InsertTreeEntry(
	AVL_TREE *Tree, 
	TREE_ENTRY *TreeEntry
	);

VOID
RemoveTreeEntry(
	AVL_TREE *Tree, 
	TREE_ENTRY *TreeEntry
	);

TREE_ENTRY *
FindTreeEntry(
	AVL_TREE *	Tree,
	DWORD		Key
	);

TREE_ENTRY *
FindNearestTreeEntry(
	AVL_TREE *	Tree,
	DWORD		Key
	);

typedef enum {
	SEARCH_EXACT,
	SEARCH_LOWER,
	SEARCH_LOWER_OR_EQUAL,
	SEARCH_GREATER,
	SEARCH_GREATER_OR_EQUAL
} SEARCH_TYPE;

TREE_ENTRY *
FindTreeEntryEx(
	AVL_TREE*	Tree,
	DWORD		Key,
	SEARCH_TYPE	SearchType
	);

TREE_ENTRY *
FindNextTreeEntry(
	TREE_ENTRY*	TreeEntry
	);

TREE_ENTRY *
FindPreviousTreeEntry(
	TREE_ENTRY*	TreeEntry
	);

TREE_ENTRY *
FindFirstTreeEntry(
	AVL_TREE *	Tree
	);

#endif // _AVLTREE_H