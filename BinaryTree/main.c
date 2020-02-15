#include <stdio.h>
#include "BinaryTree.h"
#include "menu.h"
#include "DataType.h"

int main(void)
{
	bool_t bres = FALSE;
	bool_t termFlag = FALSE;
	int menuNum = 0;
	const char* menuList[] = { "Add", "Delete", "Search", "Traverse"};
	const int menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	tree_t tree;
	tree_t* tp = &tree;
	InitTree(tp);
	InputDatas(tp);

	while (1)
	{
		if (termFlag)
			break;
		menuNum = menu(menuList, menuCnt);
		switch (menuNum)
		{
		case 1:	mAdd(tp);		break;
		case 2:	mDelete(tp);	break;
		case 3:	mSearch(tp);	break;
		case 4:	mTraverse(tp);	break;
		default: termFlag = TRUE; break;
		}
	}
	DestroyTree(tp);

	return 0;
}