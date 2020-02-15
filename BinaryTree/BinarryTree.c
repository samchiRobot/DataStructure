#include <stdio.h>
#include "BinaryTree.h"

/* Initialize Tree Management Structure */
void InitTree(tree_t* tp)
{
	if (tp == NULL)
		return;
	tp->root = NULL;
	tp->nodeCnt = 0;
	return;
}

/* Make New Node */
node_t* MakeNode(int data)
{
	node_t* np = (node_t*)calloc(1, sizeof(node_t));
	if (np != NULL)
	{
		np->data = data;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

/* Insert New node */
/* Condition 1 : Left child node < Parent node < Right child node */
/* Condition 2 : Data is unique */
node_t* AddNode(tree_t* tp, int data)
{
	if (tp == NULL)
		return NULL;
	node_t* pp = NULL;
	node_t* temp = NULL;
	node_t* np = MakeNode(data);
	if (np == NULL)
		return NULL;

	if (tp->root == NULL)
	{
		tp->root = np;
		return tp->root;
	}

	temp = tp->root;
	while (temp != NULL)
	{
		pp = temp;
		if (np->data > temp->data)
			temp = temp->right;
		else if (np->data < temp->data)
			temp = temp->left;
		else
			return NULL;		
	}

	if (np->data > pp->data)
		pp->right = np;
	else if (np->data < pp->data)
		pp->left = np;
	else
		return NULL;

	return np;
}

#ifdef RECURSIVE
/* Transverse Function */
void PreOrderTraverse(node_t* np)	// 전위순회
{
	if (np == NULL)
		return;
	printf("%d ", np->data);
	PreOrderTraverse(np->left);
	PreOrderTraverse(np->right);
	return;
}

void InOrderTraverse(node_t* np)	// 중위순회
{
	if (np == NULL)
		return;
	InOrderTraverse(np->left);
	printf("%d ", np->data);
	InOrderTraverse(np->right);
	return;
}

void PostOrderTraverse(node_t* np) // 후위순회
{
	if (np == NULL)
		return;
	PostOrderTraverse(np->left);
	PostOrderTraverse(np->right);
	printf("%d ", np->data);
	return;
}
#else
// TODO
#endif

/* Search Data */
node_t* SearchNode(tree_t* tp, int data)
{
	// Null check
	if (tp == NULL)
		return NULL;
	node_t* np = tp->root;

	while (np != NULL)
	{
		if (np->data == data)
			return np;
		else if (np->data < data)
			np = np->right;
		else
			np = np->left;
	}
	return NULL;
}

node_t* SearchParent(tree_t* tp, int data)
{
	// Null check
	if (tp == NULL)
		return NULL;

	node_t* np = SearchNode(tp, data);
	node_t* pp = tp->root;

	while (pp != NULL)
	{
		if ((pp->left == np) || (pp->right == np))
			return pp;
		else
		{
			if (pp->data < data)
				pp = pp->right;
			else
				pp = pp->left;
		}
	}
	return NULL;
}


// FIXIT
node_t* DeleteNode(tree_t* tp, int data)
{
	// Null check
	if (tp == NULL)
		return NULL;
	
	int temp = 0;

	// Search Delete Node
	node_t* dp = SearchNode(tp, data);
	if (dp == NULL)
		return NULL;

	// Search Parent Node of dp
	node_t* pdp = SearchNode(tp, data);
	if (pdp == NULL)
		return NULL;

	// Set Replace Node of dp, Parent of rp
	node_t* rp = NULL;
	node_t* prp = NULL;

	// Case 1 : dp has both child nodes
	if (dp->left != NULL && dp->right != NULL)
	{
		rp = dp->left;
		if (rp->right == NULL)
		{
			prp = SearchParent(tp, rp->data);
			if (prp == NULL)
				return NULL;

			// Swap data between dp, rp
			SwapData(&(rp->data), &(dp->data));

			if (dp->data > prp->data)
				prp->left = rp->left;

		}
		else
		{
			while (rp->right != NULL)
			{
				rp = rp->right;
			}
			prp = SearchParent(tp, rp->data);
			if (prp == NULL)
				return NULL;

			SwapData(&(rp->data), &(dp->data));

			if (rp->data > prp->data)
				prp->right = rp->left;
		}
		// Delete rp
		free(rp);
		rp = NULL;
	}


	// Case 2 : dp doesn't have child node
	else if (dp->left == NULL && dp->right == NULL)
	{
		if (dp->data > pdp->data)
			pdp->right = NULL;
		else
			pdp->left = NULL;
		free(dp);
		dp = NULL;
	}

	// Case 3 : dp has one child node
	else
	{
		if (dp->left != NULL)
			rp = dp->left;
		else
			rp = dp->right;
		
		prp = dp;
		SwapData(&(rp->data), &(dp->data));

		prp->left = rp->left;
		prp->right = rp->right;

		free(rp);
		rp = NULL;
	}
	return pdp;
}

void SwapData(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}


void DestroyTree(tree_t* tp)
{

}


void PostOrderDelete(node_t* np);