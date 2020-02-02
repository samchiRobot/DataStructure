#pragma once
#include "DataType.h"

/* Linked List Initiailization */
bool_t CreateList(list_t* lp);

/* Add node after the head node */
bool_t AddFirst(list_t* lp, int data);

/* Add node before the tail node */
bool_t AddLast(list_t* lp, int data);

/* Print all data in the list*/
void DisplayList(list_t* lp);

/* Search for node that match the presented data */
node_t* SearchNode(list_t* lp, int data);

/* Delete the data node */
bool_t RemoveNode(list_t* lp, int data);

/* Sort node - Ascending order*/
void SortList(list_t* lp);

/* Delete all of the nodes*/
void DestroyList(list_t* lp);