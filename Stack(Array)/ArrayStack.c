#pragma once
#include "ArrayStack.h"
#include <stdlib.h>

/* Array Stack Initiailization */
bool_t CreateStack(stack_t* sp, int size)
{
	/* NULL check */
	if (sp == NULL)
		return FALSE;

	/* Stack Memory Allocation */
	sp = (stack_t *)malloc(sizeof(stack_t));
	if (sp == NULL)
		return FALSE;

	/* Initialize */
	sp->size = 0;
	sp->top = 0;
	sp->stack = (int*)malloc(sizeof(int) * size);
	if (sp->stack == NULL)
		return FALSE;

	return TRUE;
}

/* Check Stack State */
bool_t isStackFull(stack_t* sp);
bool_t isStackEmpty(stack_t* sp);

/* Push/Pop Data */
bool_t Push(stack_t* sp, int PushData);
bool_t Pop(stack_t* sp, int* PopData);

/* Print all data in stack */
void PrintStack(const stack_t* sp, void(*print)(int));
void PrintInt(int data);

/* Delete all of the data */
void DestroyStack(stack_t* sp);
