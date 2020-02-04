#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/* Linked List Initiailization */
bool_t CreateList(list_t* lp)
{
	/* NULL check*/
	if (lp == NULL)
		return FALSE;
	
	/* Create Head Node */
	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL)
		return FALSE;
	head->data = 0;
	head->next = NULL;
	lp->head = head;

	/* Create Tail Node */
	node_t* tail = NULL;
	tail = malloc(sizeof(node_t));
	if (tail == NULL)
	{
		free(head);
		return FALSE;
	}
	tail->data = 0;
	tail->next = NULL;
	lp->tail = tail;

	/* Connect between head node and tail node */
	head->next = tail;

	/* Set the tail node's next point to itself */
	tail->next = tail;

	/* Set linked list size to zero */
	lp->size = 0;

	return TRUE;
}


/* Add node after the head node */
bool_t AddFirst(list_t* lp, int data)
{
	/* NULL check */
	if (lp == NULL)
		return FALSE;

	/* Create new node */
	node_t* np = NULL;
	np = malloc(sizeof(node_t));
	if (np == NULL)
		return FALSE;

	/* Apply data to new node */
	np->data = data;

	/* Set next pointer */
	np->next = lp->head->next;
	lp->head->next = np;

	/* Increase list size */
	++lp->size;

	return TRUE;
}

/* Add node before the tail node */
bool_t AddLast(list_t* lp, int data)
{
	/* NULL check */
	if (lp == NULL)
		return FALSE;

	/* Create new node */
	node_t* np = NULL;
	np = malloc(sizeof(node_t));
	if (np == NULL)
		return FALSE;

	/* Apply data to new node */
	np->data = data;

	/* Search a node just before the tail node */
	node_t* tp = lp->head;
	while (tp->next != lp->tail)
		tp = tp->next;

	/* Set next pointer */
	tp->next = np;
	np->next = lp->tail;

	/* Increase list size */
	++lp->size;

	return TRUE;
}

/* Print all data in the list*/
void DisplayList(list_t* lp)
{
	/* NULL check */
	if (lp == NULL)
		return;

	/* Set first node */
	node_t* tp = lp->head->next;

	/* Print data */
	while (tp != lp->tail)
	{
		printf("%d ", tp->data);
		tp = tp->next;
	}
	printf("\n");
}

/* Search for node that match the presented data */
node_t* SearchNode(list_t* lp, int data)
{
	/* NULL check */
	if (lp == NULL)
		return NULL;
	
	/* Select first node */
	node_t* np = lp->head->next;

	/* Find node up to tail node */
	while (np->data != data)
	{
		if (np->data == data)
			return np;
		if (np == lp->tail)
			return NULL;
		np = np->next;
	}
}

/* Delete the data node */
bool_t RemoveNode(list_t* lp, int data)
{
	/* NULL check */
	if (lp == NULL)
		return FALSE;

	/* Search node pointer to delete */
	node_t *dp = SearchNode(lp, data);
	if (dp == NULL)
		return FALSE;

	/* Search node pointer before the node to delete*/
	node_t* np = lp->head;
	while (np->next != dp)
		np = np->next;

	/* Connect np and dp->next */
	np->next = dp->next;

	/* Delete the node and decrease the lp->size*/
	free(dp);
	--lp->size;
	return TRUE;
}

/* Sort node (Bubble sort)*/
/* mode : 0 - Ascending order, 1 - Descending order */
void SortList(list_t* lp, int mode)
{
	/* Null check */
	if (lp == NULL)
		return;
	node_t* np = lp->head;
	node_t* tp = np->next;
	int temp = 0;
	for (int i = 0; i < lp->size - 1; i++)
	{
		for (int j = 0; j < lp->size - i - 1; j++)
		{
			// TODO
		}
	}
}

/* Delete all of the nodes*/
void DestroyList(list_t* lp);
