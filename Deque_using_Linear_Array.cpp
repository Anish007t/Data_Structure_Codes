#include<stdio.h>
#include<stdlib.h>
#define size 5
int deque[size];
int f=-1,r=-1;
void insert_front(int x)
{
	if((f==0 && r==size-1)||(f==r+1))
		printf("\nOverflow.");
	else if((f==-1)&&(r==-1))
	{
		f=r=0;
		deque[f]=x;
	}
	else if(f==0)
	{
		f=size-1;
		deque[f]=x;
	}
	else
	{
		f=f-1;
		deque[f]=x;
	}
}
void insert_rear(int x)
{
	if((f==0&&r==size-1)||(f==r+1))
		printf("\nOverflow.");
	else if((f==-1)&&(r==-1))
	{
		r=0;
		deque[r]=x;
	}
	else if(r==size-1)
	{
		
		r=0;
		deque[r]=x;
	}
	else
	{
		r++;
		deque[r]=x;
	}
}
void display()
{
	int i=f;
	printf("\nElements in Deque are=");
	while(i!=r)
	{
		printf("%d ",deque[i]);
		i=(i+1)%size;
	}
	printf("%d ",deque[r]);
}
void get_front()
{
	if((f==-1)&&(r==-1))
		printf("\nUnderflow.");
	else
		printf("\nFront=%d",deque[f]);
}
void get_rear()
{
	if((f==-1)&&(r==-1))
		printf("\nUnderflow.");
	else
		printf(" Rear=%d",deque[r]);
}
void delete_front()
{
	if((f==-1)&&(r==-1))
		printf("\nUnderflow.");
	else if(f==r)
	{
		printf("\nThe deleted element=%d",deque[f]);
		f=r=-1;
	}
	else if(f==size-1)
	{
		printf("\nThe deleted element=%d",deque[f]);
		f=0;
	}
	else
	{
		printf("\nThe deleted element=%d",deque[f]);
		f++;
	}
}
void delete_rear()
{
	if((f==-1)&&(r==-1))
		printf("\nUnderflow.");
	else if(f==r)
	{
		printf("\nDEleted element=%d",deque[r]);
		f=r=-1;
	}
	else if(r==0)
	{
		printf("\nDEleted element=%d",deque[r]);
		r=size-1;
	}
	else
	{
		printf("\nDEleted element=%d",deque[r]);
		r--;
	}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n..........................................");
		printf("\n. Press 1 for Inserting value at front.  .");
		printf("\n. Press 2 for Inserting value at rear.   .");
		printf("\n. Press 3 for Deleting value at front.   .");
		printf("\n. Press 4 for Deleting value at rear.    .");
		printf("\n. Press 5 for Peek.                      .");
		printf("\n. Press 6 for Display.                   .");
		printf("\n. Press 7 for exit.                      .");
		printf("\n..........................................");
		printf("\nEnter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the value=");
				scanf("%d",&x);
				insert_front(x);
				break;
			case 2:
				printf("\nEnter the value=");
				scanf("%d",&x);
				insert_rear(x);
				break;
			case 3:
				delete_front();
				break;
			case 4:
				delete_rear();
				break;
			case 5:
				get_front();
				get_rear();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
		}
	}
	return 0;
}
