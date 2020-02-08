#pragma once
#include <stdio.h>

typedef enum _bool { FALSE, TRUE }bool_t;

typedef struct _stack
{
	int* stack;
	int size;
	int top;
}stack_t;