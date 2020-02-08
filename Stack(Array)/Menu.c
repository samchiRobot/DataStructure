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

void mPush(stack_t* sp)
{
	if (sp == NULL)
		return;
	int temp = 0;
	bool_t checker = FALSE;
	printf("Input : ");
	scanf("%d", &temp);
	checker = Push(sp, temp);
	if (checker)
		printf("Push OK\n");
	else
		printf("Push Failed\n");
	PrintStack(sp);
	return;
}

void mPop(stack_t* sp)
{
	if (sp == NULL)
		return;
	int temp = 0;
	bool_t checker = FALSE;
	checker = Pop(sp, &temp);
	if (checker)
		printf("Pop OK, Data : %d\n", temp);
	else
		printf("Pop Failed\n");
	PrintStack(sp);
	return;
}

void mTerminate(stack_t* sp)
{
	printf("Terminating...");
	DestroyStack(sp);
	return;
}