#include <stdio.h>
#include "BinaryTree.h"

/* Initialize Tree Management Structure */
void InitTree(tree_t* tp)
{
	tp->root = NULL;
	tp->nodeCnt = 0;
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

// TODO
/* Insert New node */
node_t* AddNode(tree_t* tp, int data);

/* Transverse Function */
void PreOrderTraverse(node_t* np);	// 전위순회
void InOrderTraverse(node_t* np);	// 중위순회
void PostOrderTraverse(node_t* np); // 후위순회

/* Search Data */
node_t* SearchNode(tree_t* tp, int data);

void DestroyTree(tree_t* tp);
void PostOrderDelete(node_t* np);