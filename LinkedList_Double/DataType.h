#pragma once
#include <stdio.h>

typedef enum _bool {FALSE, TRUE}bool_t;

typedef struct _node 
{
	int data;
	struct _node* next;
	struct _node* prev;
}node_t;

typedef struct _list
{
	node_t* head;
	node_t* tail;
	int size;
}list_t;