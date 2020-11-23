/*
 * linkedList.h
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#ifndef DS_LINKEDLIST_INC_LINKEDLIST_H_
#define DS_LINKEDLIST_INC_LINKEDLIST_H_


struct Node
{
	int data;
	struct Node* next;
};

struct Node* LinkedListInit();

void LinkedListAdd();
void LinkedListRemove();
void LinkedListRemoveAt();
void LinkedListInsert();
void LinkedListGetFrom();
void LinkedListClear();

#endif /* DS_LINKEDLIST_INC_LINKEDLIST_H_ */
