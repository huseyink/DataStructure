/*
 * queue.h
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#ifndef DS_QUEUE_INC_QUEUE_H_
#define DS_QUEUE_INC_QUEUE_H_


struct Queue
{
	int front, rear;
	unsigned int capacity;
	int count;
	int* data;
};


struct Queue* queueInit(unsigned int capacity);

int queueIsFull(struct Queue* queue);

int queueIsEmpty(struct Queue* queue);

int queuePush(struct Queue* queue, const int data);

int queuePop(struct Queue* queue, int* data);

int queuePeek(struct Queue* queue, int* data);

void queueClear(struct Queue** queue);

void queueDisplay(struct Queue* queue);

void queueReset(struct Queue* queue);

#endif /* DS_QUEUE_INC_QUEUE_H_ */
