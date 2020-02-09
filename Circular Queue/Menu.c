#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int menu(const char** menuList, int cnt)
{
	int temp = 0;
	printf("\n");
	for (int i = 0; i < cnt; ++i)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	printf("Select Number : ");
	scanf("%d", &temp);
	if (temp < 1 || temp > cnt)
		temp = 0;
	printf("\n");
	return temp;
}

void mEnqueue(queue_t* qp)
{
	if (qp == NULL)
		return;
	int temp = 0;
	bool_t checker = FALSE;
	printf("Input : ");
	scanf("%d", &temp);
	checker = Enqueue(qp, temp);
	if (checker)
		printf("Enqueue OK\n");
	else
		printf("Enqueue Failed\n");
	PrintQueue(qp);
	return;
}

void mDequeue(queue_t* qp)
{
	if (qp == NULL)
		return;
	int temp = 0;
	bool_t checker = FALSE;
	checker = Dequeue(qp, &temp);
	if (checker)
		printf("Dequeue OK, Data : %d\n", temp);
	else
		printf("Dequeue Failed\n");
	PrintQueue(qp);
	return;
}

void mTerminate(queue_t* qp)
{
	printf("Terminating...");
	DestroyQueue(qp);
	return;
}