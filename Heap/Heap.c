#include "Heap.h"
#include <stdlib.h>

bool_t CreateHeap(heap_t* hp, int size)
{
	// Null check
	if (hp == NULL)
		return FALSE;

	hp->heap = (int*)calloc(size + 1, sizeof(int));
	if (hp->heap == NULL)
		return FALSE;

	hp->size = size;
	hp->count = 0;
	hp->heap[0] = INT_MAX;
	return TRUE;
}

bool_t isHeapEmpty(heap_t* hp)
{
	// Exception handling
	if (hp == NULL)
		return TRUE;	
	if (hp->count == 0)
		return TRUE;
	return FALSE;
}

bool_t isHeapFull(heap_t* hp)
{
	// Exception handling
	if (hp == NULL)
		return TRUE;	
	if (hp->count == hp->size)
		return TRUE;
	return FALSE;
}

bool_t InsertHeap(heap_t* hp, int data)
{
	// Null chechk
	if (hp == NULL)
		return FALSE;

	if (isHeapFull(hp))
		return FALSE;

	hp->count++;
	hp->heap[hp->count] = data;
	reHeapUp(hp, hp->count);
	return TRUE;
}

bool_t DeleteHeap(heap_t* hp, int* data)
{
	if (hp == NULL)
		return FALSE;
	if (isHeapEmpty(hp))
		return FALSE;

	*data = hp->heap[1];
	hp->heap[1] = hp->heap[hp->count];
	hp->count--;
	reHeapDown(hp, 1);
	return TRUE;
}

void reHeapUp(heap_t* hp, int child)
{
	int parent = child / 2;

	int temp = 0;
	while (hp->heap[parent] > hp->heap[child] && hp->count > 1)
	{
		if (parent == 0 || child == 0)
			break;
		temp = hp->heap[parent];
		hp->heap[parent] = hp->heap[child];
		hp->heap[child] = temp;

		child = child / 2;
		parent = child / 2;
	}
	return;
}

void reHeapDown(heap_t* hp, int parent)
{
	if (parent == 0)
		return;
	int cL = 0;
	int cR = 0;
	int child = 0;
	int temp = 0;
	while (parent < hp->count)
	{
		cL = parent * 2;
		cR = parent * 2 + 1;
		if (cR <= hp->count)
			child = hp->heap[cL] < hp->heap[cR] ? cL : cR;
		else if (cL <= hp->count)
			child = cL;

		if (hp->heap[child] < hp->heap[parent] && hp->count > 1)
		{
			temp = hp->heap[parent];
			hp->heap[parent] = hp->heap[child];
			hp->heap[child] = hp->heap[parent];
		}
		parent = child;
	}
	return;
}

void PrintHeap(const heap_t* hp)
{
	printf("Heap : ");
	if (hp->count >= 1)
	{
		for (int i = 1; i <= hp->count; ++i)
		{
			printf("%d ", hp->heap[i]);
		}
	}
	printf("\n Count : %d\n Size : %d\n", hp->count, hp->size);
	return;
}

void DestroyHeap(heap_t* hp)
{
	if (hp == NULL)
		return;
	free(hp->heap);
	hp->heap = NULL;
	hp->size = 0;
	hp->count = 0;
	return;
}