/*
 * LinkedList.c
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

struct LinkedList* LinkedListInit()
{
	struct LinkedList* linkedList = (struct LinkedList*)malloc(sizeof(struct LinkedList));

	if( linkedList == NULL )
	{
		perror(NULL);
		return NULL;
	}

	linkedList->head = NULL;
	return linkedList;
}

int LinkedListAdd(struct LinkedList* linkedList, const int data)
{
	Node* current = linkedList->head;
	Node* new = (Node*)malloc(sizeof(Node));

	if(new == NULL)
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	new->data = data;
	new->next = NULL;

	if( current == NULL )
	{
		linkedList->head = new;
		return EXIT_SUCCESS;
	}

	/*
	 * TODO :
	 * For now, Single LinkedList is used so the time complexity is O(n).
	 * Time complexity will be O(1) by using Doubly LinkedList.
	 */
	while( current->next != NULL)
	{
		current = current->next;
	}

	current->next = new;

	return EXIT_SUCCESS;
}

int LinkedListInsert(struct LinkedList* linkedList, const int data, unsigned int index)
{
	Node* current = linkedList->head;
	Node* prev = NULL;
	Node* new = (Node*)malloc(sizeof(Node));

	if(new == NULL)
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	new->data = data;
	new->next = NULL;

	if( index == 0 )
	{
		new->next = linkedList->head;
		linkedList->head = new;

		return EXIT_SUCCESS;
	}

	while( index != 0 )
	{
		// If given index is too much than current node numbers??
		if(current == NULL)
		{
			perror("Given index is wrong!");
			return EXIT_FAILURE;
		}

		prev = current;
		current = current->next;
		index--;
	}

	new->next = prev->next;
	prev->next = new;

	return EXIT_SUCCESS;
}

int LinkedListRemove(struct LinkedList* linkedList, const int data)
{
	if( linkedList == NULL )
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	Node* current = linkedList->head;
	Node* prev = NULL;

	// If the searched data is in head node??
	if( current->data == data )
	{
		linkedList->head = current->next;
		free(current);

		return EXIT_SUCCESS;
	}

	while( current != NULL )
	{
		if( current->data == data )
		{
			prev->next = current->next;
			free(current);
			current = NULL;

			return EXIT_SUCCESS;
		}

		prev = current;
		current = current->next;
	}

	perror("The given value is not in the List!\n");
	return EXIT_FAILURE;
}

int LinkedListRemoveAt(struct LinkedList* linkedList, unsigned int index)
{
	Node* current = linkedList->head;
	Node* prev = NULL;

	if( linkedList == NULL || current == NULL )
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	// If given index is head node??
	if( index == 0 )
	{
		linkedList->head = current->next;
		free(current);

		return EXIT_SUCCESS;
	}

	while( index != 0 )
	{
		// If given index is too much than current node numbers??
		if(current == NULL)
		{
			perror("Given index is wrong!");
			return EXIT_FAILURE;
		}

		prev = current;
		current = current->next;
		index--;
	}

	prev->next = current->next;
	free(current);
	current = NULL;

	return EXIT_SUCCESS;
}

int LinkedListGetFrom(struct LinkedList* linkedList, unsigned int index, int* data)
{
	Node* current = linkedList->head;

	if( linkedList == NULL || current == NULL )
	{
		perror(NULL);
		return EXIT_FAILURE;
	}

	while( index != 0 )
	{
		current = current->next;
		index--;

		// If given index is too much than current node numbers??
		if(current == NULL)
		{
			perror("Given index is wrong!");
			return EXIT_FAILURE;
		}
	}

	*data = current->data;

	return EXIT_SUCCESS;

}

void LinkedListClear(struct LinkedList* linkedList)
{
	Node* current = linkedList->head;

	if( linkedList == NULL && current == NULL )
	{
		perror(NULL);
	}

	while( current != NULL )
	{
		current = current->next;
		free(linkedList->head);
		linkedList->head = current;
	}
}

void LinkedListDisplay(const struct LinkedList* linkedList)
{
	Node* tmp = linkedList->head;

	if( linkedList == NULL || tmp == NULL )
	{
		perror("LinkedList is empty!");
		return;
	}

	while( tmp != NULL )
	{
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}

	printf("\n");
}













