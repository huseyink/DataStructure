/*
 * queue.c
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#define DEBUG

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct Queue* queueInit(unsigned int capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

	if( queue != NULL)
	{
		queue->capacity = capacity;
		queue->data = (int*)malloc(queue->capacity * sizeof(int));
		queue->rear = -1;
		queue->front = queue->count = 0;
	}

	return queue;
}

int queueIsFull(struct Queue* queue)
{
	return (queue->count == queue->capacity);
}

int queueIsEmpty(struct Queue* queue)
{
	return (queue->count == 0);
}

int queuePush(struct Queue* queue, const int data)
{
	if( queue != NULL )
	{
		if( !queueIsFull(queue) )
		{
			queue->rear = (queue->rear + 1) % queue->capacity;
			queue->data[queue->rear] = data;
			queue->count++;

#ifdef DEBUG
			printf("%d kuyruga eklendi.\n",data);
#endif
			return EXIT_SUCCESS;
		}
#ifdef DEBUG
			printf("Kuyruk dolu!\n");
#endif
			return EXIT_FAILURE;
	}

#ifdef DEBUG
			printf("Kuyruk yok!\n");
#endif
			return EXIT_FAILURE;
}

int queuePop(struct Queue* queue, int* data)
{
	if( queue != NULL )
	{
		if( !queueIsEmpty(queue) )
		{
			*data = queue->data[queue->front];
			queue->front = (queue->front + 1) % queue->capacity;
			queue->count--;


#ifdef DEBUG
			printf("%d kuyruktan cikarildi!\n",*data);
#endif
			return EXIT_SUCCESS;
		}
#ifdef DEBUG
			printf("Kuyruk bos!\n");
#endif
			return EXIT_FAILURE;
	}

#ifdef DEBUG
			printf("Kuyruk yok!\n");
#endif
			return EXIT_SUCCESS;
}

int queuePeek(struct Queue* queue, int* data)
{
	if( queue != NULL )
	{
		if( !queueIsEmpty(queue) )
		{
			*data = queue->data[queue->front];
#ifdef DEBUG
			printf("%d kuyrugun basindaki elemandir!\n",*data);
#endif
			return EXIT_SUCCESS;
		}

#ifdef DEBUG
			printf("Kuyruk bos!\n");
#endif
		return EXIT_FAILURE;
	}

#ifdef DEBUG
			printf("Kuyruk yok!\n");
#endif
			return EXIT_FAILURE;
}

void queueClear(struct Queue** queue)
{
	if( *queue != NULL )
	{
		free((*queue)->data);
		(*queue)->data = NULL;
	}

	free(*queue);
	*queue = NULL;

#ifdef DEBUG
			printf("Kuyruk silindi!\n");
#endif
}

void queueReset(struct Queue* queue)
{
	if( queue != NULL )
	{
		free(queue);
		queue = NULL;

		queue = queueInit(5);
	}
}

#ifdef DEBUG
void queueDisplay(struct Queue* queue)
{
	if( queue != NULL )
	{
		if( !queueIsEmpty(queue) )
		{
			for( int i = queue->rear; i >= queue->front; i--)
			{
				printf("%d - ",queue->data[i]);
			}
			printf("\n");
		}

	}
}
#endif
