#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	tree_t tree;
	const tree_t* tp = &tree;
	InitTree(tp);

	AddNode(tp, 7);
	AddNode(tp, 6);
	AddNode(tp, 5);
	AddNode(tp, 1);


	return 0;
}