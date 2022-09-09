#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],TOP=-1;
void push(int x);
int pop();
void display();
int main()
{
	int val,prompt;
	while(1)
	{
		printf("\n..............................");
		printf("\n. Press 1 for push data.     .");
		printf("\n. Press 2 for pop data.      .");
		printf("\n. Press 3 for display data.  .");
		printf("\n. Press 4 for peek.          .");
		printf("\n. Press 5 for exit.          .");
		printf("\n..............................");
		printf("\nEnter your choice=");
		scanf("%d",&prompt);
		switch(prompt)
		{
			case 1:
				printf("\nEnter the value to push=");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				val=pop();
				if(val!=0)
					printf("\nPopped element=%d",val);
				break;
			case 3:
				display();
				break;
			case 4:
				if(TOP==-1)
					printf("\nStack Underflow.");
				else
					printf("\nTop element=%d",stack[TOP]);
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
void push(int x)
{
	if(TOP==MAX-1)
		printf("\n!!!Stack Overflow!!!");
	else
		stack[++TOP]=x;
}
int pop()
{
	if(TOP==-1)
	{
		printf("\n!!!Stack Underflow!!!");
		return 0;
	}
	else
	   return stack[TOP--];
}
void display()
{
	int i=TOP;
	if(TOP==-1)
	{
		printf("\n!!!Stack Underflow!!!");
		return;
	}
	printf("\nThe remaining elements=\n");
	while(i>=0)
	{
		printf("\nThe stack element is %d",stack[i]);
		i--;
	}
}
