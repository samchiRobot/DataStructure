#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	tree_t tree;
	tree_t* tp = &tree;
	InitTree(tp);

	AddNode(tp, 20);
	AddNode(tp, 9);
	AddNode(tp, 5);
	AddNode(tp, 1);
	AddNode(tp, 7);
	AddNode(tp, 6);
	AddNode(tp, 10);
	DeleteNode(tp, 7);

	return 0;
}