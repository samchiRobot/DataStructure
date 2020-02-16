#pragma once
#include "DataType.h"

bool_t CreateHeap(heap_t* hp, int size);

bool_t isHeapEmpty(heap_t* hp);
bool_t isHeapFull(heap_t* hp);
bool_t InsertHeap(heap_t* hp, int data);
bool_t DeleteHeap(heap_t* hp, int* data);

void reHeapUp(heap_t* hp, int child);
void reHeapDown(heap_t* hp, int parent);

void PrintHeap(const heap_t* hp);
void DestroyHeap(heap_t* hp);