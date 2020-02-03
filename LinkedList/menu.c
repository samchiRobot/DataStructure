#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int menu(const char** menuList, int cnt)
{
	int temp = 0;
	for (int i = 0; i < cnt; ++i)
	{
		printf("%d. %s\n", i+1, menuList[i]);
	}
	printf("Select Number : ");
	scanf("%d", &temp);
	if (temp < 1 || temp >= cnt)
		temp = 0;
	return temp;
}


void mInput(list_t* lp)
{
	int temp = 0;
	printf("Set Input Data : ");
	scanf("%d", &temp);
	AddFirst(lp, temp);
}

void mOutput(list_t* lp);
void mSearch(list_t* lp);
void mDelete(list_t* lp);
void mSort(list_t* lp);