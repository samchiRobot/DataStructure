#include <stdio.h>
#include "LinkedList.h"
#include "menu.h"

int main(void)
{
	const char* menuList[] = { "Input(Front)", "Input(Backward)", "Print", "Search", "Delete", "Sort"};
	int num = 0;
	int cnt = 0;
	bool_t termFlag = FALSE;

	list_t list;
	list_t* lp = &list;
	bool_t bres;

	cnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = CreateList(&list);
	if (bres)
		printf("CreateList Success!\n");
	else
	{
		printf("CreateList Failed!\n");
		return -1;
	}

	while (1)
	{
		if (termFlag)
			break;
		num = menu(menuList, cnt);

		switch(num)
		{
		case 1:	mInputFirst(lp);	break;
		case 2: mInputLast(lp);		break;
		case 3: DisplayList(lp);	break;
		case 4: mSearch(lp);		break;
		case 5: mDelete(lp);		break;
		case 6: mSort(lp);			break;
		default: termFlag = TRUE;	break;
		}
	}

	mTerminate(&list);
	return 0;
}