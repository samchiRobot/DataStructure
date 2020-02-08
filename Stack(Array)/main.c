#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "ArrayStack.h"
#include "Menu.h"

int main(void)
{
	bool_t checker = FALSE;
	bool_t termFlag = FALSE;
	stack_t s;
	const stack_t* sp = &s;
	const char* menuList[] = {"Push", "Pop", "Print"};
	const int menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	int menuNum = 0;
	int stackSize = 0;

	printf("Stack Size : ");
	scanf("%d", &stackSize);

	checker = CreateStack(sp, stackSize);

	if (checker)
		printf("Create Stack Success\n");
	else
	{
		printf("Create Stack Fail!\n");
		return -1;
	}

	while (1)
	{
		if (termFlag)
			break;
		menuNum = menu(menuList, menuCnt);
		switch (menuNum)
		{
		case 1:		mPush(sp);			break;
		case 2:		mPop(sp);			break;
		case 3:		PrintStack(sp);		break;
		default:	termFlag = TRUE;	break;
		}
	}
	mTerminate(sp);

	return 0;
}