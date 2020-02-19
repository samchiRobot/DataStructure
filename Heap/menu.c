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

void mInsert(heap_t* hp)
{
	if (hp == NULL)
		return;
	int temp = 0;
	bool_t bres = FALSE;
	printf("Input : ");
	scanf("%d", &temp);

	bres = InsertHeap(hp, temp);
	if (bres)
		printf("Insert OK\n");
	else
		printf("Insert Failed\n");

	PrintHeap(hp);
	return;
}

void mDelete(heap_t* hp)
{
	if (hp == NULL)
		return;
	int temp = 0;
	bool_t bres = FALSE;

	bres = DeleteHeap(hp, &temp);
	if (bres)
		printf("Delete OK : %d\n",temp);
	else
		printf("Delete Failed\n");

	PrintHeap(hp);
	return;
}

void mTerminate(heap_t* hp)
{
	printf("Terminating...\n");
	DestroyHeap(hp);
	return;
}
