#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CircularQueue.h"
#include "Menu.h"

int main(void)
{
	queue_t q;
	queue_t* qp = &q;
	bool_t bres = FALSE;
	bool_t termFlag = FALSE;
	int qSize = 0;
	const char* menuList[] = { "Enqueue", "Dequeue", "Print" };
	const int menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	int menuNum = 0;

	printf("Queue size : ");
	scanf("%d", &qSize);

	if (qSize <= 0)
	{
		perror("Invalid Size!\n");
		return -1;
	}

	bres = CreateQueue(qp, qSize);
	if (bres)
		printf("Create Queue OK, size : %d\n", qp->size);
	else
	{
		perror("Create Queue Error!");
		return -2;
	}

	while (1)
	{
		if (termFlag)
			break;
		menuNum = menu(menuList, menuCnt);
		switch (menuNum)
		{
		case 1:	mEnqueue(qp);	break;
		case 2: mDequeue(qp);	break;
		case 3: PrintQueue(qp);	break;
		default: termFlag = TRUE; break;
		}
	}
	mTerminate(qp);

	return 0;
}