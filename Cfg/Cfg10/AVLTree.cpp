#include "project.h"
#include "AVLTree.h"

BOOL
InsertTreeEntry(
	AVL_TREE *Tree, 
	TREE_ENTRY *TreeEntry)
//++
//
// This function inserts a TREE_ENTRY
//
// A node is balanced if it has balance factor -1, 0, or 1.
//
//--
{
	//
	// Check for empty tree
	//
	if (!Tree->Root)	{
		Tree->Root = TreeEntry;
		Tree->Count++;
		return TRUE;
	}

	//
	// Find insert point for TreeEntry.  This is done by following the
	// left or right branch at every node until we either find a node
	// with the same key value as the new entry, or we reach a leaf
	// node.
	//
	/* p */TREE_ENTRY *CurrentNode = Tree->Root;// node used to iterate
	/* q */TREE_ENTRY *LastNode = NULL;			// previous value of CurrentNode
	/* f */TREE_ENTRY *PivotParentNode = NULL;	// parent of PivotNode
	/* a */TREE_ENTRY *PivotNode = Tree->Root;	// The nearest ancestor of TreeEntry that has a
												// non-zero BalanceFactor (-1 or +1)
	/* b */TREE_ENTRY *PivotChildNode = NULL;
	while(CurrentNode)	{
		//
		// Keep track of the most recent node with a non-zero
		// balance factor.
		//
		if (CurrentNode->BalanceFactor != 0) { 
			PivotNode = CurrentNode; 
			PivotParentNode = LastNode; 
		}

		//
		// Follow the left or right branch if this key is different
		//
		if (TreeEntry->Key < CurrentNode->Key)	{
			LastNode = CurrentNode;
			CurrentNode = CurrentNode->LChild;	// Branch left
		} else if (TreeEntry->Key > CurrentNode->Key)	{
			LastNode = CurrentNode;
			CurrentNode = CurrentNode->RChild;	// Branch right
		} else {
			return FALSE;	// Found match (error)
		}
	} // while


	//
	// Insert the new node under the last non-NULL node we traversed
	//
	if (TreeEntry->Key < LastNode->Key)	{
		LastNode->LChild = TreeEntry;
		TreeEntry->Parent = LastNode;
	} else {
		LastNode->RChild = TreeEntry;
		TreeEntry->Parent = LastNode;
	}

	Tree->Count++;

	//
	// Calculate the balance adjustment to be applied to all nodes
	// between the pivot node and the inserted node.  Also remember
	// the child node of the pivot node that is on the 'heavy' side;
	//
	int BalanceAdjustment;
	if ( TreeEntry->Key > PivotNode->Key )	{
		CurrentNode = PivotNode->RChild;
		PivotChildNode = CurrentNode;	// right child is heavy
		BalanceAdjustment = -1;
	} else {
		CurrentNode = PivotNode->LChild;
		PivotChildNode = CurrentNode;	// left child is heavy
		BalanceAdjustment = +1;
	}

	//
	// Adjust the balance factors of all nodes between the pivot
	// node and the newly inserted node
	//
	while (CurrentNode != TreeEntry)	{
		if (TreeEntry->Key > CurrentNode->Key)	{
			// height of right increases by 1 (we know that
			// CurrentNode->BalanceFactor was zero.  Otherwise,
			// it would have been designated as PivotNode)
			_ASSERT(CurrentNode->BalanceFactor == 0);
			CurrentNode->BalanceFactor = -1;
			CurrentNode = CurrentNode->RChild;
		} else {
			// height of left increases by 1
			_ASSERT(CurrentNode->BalanceFactor == 0);
			CurrentNode->BalanceFactor = +1;
			CurrentNode = CurrentNode->LChild;
		}
	}

	//
	// If the tree is still balanced with the new node added, return.
	// We will now that it is unbalanced if the pivot node hits +2 or -2
	// once the balance adjustment is applied to it.
	//
	if (	(PivotNode->BalanceFactor == 0) || 
			(PivotNode->BalanceFactor + BalanceAdjustment == 0))	
	{
		PivotNode->BalanceFactor += BalanceAdjustment;
		return TRUE;	// no balancing needs to be done
	}

	//
	// The tree is now imbalanced.
	//
	if (BalanceAdjustment == 1)		{
		// left imbalance
		if (PivotChildNode->BalanceFactor == 1)	{
			// rotation type LL
			//
			// This infers that the new node is being inserted in the
			// left subtree of the left subtree of PivotNode
			//
			PivotNode->LChild = PivotChildNode->RChild;
			if (PivotChildNode->RChild) PivotChildNode->RChild->Parent = PivotNode;

			PivotChildNode->RChild = PivotNode;
			if (PivotNode) PivotNode->Parent = PivotChildNode;

			PivotNode->BalanceFactor = 0;
			PivotChildNode->BalanceFactor = 0;
		} else {
			// rotation type LR
			//
			// TreeEntry was inserted in the right subtree of the left
			// subtree of PivotNode
			//
			TREE_ENTRY *NodeC = PivotChildNode->RChild;
			PivotChildNode->RChild = NodeC->LChild;
			if (NodeC->LChild) NodeC->LChild->Parent = PivotChildNode;

			PivotNode->LChild = NodeC->RChild;
			if (NodeC->RChild) NodeC->RChild->Parent = PivotNode;

			NodeC->LChild = PivotChildNode;
			if (PivotChildNode) PivotChildNode->Parent = NodeC;

			NodeC->RChild = PivotNode;
			if (PivotNode) PivotNode->Parent = NodeC;

			switch(NodeC->BalanceFactor)	{
			case 1:
				// LR(b)
				PivotNode->BalanceFactor = -1;
				PivotChildNode->BalanceFactor = 0;
				break;
			case -1:
				// LR(c)
				PivotNode->BalanceFactor = 0;
				PivotChildNode->BalanceFactor = 1;
				break;
			case 0:
				// LR(a)
				PivotNode->BalanceFactor = 0;
				PivotChildNode->BalanceFactor = 0;
				break;
			default:
				_ASSERT(0);
			}
			NodeC->BalanceFactor = 0;
			PivotChildNode = NodeC;	// b is the new root
		} // end of LR
	} // end of left imbalance
	else {
		_ASSERT(BalanceAdjustment == -1);
		// right imbalance
		if (PivotChildNode->BalanceFactor == -1)	{				
			// rotation type RR
			//
			// TreeEntry was inserted in the right subtree of the right
			// subtree of PivotNode
			//
			PivotNode->RChild = PivotChildNode->LChild;
			if (PivotChildNode->LChild) PivotChildNode->LChild->Parent = PivotNode;

			PivotChildNode->LChild = PivotNode;
			if (PivotNode) PivotNode->Parent = PivotChildNode;

			PivotNode->BalanceFactor = 0;
			PivotChildNode->BalanceFactor = 0;
		} else {
			_ASSERT(PivotChildNode->BalanceFactor == 1);
			// rotation type RL
			//
			// TreeEntry was inserted in the left subtree of the right
			// subtree of PivotNode
			//
			TREE_ENTRY *NodeC = PivotChildNode->LChild;
			PivotChildNode->LChild = NodeC->RChild;
			if (NodeC->RChild) NodeC->RChild->Parent = PivotChildNode;

			PivotNode->RChild = NodeC->LChild;
			if (NodeC->LChild) NodeC->LChild->Parent = PivotNode;

			NodeC->RChild = PivotChildNode;
			if (PivotChildNode) PivotChildNode->Parent = NodeC;

			NodeC->LChild = PivotNode;
			if (PivotNode) PivotNode->Parent = NodeC;

			switch(NodeC->BalanceFactor)	{
			case 1:
				// RL(b)
				PivotNode->BalanceFactor = 0;
				PivotChildNode->BalanceFactor = -1;
				break;
			case -1:
				// RL(c)
				PivotNode->BalanceFactor = 1;
				PivotChildNode->BalanceFactor = 0;
				break;
			case 0:
				// RL(a)
				PivotNode->BalanceFactor = 0;
				PivotChildNode->BalanceFactor = 0;
				break;
			default:
				_ASSERT(0);
			}
			NodeC->BalanceFactor = 0;
			PivotChildNode = NodeC;	// b is the new root
		} // end of LR
	}

	if (!PivotParentNode) {
		Tree->Root = PivotChildNode;
		if (PivotChildNode) PivotChildNode->Parent = NULL;
	} else if (PivotNode == PivotParentNode->LChild)	{
		PivotParentNode->LChild = PivotChildNode;
		if (PivotChildNode) PivotChildNode->Parent = PivotParentNode;
	} else if (PivotNode == PivotParentNode->RChild)	{
		PivotParentNode->RChild = PivotChildNode;
		if (PivotChildNode) PivotChildNode->Parent = PivotParentNode;
	}

	return TRUE;
}

TREE_ENTRY *
FindTreeEntry(
	AVL_TREE *	Tree,
	DWORD		Key)
//++
//
//--
{
	TREE_ENTRY *CurrentNode = Tree->Root;
	while (CurrentNode)	{
		if (Key < CurrentNode->Key)	{
			CurrentNode = CurrentNode->LChild;	// Branch left
		} else if (Key > CurrentNode->Key)	{
			CurrentNode = CurrentNode->RChild;	// Branch right
		} else {
			return CurrentNode;	// Found match (error)
		}
	}
	return NULL;
}

TREE_ENTRY *
FindTreeEntryEx(
	AVL_TREE *	Tree,
	DWORD		Key,
	SEARCH_TYPE	SearchType)
//++
//
//--
{
	TREE_ENTRY *TreeEntry = FindNearestTreeEntry(Tree, Key);

	if (TreeEntry) switch(SearchType)	{
	case SEARCH_EXACT:
		return TreeEntry;
	case SEARCH_LOWER:
		if (TreeEntry->Key >= Key)
			TreeEntry = FindPreviousTreeEntry(TreeEntry);
		break;
	case SEARCH_LOWER_OR_EQUAL:
		if (TreeEntry->Key > Key)
			TreeEntry = FindPreviousTreeEntry(TreeEntry);
		break;
	case SEARCH_GREATER:
		if (TreeEntry->Key <= Key)
			TreeEntry = FindNextTreeEntry(TreeEntry);
		break;
	case SEARCH_GREATER_OR_EQUAL:
		if (TreeEntry->Key < Key)
			TreeEntry = FindPreviousTreeEntry(TreeEntry);
		break;
	default:
		_ASSERT(0);
		break;
	}
	return TreeEntry;
}

TREE_ENTRY *
FindPreviousTreeEntry(
	TREE_ENTRY *TreeEntry)
//++
//
//--
{

	//
	// If this node has an LChild, the previous entry is found 
	// by following all RChild links of that child.  Otherwise, it
	// is found as the parent of the first RChild walking up the
	// Parent chain.
	// 
	TREE_ENTRY *CurrentNode;
	TREE_ENTRY *LastNode;
	if (TreeEntry->LChild)	{
		CurrentNode = TreeEntry->LChild;
		LastNode = CurrentNode;
		while (CurrentNode)	{
			LastNode = CurrentNode;
			CurrentNode = CurrentNode->RChild;
		}
		return LastNode;
	} else {
		CurrentNode = TreeEntry;	// may be NULL
		while (CurrentNode && CurrentNode->Parent)	{
			if (CurrentNode->Parent->RChild == CurrentNode)
				return CurrentNode->Parent;
			CurrentNode = CurrentNode->Parent;
		}
		return NULL;	// no previous node
	}
}

TREE_ENTRY *
FindNextTreeEntry(
	TREE_ENTRY *TreeEntry)
//++
//
//--
{
	//
	// If this node has an RChild, the previous entry is found 
	// by following all LChild links of that child.  Otherwise, it
	// is found as the parent of the first LChild walking up the
	// Parent chain.
	// 
	TREE_ENTRY *CurrentNode;
	TREE_ENTRY *LastNode;
	if (TreeEntry->RChild)	{
		CurrentNode = TreeEntry->RChild;
		LastNode = CurrentNode;
		while (CurrentNode)	{
			LastNode = CurrentNode;
			CurrentNode = CurrentNode->LChild;
		}
		return LastNode;
	} else {
		CurrentNode = TreeEntry;	// may be NULL
		while (CurrentNode && CurrentNode->Parent)	{
			if (CurrentNode->Parent->LChild == CurrentNode)
				return CurrentNode->Parent;
			CurrentNode = CurrentNode->Parent;
		}
		return NULL;	// no previous node
	}
}

TREE_ENTRY *
FindNearestTreeEntry(
	AVL_TREE *	Tree,
	DWORD		Key)
{
	TREE_ENTRY *CurrentNode = Tree->Root;
	TREE_ENTRY *LastNode = NULL;
	while (CurrentNode)	{
		LastNode = CurrentNode;
		if (Key < CurrentNode->Key)	{
			CurrentNode = CurrentNode->LChild;	// Branch left
		} else if (Key > CurrentNode->Key)	{
			CurrentNode = CurrentNode->RChild;	// Branch right
		} else {
			return CurrentNode;	// Found match (error)
		}
	}
	return LastNode;
}

VOID
RemoveTreeEntry(
	AVL_TREE *Tree, 
	TREE_ENTRY *TreeEntry)
//++
//
//--
{
	UNUSED_ARG(Tree);
	UNUSED_ARG(TreeEntry);
	_ASSERT(0);
}

TREE_ENTRY *
FindFirstTreeEntry(
	AVL_TREE *	Tree)
{
	return FindNearestTreeEntry(Tree, 0);
}
