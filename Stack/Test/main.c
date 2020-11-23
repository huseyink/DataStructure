/*
 ============================================================================
 Name        : main.c
 Author      : Huseyin Koc
 Version     : v_0_0_1
 Copyright   : Use it whatever you want :)
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {

	int islem, kapasite, data;

	printf("Stack kapasite degeri giriniz : ");
	scanf("%d",&kapasite);

	struct Stack* stack = stackInit(kapasite);

	do {

		system("CLS");

		printf( "---ISLEMLER---\n"
				"1.PUSH\n"
				"2.POP\n"
				"3.PEEK\n"
				"4.STACK CAPACITY\n"
				"5.STACK COUNT\n"
				"6.CLEAR STACK\n"
				"7.DISPLAY STACK\n"
				"8.EXIT\n");

		printf("Yapmak istediginiz islem : ");
		scanf("%d",&islem);

		switch( islem )
		{

		case 1:
			printf("Eklemek istediginiz elemani giriniz : ");
			scanf("%d", &data);

			if(stackPush(stack, data) != EXIT_SUCCESS)
			{
				printf("Stack error!\n");
			}

			break;
		case 2:
			if( stackPop(stack, &data) != EXIT_SUCCESS)
			{
				printf("Stack error!\n");
			}

			break;
		case 3:
			if( stackPeek(stack, &data) != EXIT_SUCCESS )
			{
				printf("Stack error!\n");
			}
			break;
		case 4:
			printf("Stack kapasitesi %d\n", stackGetCapacity(stack));
			break;
		case 5:
			printf("Stack count %d\n",stackGetCount(stack));
			break;
		case 6:
			stackClear(&stack);
			break;
		case 7:
			stackDisplay(stack);
			break;
		}


		system("pause");

	}while(islem != 8);

	return EXIT_SUCCESS;
}
