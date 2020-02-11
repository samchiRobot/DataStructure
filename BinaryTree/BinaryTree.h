#pragma once

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}node_t;

typedef struct _tree
{
	node_t* root;		// Point Head Node of Tree
	int nodeCnt;
}tree_t;

/* Initialize Tree Management Structure */
void InitTree(tree_t* tp);

/* Make New Node */
node_t* MakeNode(int data);

/* Insert New node */
node_t* AddNode(tree_t* tp, int data);

/* Transverse Function */
void PreOrderTraverse(node_t* np);	// ������ȸ
void InOrderTraverse(node_t* np);	// ������ȸ
void PostOrderTraverse(node_t* np); // ������ȸ

/* Search Data */
node_t* SearchNode(tree_t* tp, int data);

void DestroyTree(tree_t* tp);
void PostOrderDelete(node_t* np);