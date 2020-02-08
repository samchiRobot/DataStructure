#pragma once
#include "DataType.h"

/* Array Stack Initiailization */
bool_t CreateStack(stack_t* sp, int size);

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
