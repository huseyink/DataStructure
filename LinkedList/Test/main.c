/*
 * main.c
 *
 *  Created on: 23 Kas 2020
 *      Author: Huseyink
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main()
{
	struct LinkedList* linkedList = LinkedListInit();

	if( linkedList != NULL )
	{
		LinkedListAdd(linkedList, 10);
		LinkedListAdd(linkedList, 20);
		LinkedListAdd(linkedList, 30);
		LinkedListAdd(linkedList, 30);

		LinkedListDisplay(linkedList);
	}


	LinkedListInsert(linkedList, 40, 0);
	LinkedListDisplay(linkedList);

	LinkedListClear(linkedList);

	LinkedListAdd(linkedList, 10);
	LinkedListAdd(linkedList, 20);
	LinkedListAdd(linkedList, 30);
	LinkedListAdd(linkedList, 30);

	LinkedListDisplay(linkedList);

	system("pause");
	return EXIT_SUCCESS;
}
