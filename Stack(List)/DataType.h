#pragma once
#include <stdio.h>

typedef enum _bool { FALSE, TRUE }bool_t;

typedef struct _node
{
	int data;
	struct _node* next;
}node_t;

typedef struct _stack
{
	node_t* head;
	node_t* tail;
}stack_t;