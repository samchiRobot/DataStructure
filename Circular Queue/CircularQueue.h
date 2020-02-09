#pragma once
#include "DataType.h"

/* Create queue and initialize */
bool_t CreateQueue(queue_t* qp, int size);

/* Check Queue */
bool_t isQueueEmpty(const queue_t* qp);
bool_t isQueueFull(const queue_t* qp);

bool_t Enqueue(queue_t* qp, int enqueData);
bool_t Dequeue(queue_t* qp, int *dequeData);

void PrintQueue(const queue_t* qp);
void DestroyQueue(queue_t* qp);