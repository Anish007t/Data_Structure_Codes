#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int QUEUE[MAX],FRONT=-1,REAR=-1;
void store(int x);
int retrieve();
void display();
int main()
{
	int val,prompt;
	while(1)
	{
		printf("\n..........................");
		printf("\n. Press 1 to Store.      .");
		printf("\n. Press 2 for retrieve.  .");
		printf("\n. Press 3 to Display.    .");
		printf("\n. Press 4 for peek.      .");
		printf("\n. Press 5 for exit.      .");
		printf("\n..........................");
		printf("\nEnter your choice=");
		scanf("%d",&prompt);
		switch(prompt)
		{
			case 1:
				printf("\nEnter the value=");
				scanf("%d",&val);
				store(val);
				break;
			case 2:
				val=retrieve();
				if(val!=0)
					printf("\nRetrieved value=%d",val);
				break;
			case 3:
				display();
				break;
			case 4:
				if(FRONT==-1)
				printf("\nQUEUE Underflow.");
				else
					printf("\nFront element=%d\nRear element=%d",QUEUE[FRONT],QUEUE[REAR]);
				break;
			case 5:
				printf("\nProgramme operation is over.");
				exit(0);
			default:
				printf("\nEntered choice is not correct.");
		}
		printf("\n\n\n");
	}
	return 0;
}
void store(int x)
{
	if(REAR==MAX-1)
	{
		printf("\nQueue Overflow.");
		return;
	}
	if(REAR==-1)
		++FRONT;
	QUEUE[++REAR]=x;
}
int retrieve()
{
	int val;
	if(FRONT==-1)
	{
		printf("\nQueue Underflow.");
		return 0;
	}
	val=QUEUE[FRONT];
	if(FRONT==REAR)
	{
		FRONT=-1;
		REAR=-1;
	}
	else
		++FRONT;
	return val;
}
void display()
{
	int i;
	if(FRONT==-1)
		printf("\nQueue Underflow.");
	else
	{
		printf("\nRemaining elements=\n");
		for(i=FRONT;i<=REAR;i++)
			printf("\nQUeue Element=%d",QUEUE[i]);
	}
}
