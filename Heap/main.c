#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Heap.h"
#include "menu.h"

int main(void)
{
	heap_t heap;
	heap_t* hp = &heap;

	bool_t bres = FALSE;
	bool_t termFlag = FALSE;
	int menuNum = 0;
	int hSize = 0;

	const char* menuList[] = { "Insert", "Delete", "Print" };
	const int menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	printf("Heap size : ");
	scanf("%d", &hSize);

	if (hSize <= 0)
	{
		perror("Invalid size!\n");
		return -1;
	}

	bres = CreateHeap(hp, hSize);
	if (bres == FALSE)
	{
		perror("Create heap failed!\n");
		return -2;
	}

	while (1)
	{
		if (termFlag)
			break;
		menuNum = menu(menuList, menuCnt);
		switch (menuNum)
		{
		case 1:	mInsert(hp);	break;
		case 2: mDelete(hp);	break;
		case 3: PrintHeap(hp);	break;
		default: termFlag = TRUE; break;
		}
	}

	mTerminate(hp);
	return 0;
}