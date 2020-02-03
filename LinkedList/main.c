

#include <stdio.h>
#include "LinkedList.h"
#include "menu.h"

int main(void)
{
	const char* menuList[] = { "Input", "Print", "Search", "Delete", "Sort", "Quit" };
	int num = 0;
	int cnt = 0;
	
	list_t list;
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
		num = menu(menuList, cnt);
		if (num == cnt)
			break;
	switch (num)
		{
		case 1:	mInput(&list);		break;
		case 2: DisplayList(&list);	break;
		default:	break;
		}
	}

	return 0;
}