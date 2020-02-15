#pragma once
#define RECURSIVE

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
void PreOrderTraverse(node_t* np);	// 전위순회
void InOrderTraverse(node_t* np);	// 중위순회
void PostOrderTraverse(node_t* np); // 후위순회

/* Search Data */
node_t* SearchNode(tree_t* tp, int data);
node_t* SearchParent(tree_t* tp, int data);

node_t* DeleteNode(tree_t* tp, int data);
void DestroyTree(tree_t* tp);
void PostOrderDelete(node_t* np);

void SwapData(int a, int b);