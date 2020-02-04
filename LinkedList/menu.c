#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int menu(const char** menuList, int cnt)
{
	int temp = 0;
	printf("\n");
	for (int i = 0; i < cnt; ++i)
	{
		printf("%d. %s\n", i+1, menuList[i]);
	}
	printf("Select Number : ");
	scanf("%d", &temp);
	if (temp < 1 || temp >= cnt)
		temp = 0;
	printf("\n");
	return temp;
}


void mInputFirst(list_t* lp)
{
	int temp = 0;
	printf("Set Input Data : ");
	scanf("%d", &temp);
	AddFirst(lp, temp);
}

void mInputLast(list_t* lp)
{
	int temp = 0;
	printf("Set Input Data : ");
	scanf("%d", &temp);
	AddLast(lp, temp);
}

// TODO
void mOutput(list_t* lp);

void mSearch(list_t* lp)
{
	int temp = 0;
	printf("Set Search Data : ");
	scanf("%d", &temp);
	node_t* np = SearchNode(lp, temp);
	if (np != NULL)
		printf("Data found, Address is %p\n", np);
	else
		printf("Data not found!\n");
}

void mDelete(list_t* lp)
{
	int temp = 0;
	printf("Set Delete Data : ");
	scanf("%d", &temp);
	
	if (RemoveNode(lp, temp) == TRUE)
		printf("Delete success\n");
	else
		printf("Delete failed!\n");
}

void mSort(list_t* lp);