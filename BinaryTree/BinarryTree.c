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
	node_t* np = calloc(1, sizeof(node_t));
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

// TODO
node_t* SearchParent(tree_t* tp, int data)
{

}

node_t* DeleteNode(tree_t* tp, int data)
{
	// Null check
	if (tp == NULL)
		return NULL;
	node_t* dp = SearchNode(tp, data);
	if (dp == NULL)
		return NULL;
}

void DestroyTree(tree_t* tp)
{

}
void PostOrderDelete(node_t* np);