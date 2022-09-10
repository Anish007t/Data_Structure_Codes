#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct record
{
	int value;
	struct record *next;
}NODE;
void append(int data);
void add_beginning(int data);
void add_after_node(int pos,int data);
void display();
void del_begin();
void del_last();
void del_node(int pos);
void del_value(int data);
void reverse();
void search(int data);
void sort();
NODE *start=NULL;
int main()
{
	int prompt,data,s,pos;
	while(1)
	{
		printf("\n................................................");
		printf("\n. Press 1 for add new node to list.            .");
		printf("\n. Press 2 for add a node on the beginning.     .");
		printf("\n. Press 3 for add a node after a node.         .");
		printf("\n. Press 4 for display.                         .");
		printf("\n. Press 5 for delete at begining.              .");
		printf("\n. Press 6 for delete last node.                .");
		printf("\n. Press 7 for deleting a node number.          .");
		printf("\n. Press 8 for delete a node by value.          .");
		printf("\n. Press 9 for reverse.                         .");
		printf("\n. Press 10 for search of a node.               .");
		printf("\n. Press 11 for sort.                           .");
		printf("\n. Press 12 for exit.                           .");
		printf("\n................................................");
		printf("\n Enter your choice: ");
		scanf("%d",&s);
		switch(s)
		{
			case 1:
				do
	            {
					printf("\n Enter <1> to add new NODE to list <0> to end list: ");
					scanf("%d",&prompt);
					if(prompt==1)
					{
						printf("\n Enter the data: ");
						fflush(stdin);
						scanf("%d",&data);
						append(data);
					}
				}while(prompt!=0);
				break;
			case 2:
				printf("\n Enter the data to be kept in beginning: ");
				fflush(stdin);
				scanf("%d",&data);
				add_beginning(data);
				break;
			case 3:
				printf("\n Enter the position of node where data to be entered: ");
				fflush(stdin);
				scanf("%d",&pos);
				printf("\n Enter the data: ");
				fflush(stdin);
				scanf("%d",&data);
				add_after_node(pos,data);
				break;
			case 4:
				display();
				break;
			case 5:
				del_begin();
				break;
			case 6:
				del_last();
				break;
			case 7:
				printf("\n Enter the position of node where data to be deleted: ");
				fflush(stdin);
				scanf("%d",&pos);
				del_node(pos);
				break;
			case 8:
				printf("\n Enter the data to be deleted: ");
				fflush(stdin);
				scanf("%d",&data);
				del_value(data);
				break;
			case 9:
				reverse();
				break;				
			case 10:
				printf("\n Enter the data to be search: ");
				fflush(stdin);
				scanf("%d",&data);
				search(data);
				break;
			case 11:
				sort();
				break;
			case 12:
				printf("\n Programme operation is over.");
				exit(0);
			default:
				printf("\n\t !!!Wrong Choice!!! ");
		}
	}
	getch();
	return 0;
}
void append(int data)
{
	NODE *temp,*curr;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->value=data;
	temp->next=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		curr=start;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
	}
}
void add_beginning(int data)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->value=data;
	temp->next=start;
	start=temp;
}
void add_after_node(int pos,int data)
{
	NODE *curr=start,*temp;
	while(pos>1)
	{
		curr=curr->next;
		pos--;
	}
	temp=(NODE *)malloc(sizeof(NODE));
	temp->value=data;
	temp->next=curr->next;
	curr->next=temp;
}
void display()
{
	int count=-1;
	NODE *curr=start;
	printf("\n Current List is: \n");
	while(curr!=NULL)
	{
		printf("\n Data %d = %d \n",++count,curr->value);
		curr=curr->next;	
	}
}
void del_begin()
{
	NODE *temp=start;
	start=start->next;
	free(temp);
}
void del_last()
{
	NODE *curr=start,*temp;
	while(curr->next!=NULL)
		curr=curr->next;
	temp=curr->next;
	curr->next=NULL;
	free(temp);
}
void del_node(int pos)
{
	NODE *curr=start,*temp;
	while((pos-1)>1&&curr!=NULL)
	{
		curr=curr->next;
		pos--;
	}
	if(curr==NULL)
	{
		printf("\n Position is outside the list.");
		return;
    }
	temp=curr->next;
	curr->next=temp->next;
	free(temp);    
}
void del_value(int data)
{
	NODE *curr,*temp;
	if(start->value==data)
	{
		del_begin();
		return;
	}
	curr=start;
	while(curr->next->value!=data)
		curr=curr->next;
	temp=curr->next;
	curr->next=temp->next;
	free(temp);
}
void reverse()
{
	NODE *curr=start,*prev=NULL,*sprev=NULL;
	while(curr!=NULL)
	{
		sprev=prev;
		prev=curr;
		curr=curr->next;
		prev->next=sprev;
	}
	start=prev;
}
void search(int data)
{
	NODE *curr=start;
	int check=0,count=-1;
	while(curr!=NULL)
	{
		count++;
		if(curr->value==data)
		{
			printf("\n Data %d found in position %d", data,count);
			check++;
		}
		curr=curr->next;
	}
	if(check==0)
		printf("\n Value not found.");
} 
void sort() 
{
	NODE *curr=start, *index = NULL;
    int temp;
    if(start==NULL) 
	{
  		return;
    } 
	else 
	{
  		while(curr!=NULL) 
		{
    		index=curr->next;
			while (index!=NULL) 
			{
    			if(curr->value>index->value) 
				{
      				temp=curr->value;
      				curr->value=index->value;
      				index->value=temp;
    			}
    			index=index->next;
    		}
    		curr=curr->next;
  		}
  	}
}
