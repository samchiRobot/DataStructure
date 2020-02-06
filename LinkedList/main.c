#include <stdio.h>
#include "LinkedList.h"
#include "menu.h"

int main(void)
{
	const char* menuList[] = { "Input(Front)", "Input(Backward)", "Print", "Search", "Delete", "Sort", "Quit" };
	int num = 0;
	int cnt = 0;
	bool_t termFlag = FALSE;

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
		if(termFlag)
			break;
	
		switch(num)
		{
		case 1:	mInputFirst(&list);		break;
		case 2: mInputLast(&list);		break;
		case 3: DisplayList(&list);		break;
		case 4: mSearch(&list);			break;
		case 5: mDelete(&list);			break;
		case 6: mSort(&list);			break;
		default: termFlag = TRUE;		break;
		}
	}

	mTerminate(&list);
	return 0;
}