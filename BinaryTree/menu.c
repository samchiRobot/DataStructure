#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>

void InputDatas(tree_t* tp)
{
	int data = 0;
	while (1)
	{
		printf("Input data : ");
		scanf("%d", &data);
		if (data < 0)
			break;
		if (AddNode(tp, data) == NULL)
			printf("Invalid Data!\n");
		else
			printf("Input OK\n");
	}
	return;
}

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

void mTraverse(tree_t* tp)
{
	int mode = 0;
	printf("Select mode : ");
	scanf("%d", &mode);

	switch (mode)
	{
	case 1:	PreOrderTraverse(tp->root);		break;
	case 2: InOrderTraverse(tp->root);		break;
	case 3:	PostOrderTraverse(tp->root);	break;
	default:	printf("Invalid mode!");	break;
	}
	printf("\nNumber of nodes : %d\n", tp->nodeCnt);
	return;
}

void mSearch(tree_t* tp)
{
	int data = 0;
	printf("Input data : ");
	scanf("%d", &data);

	node_t* np = SearchNode(tp, data);
	if (np == NULL)
		printf("Data Not Found!\n");
	else
	{
		printf("Data Found\n");
		printf("Node Address : %p\n", np);
		printf("Parent Node Data : %d", SearchParent(tp, data)->data);
	}
}

void mDelete(tree_t* tp)
{
	int data = 0;
	printf("Input data : ");
	scanf("%d", &data);

	node_t* np = SearchNode(tp, data);
	if (np == NULL)
		printf("Data Not Found!\n");
	else
	{
		node_t* pp = SearchParent(tp, data);
		node_t* dp = DeleteNode(tp, data);
		if (pp == dp)
			printf("Delete OK\n");
		else
			printf("Delete Failed!\n");
	}
}

void mAdd(tree_t* tp)
{
	int data = 0;
	printf("Input data : ");
	scanf("%d", &data);

	node_t* np = AddNode(tp, data);
	if (np == NULL)
		printf("Add Failed!\n");
	else
		printf("Add OK\n");
}
