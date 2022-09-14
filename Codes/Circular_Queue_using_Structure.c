#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct circular_queue
{
	int list[MAX];
	int front=-1,rear=-1;
}queue;
void insert(int,queue*);
void deletion(queue*);
void display(queue);
int main()
{
	queue cq;
	int choice,item;
	do{
		printf("\n...........................");
		printf("\n. Press 1 for Insert.     .");
		printf("\n. Press 2 for Retreive.   .");
		printf("\n. Press 3 for Peek.       .");
		printf("\n. Press 4 for Display.    .");
		printf("\n. Press 5 for Exit.       .");
		printf("\n...........................");
		printf("\nEnter your choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element=");
				scanf("%d",&item);
				insert(item,&cq);
				break;
			case 2:
				deletion(&cq);
				break;
			case 3:
				if(cq.front==-1 && cq.rear==-1)
					printf("\nQueue Underflow!!!");
				else
					printf("Front element=%d\nRear element=%d",cq.list[cq.front],cq.list[cq.rear]);
				break;
			case 4:
				display(cq);
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong choice");
		}
	}while(1);
	return 0;
}
void insert(int item,queue *cq)
{
	if(cq->front==(cq->rear+1)%MAX)
		printf("\nQueue Overflow.");
	else
	{
		if(cq->front==-1 & cq->rear==-1)
			cq->front=cq->rear=0;
		else
			cq->rear=(cq->rear+1)%MAX;
		cq->list[cq->rear]=item;
	}
}
void deletion(queue *cq)
{
	if(cq->front==-1 & cq->rear==-1)
		printf("\nQueue Underflow.");
	else
	{
		printf("\nDequed element=%d",cq->list[cq->front]);
		if(cq->front==cq->rear)
			cq->front=cq->rear=-1;
		else
			cq->front=(cq->front+1)%MAX;
	}
}
void display(queue cq)
{
	int f=cq.front,r=cq.rear;
	if(cq.front==-1)
	{
		printf("\nQueue Underflow!!!");
	}
	else
	{
		printf("\nQueue elements=");
		if(f<=r)
			while(f<=r)
			{
				printf("%d ",cq.list[f]);
				f++;
			}
		else
		{
			while(f<=MAX-1)
			{
				printf("%d ",cq.list[f]);
				f++;
			}
		}
		printf("\n");
	}
}
