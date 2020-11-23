/*
 * stack.c
 *
 *  Created on: 22 Kas 2020
 *      Author: Huseyink
 */

#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "stack.h"


struct Stack* stackInit(unsigned int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

	if( stack != NULL)
	{
		stack->capacity = capacity;
		stack->count = -1;
		stack->array = (int*)malloc(stack->capacity * sizeof(int));

		return stack;
	}

#ifdef DEBUG
	printf("Stack olusturulamadi!\n");
#endif

	return NULL;
}


int stackIsFull(const struct Stack* stack)
{
	return stack->count == (stack->capacity - 1);
}


int stackPush(struct Stack* stack, const int data)
{
	if( stack != NULL)
	{
		if( stackIsFull(stack) )
		{

#ifdef DEBUG
			printf("Stack overflow error!\n");
#endif

			return EXIT_FAILURE;
		}

		stack->array[++stack->count] = data;

#ifdef DEBUG
		printf("%d stack'e eklendi.\n",data);
#endif
		return EXIT_SUCCESS;
	}

#ifdef DEBUG
	printf("Stack olusturulamadi!\n");
#endif

	return EXIT_FAILURE;
}


int stackIsEmpty(const struct Stack* stack)
{
	return (stack->count == -1);
}


int stackPop(struct Stack* stack, int* data)
{
	if( stack != NULL )
	{
		if( stackIsEmpty(stack) )
		{
			printf("Stack underflow error!\n");
			return EXIT_FAILURE;
		}

		*data = stack->array[stack->count--];

#ifdef DEBUG
		printf("%d stack'ten silindi.\n",*data);
#endif

		return EXIT_SUCCESS;
	}

#ifdef DEBUG
	printf("Stack olusturulamadi!\n");
#endif

	return EXIT_FAILURE;
}


int stackPeek(struct Stack* stack, int* data)
{
	if( stack != NULL )
	{
		if( !stackIsEmpty(stack) )
		{
			*data = stack->array[stack->count];

#ifdef DEBUG
			printf("%d stack'ten okundu\n",*data);
#endif
			return EXIT_SUCCESS;
		}

#ifdef DEBUG
		printf("Stack underflow error!\n");
#endif
		return EXIT_FAILURE;
	}

#ifdef DEBUG
	printf("Stack olusturulamadi!\n");
#endif

	return EXIT_FAILURE;
}


void stackClear(struct Stack** stack)
{
	if((*stack)->array != NULL)
	{
		free((*stack)->array);
		(*stack)->array = NULL;
	}

	free(*stack);
	*stack = NULL;
}

void stackDisplay(const struct Stack* stack)
{
	if(stack != NULL)
	{
		if( !stackIsEmpty(stack) )
		{
			for(int i = stack->count; i >= 0; i--)
			{
				printf("%d\n",stack->array[i]);
			}
		}
		else
		{
#ifdef DEBUG
			printf("Stack underflow error!\n");
#endif
		}
	}
	else
	{
#ifdef DEBUG
		printf("Stack olusturulamadi!\n");
#endif
	}

}

int stackGetCount(const struct Stack* stack)
{
	return (stack != NULL) ? stack->count + 1 : INT_MIN;
}

int stackGetCapacity(const struct Stack* stack)
{
	return (stack != NULL) ? stack->capacity : INT_MIN;
}

