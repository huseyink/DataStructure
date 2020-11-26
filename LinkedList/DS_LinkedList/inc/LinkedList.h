/*
 * linkedList.h
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#ifndef DS_LINKEDLIST_INC_LINKEDLIST_H_
#define DS_LINKEDLIST_INC_LINKEDLIST_H_


typedef struct Node_t
{
	int data;
	struct Node_t* next;
}Node;

struct LinkedList
{
	Node* head;
};

struct LinkedList* LinkedListInit();
int LinkedListAdd(struct LinkedList* linkedList, const int data);
int LinkedListInsert(struct LinkedList* linkedList, const int data, unsigned int index);
int LinkedListRemove(struct LinkedList* linkedList, const int data);
int LinkedListRemoveAt(struct LinkedList* linkedList, unsigned int index);
int LinkedListGetFrom(struct LinkedList* linkedList, unsigned int index, int* data);
void LinkedListClear(struct LinkedList* linkedList);
void LinkedListDisplay(const struct LinkedList* linkedList);

#endif /* DS_LINKEDLIST_INC_LINKEDLIST_H_ */
