#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int cq[MAX];
int front=-1,rear=-1;
void insert(int);
void deletion();
void display();
int main()
{
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
				insert(item);
				break;
			case 2:
				deletion();
				break;
			case 3:
				if(front==-1 && rear==-1)
					printf("\nQueue Underflow!!!");
				else
					printf("Front element=%d\nRear element=%d",cq[front],cq[rear]);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong choice");
		}
	}while(1);
	return 0;
}
void insert(int item)
{
	if(front==(rear+1)%MAX)
		printf("\nQueue Overflow.");
	else
	{
		if(front==-1 & rear==-1)
			front=rear=0;
		else
			rear=(rear+1)%MAX;
		cq[rear]=item;
	}
}
void deletion()
{
	if(front==-1 & rear==-1)
		printf("\nQueue Underflow.");
	else
	{
		printf("\nDequed element=%d",cq[front]);
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%MAX;
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue Underflow!!!");
	}
	else
	{
		printf("\nQueue elements=");
        for(i=front;i!=rear;i=(i+1)%MAX)
        {
            printf("%d ",cq[i]);
        }
		printf("%d ",cq[i]);
    }
}