#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	tree_t tree;
	tree_t* tp = &tree;
	InitTree(tp);

	AddNode(tp, 7);
	AddNode(tp, 3);
	AddNode(tp, 8);
	AddNode(tp, 1);
	AddNode(tp, 4);
	AddNode(tp, 5);
	AddNode(tp, 6);

	DeleteNode(tp, 4);
	PreOrderTraverse(tp->root);
	return 0;
}