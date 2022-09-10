#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct queue
{
	int list[MAX];
	int front,rear;
};
void enqueue(struct queue*,int);
int dequeue(struct  queue*);
void display(struct queue*);
int main()
{
	struct queue q;
	int ch,x,p;
	q.rear=-1;
	q.front=-1;
	while(1)
	{
		printf("\n............................");
		printf("\n. Press 1 for insert.      .");
		printf("\n. Press 2 for retrieve.    .");
		printf("\n. Press 3 for peek.        .");
		printf("\n. Press 4 for Display.     .");
		printf("\n. Press 5 for exit.        .");
		printf("\nEnter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the no=");
				scanf("%d",&x);
				enqueue(&q,x);
				break;
			case 2:
				p=dequeue(&q);
				if(p!=-1)
					printf("\nDequeued element=%d",p);
				break;
			case 3:
				if(q.front==-1)
					printf("\nUnderflow.");
				else
					printf("\nThe front value=%d and rear value=%d",q.list[q.front],q.list[q.rear]);
				break;
			case 4:
				display(&q);
				break;
			case 5:
				printf("\nprogramme over.");
				exit(0);
			default:
				printf("\nWrong choice.");
		}
	}
	return 0;
}
void enqueue(struct queue *qp,int x)
{
	if(qp->rear==MAX-1)
	{
		printf("\nOverflow.");
		return;
	}
	if(qp->rear==-1)
		(qp->front)++;
	qp->list[++(qp->rear)]=x;
}
int dequeue(struct queue *qp)
{
	int v;
	if(qp->front==-1)
	{
		printf("\nUnderflow.");
		return (-1);
	}
	v=qp->list[qp->front];
	if(qp->front==qp->rear)
	{
		qp->front=-1;
		qp->rear=-1;
	}
	else
		(qp->front)++;
	return v;
}
void display(struct queue *qp)
{
	int i;
	if(qp->front==-1)
		printf("\nQueue Underflow.");
	else
	{
		printf("\nRemaining elements=\n");
		for(i=qp->front;i<=qp->rear;i++)
			printf("\nQUeue Element=%d",qp->list[i]);
	}
}
