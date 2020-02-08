#pragma once
#include "ArrayStack.h"
#include <stdlib.h>

/* Array Stack Initiailization */
bool_t CreateStack(stack_t* sp, int size)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	/* Initialize */
	sp->size = size;
	sp->top = 0;
	sp->stack = calloc(sizeof(int), sp->size);
	if (sp->stack == NULL)
		return FALSE;

	return TRUE;
}

/* Check Stack State */
bool_t isStackFull(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;
	if (sp->top == sp->size)
		return TRUE;
	else
		return FALSE;
}

bool_t isStackEmpty(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	if (sp->top == 0)
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

	/* Check sp->top */
	if (isStackFull(sp))
		return FALSE;
	sp->stack[sp->top++] = PushData;
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
	sp->top--;
	*PopData = sp->stack[sp->top];
	return TRUE;
}

/* Print all data in stack */
void PrintStack(const stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;
	printf("Stack :");
	for (int i = sp->top - 1; i >= 0; i--)
	{
		printf("%d ", sp->stack[i]);
	}
	printf("\n");
}

/* Delete all of the data */
void DestroyStack(stack_t* sp)
{
	/* NULL check */
	if (sp == NULL)
		return;
	free(sp->stack);
	sp->stack = NULL;
	sp->size = 0;
	sp->top = 0;
	return;
}
