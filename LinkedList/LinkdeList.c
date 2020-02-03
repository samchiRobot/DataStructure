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
node_t* SearchNode(list_t* lp, int data);

/* Delete the data node */
bool_t RemoveNode(list_t* lp, int data);

/* Sort node - Ascending order*/
void SortList(list_t* lp);

/* Delete all of the nodes*/
void DestroyList(list_t* lp);
