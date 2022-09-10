#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 100
struct stack
{
	int list[size];
	int top;
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack);
int main()
{
	struct stack s;
	int opt,x,n;
	s.top=-1;
	while(1)
	{
		printf("\n...........................");
		printf("\n. Press 1 for push.       .");
		printf("\n. Press 2 for pop.        .");
		printf("\n. Press 3 for display.    .");
		printf("\n. Press 4 for peek.       .");
		printf("\n. Press 5 for exit.       .");
		printf("\n...........................");
		printf("\nEnter your choice:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter the no.=");
				scanf("%d",&x);
				push(&s,x);
				break;
			case 2:
				n=pop(&s);
				if(n!=-1)
				  printf("\nPopped value:%d",n);
				break;
			case 3:
				display(s);
				break;
			case 4:
				if(s.top==-1)
					printf("\nStack is empty.");
				else
					printf("\nTop element=%d",s.list[s.top]);
				break;
			case 5:
				printf("\nProgramme operation is over.");
				exit(0);
			default:
				printf("\nEntered choice is not correct.");
		}
		printf("\n\n\n");
	}
	getch();
	return 0;
}
void push(struct stack *sp,int x)
{
	if(sp->top==size-1)
	{
		printf("\nOverflow");
		return;
	}
	sp->list[++sp->top]=x;
	return;
}
int pop(struct stack *sp)
{
	if(sp->top==-1)
	{
		printf("\nstack is empty.");
		return (-1);
	}
	return(sp->list[sp->top--]);
}
void display(struct stack sp)
{
	int i=sp.top;
	if(sp.top==-1)
	{
		printf("\nStack is empty.");
		return;
	}
	printf("\nRemaining elements is stacks:");
	while(i>=0)
	{
		printf("\nTop element=%d",sp.list[sp.top]);
		sp.top--;
		i--;
	}
}
