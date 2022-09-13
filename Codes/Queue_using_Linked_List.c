#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;
void enqueue(QUEUE *qp,int item)
{
	NODE *q;
	q=(NODE*)malloc(sizeof(NODE));
	if(q==NULL)
	{
		printf("\nQueue full.");
		return;
	}
	q->data=item;
	q->next=NULL;
	if(qp->rear==NULL)
	{
		qp->front=q;
		qp->rear=q;
	}
	else
	{
		(qp->rear)->next=q;
		qp->rear=(qp->rear)->next;
	}
}
int dequeue(QUEUE *qp)
{
	NODE* q;
	int item;
	if(qp->front==NULL)
	{
		printf("\nQueue is empty.");
		return (-1);
	}
	item=(qp->front)->data;
	q=qp->front;
	if(qp->front==qp->rear)
	{
		qp->front=NULL;
		qp->rear=NULL;
	}
	else
		qp->front=(qp->front)->next;
	free(q);
	return item;
}
void display(QUEUE *qp)
{
	NODE *temp;
	if(qp->front==NULL)
	{
		printf("\nQueue is empty.");
	}
	else
	{
		temp=qp->front;
		printf("\nQueue elements=");
		while(temp->next!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d ",temp->data);
	}
}
int main()
{
	int x,i,n,prompt;
	QUEUE que;
	que.front=que.rear=NULL;
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
				scanf("%d",&x);
				enqueue(&que,x);
				break;
			case 2:
				x=dequeue(&que);
				if(x!=-1)
					printf("\nRetrieved value=%d",x);
				break;
			case 3:
				display(&que);
				break;
			case 4:
				if(que.front==NULL)
				printf("\nQUEUE Underflow.");
				else
					printf("\nFront element=%d\nRear element=%d",(que.front)->data,(que.rear)->data);
				break;
			case 5:
				printf("\nProgramme operation is over.");
				exit(0);
			default:
				printf("\nEntered choice is not correct.");
		}
	}
	return 0;
}
