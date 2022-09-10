#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void pushnode(struct node**,int);
int popnode(struct node**);
void display(struct node**);
int main()
{
	int x,ch;
	struct node *head;
	head=NULL;
	while(1)
	{
		printf("\n..........................");
		printf("\n. Press 1 for Push.     .");
		printf("\n. Press 2 for Pop.      .");
		printf("\n. Press 3 for Display.  .");
		printf("\n. Press 4 for Peek.     .");
		printf("\n. Press 5 for exit.");
		printf("\n.........................");
		printf("\nEnter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the no.=");
				scanf("%d",&x);
				pushnode(&head,x);
				break;
			case 2:
				x=popnode(&head);
				if(x!=-1)
					printf("\nPopped value=%d",x);
				break;
			case 3:
				display(&head);
				break;
			case 4:
				if(head==NULL)
					printf("\nStack Underflow.");
				else
					printf("\nTop element=%d",head->data);
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong Choice.");
		}
	}
	return 0;
}
void pushnode(struct node **t,int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("\nStack Overflow.");
		return;
	}
	p->data=x;
	p->next=*t;
	*t=p;
}
int popnode(struct node **t)
{
	int n;
	struct node *p;
	if(*t==NULL)
	{
		printf("\nStack Underflow.");
		return (-1);
	}
	n=(*t)->data;
	p=*t;
	*t=(*t)->next;
	free(p);
	return n;
}
void display(struct node **t)
{
	struct node *p;
	int n,i=0;
	p=*t;
	if(p==NULL)
		printf("\nStack Underflow.");
	else
	{
		while(p!=NULL)
		{
			n=p->data;
			printf("\nPostion=%d element=%d",i+1,n);
			i++;
			p=p->next;
		}
	}
}
