#pragma once
#include <stdio.h>

typedef enum _bool {FALSE, TRUE}bool_t;

typedef struct _heap
{
	int* heap;	// heap space
	int size;	// heap size
	int count;	// number of data
}heap_t;
