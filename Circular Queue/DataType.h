#pragma once
#include <stdio.h>

typedef enum _bool { FALSE, TRUE }bool_t;

typedef struct _queue
{
	int* queue;
	int size;
	int front;
	int rear;
}queue_t;