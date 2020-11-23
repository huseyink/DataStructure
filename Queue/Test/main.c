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

#include "queue.h"

int main(void) {

	int islem, kapasite, data;

	printf("Queue kapasite degeri giriniz : ");
	scanf("%d",&kapasite);

	struct Queue* queue = queueInit(kapasite);

	do {

		system("CLS");

		printf( "---ISLEMLER---\n"
				"1.PUSH\n"
				"2.POP\n"
				"3.PEEK\n"
				"4.QUEUE CAPACITY\n"
				"5.QUEUE COUNT\n"
				"6.CLEAR QUEUE\n"
				"7.DISPLAY QUEUE\n"
				"8.EXIT\n");

		printf("Yapmak istediginiz islem : ");
		scanf("%d",&islem);

		switch( islem )
		{

		case 1:
			printf("Eklemek istediginiz elemani giriniz : ");
			scanf("%d", &data);

			if(queuePush(queue, data) != EXIT_SUCCESS)
			{
				printf("queue error!\n");
			}

			break;
		case 2:
			if( queuePop(queue, &data) != EXIT_SUCCESS)
			{
				printf("queue error!\n");
			}

			break;
		case 3:
			if( queuePeek(queue, &data) != EXIT_SUCCESS )
			{
				printf("queue error!\n");
			}
			break;
		case 4:
			//printf("queue kapasitesi %d\n", queueGetCapacity(queue));
			break;
		case 5:
			//printf("queue count %d\n",queueGetCount(queue));
			break;
		case 6:
			queueClear(&queue);
			break;
		case 7:
			queueDisplay(queue);
			break;
		}


		system("pause");

	}while(islem != 8);

	return EXIT_SUCCESS;
}
