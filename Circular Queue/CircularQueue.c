#include "CircularQueue.h"

/* Create queue and initialize */
bool_t CreateQueue(queue_t* qp, int size)
{
	/* NULL check */
	if (qp == NULL)
		return FALSE;

	qp->queue = malloc(sizeof(int)*size);
	if (qp->queue == NULL)
		return FALSE;
	
	/* Initialize values */
	qp->size = size;
	qp->front = qp->rear = 0;

	return TRUE;
}

/* Check Queue */
bool_t isQueueEmpty(const queue_t* qp)
{
	/* NULL check */
	if (qp == NULL)
		return FALSE;

	if (qp->front == qp->rear)
		return TRUE;
	else
		return FALSE;
}

bool_t isQueueFull(const queue_t* qp)
{
	/* NULL check */
	if (qp == NULL)
		return FALSE;

	if (qp->rear == (qp->front + qp->size - 1) % qp->size)
		return TRUE;
	else
		return FALSE;
}

bool_t Enqueue(queue_t* qp, int enqueData)
{
	/* NULL check */
	if (qp == NULL)
		return FALSE;
	
	if (isQueueFull(qp))
		return FALSE;
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear++) % qp->size;
	return TRUE;
}

bool_t Dequeue(queue_t* qp, int* dequeData)
{
	/* NULL check */
	if (qp == NULL)
		return FALSE;

	if (isQueueEmpty(qp))
		return FALSE;
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front++) % qp->size;
	return TRUE;
}

void PrintQueue(const queue_t* qp)
{
	/* NULL check */
	if (qp == NULL)
		return ;
	printf("Result : ");
	for (int i = qp->front; i < qp->rear; i++)
	{
		i = i % qp->size;
		printf("%d ", qp->queue[i]);
	}
	printf("\n");
	return;
}

void DestroyQueue(queue_t* qp)
{
	/* NULL check */
	if (qp == NULL)
		return;

	free(qp->queue);
	qp->queue = NULL;
	qp->size = 0;
	qp->front = 0;
	qp->rear = 0;

	return;
}