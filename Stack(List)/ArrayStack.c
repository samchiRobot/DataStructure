#pragma once
#include "ArrayStack.h"
#include <stdlib.h>

/* Array Stack Initiailization */
bool_t CreateStack(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	/* Create head, tail node */
	sp->head = malloc(sizeof(node_t));
	if (sp->head == NULL)
		return FALSE;

	sp->tail = malloc(sizeof(node_t));
	if (sp->tail == NULL)
	{
		free(sp->head);
		return FALSE;
	}

	/* Set pointer */
	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;

	return TRUE;
}

bool_t isStackEmpty(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	if (sp->head->next == sp->tail)
		return TRUE;
	else
		return FALSE;
}

/* Push/Pop Data */
bool_t Push(stack_t* sp, int PushData)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	/* Create new node */
	node_t* np = malloc(sizeof(node_t));
	if (np == NULL)
		return FALSE;
	np->data = PushData;

	/* set pointer */
	np->next = sp->head->next;
	sp->head->next = np;
	return TRUE;
}

bool_t Pop(stack_t* sp, int* PopData)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	/* Check sp->top */
	if (isStackEmpty(sp))
		return FALSE;

	node_t* dp = sp->head->next;
	
	*PopData = dp->data;

	sp->head->next = dp->next;
	free(dp);

	return TRUE;
}

/* Print all data in stack */
void PrintStack(const stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;
	printf("Stack :");
	node_t* np = sp->head->next;
	while (np != sp->tail)
	{
		printf("%d ", np->data);
		np = np->next;
	}
	printf("\n");
}

/* Delete all of the data */
void DestroyStack(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return;
	
	/* Remove nodes between head, tail node */
	node_t* dp = sp->head->next;
	node_t* np = dp->next;
	while (dp != sp->tail)
	{
		free(dp);
		dp = np;
		np = np->next;
		printf("*"); // for check the number of delete data
	}
	printf("\n");
	/* Remove head, tail node */
	free(sp->head);
	free(sp->tail);
	sp->head = NULL;
	sp->tail = NULL;
	return;
}
