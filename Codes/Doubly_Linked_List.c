#include<stdio.h>
#include<stdlib.h>
typedef struct record
{
    int value;
    struct record *rlink;
    struct record *llink;
}NODE;
NODE *st=NULL;
NODE* create_node(int);
void insert_last(int);
void insert_first(int);
void insert_after(int,int);
void insert_before(int,int);
void display();
void del_beg();
void del_last();
void del_pos(int); 
void del_any(int);
void rev();
void ser(int);
void sort();
int main()
{
    int val,pos,choice;
    while(1)
    {
        printf("\n................................................");
		printf("\n. Press 1 for add new node at Last.            .");
		printf("\n. Press 2 for add a node at beginning.         .");
		printf("\n. Press 3 for add a node after a node.         .");
        printf("\n. Press 4 for add a node before a node.        .");
		printf("\n. Press 5 for display.                         .");
		printf("\n. Press 6 for delete at begining.              .");
		printf("\n. Press 7 for delete last node.                .");
		printf("\n. Press 8 for deleting a node number.          .");
		printf("\n. Press 9 for delete a node by value.          .");
		printf("\n. Press 10 for reverse.                        .");
		printf("\n. Press 11 for search of a node.               .");
		printf("\n. Press 12 for sort.                           .");
		printf("\n. Press 13 for exit.                           .");
		printf("\n................................................");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the value to insert=");
                scanf("%d",&val);
                insert_last(val);
                break;
            case 2:
                printf("\nEnter the value to insert=");
                scanf("%d",&val);
                insert_first(val);
                break;
            case 3:
                printf("\nEnter the value to insert=");
                scanf("%d",&val);
                printf("\nEnter the value of the node=");
                scanf("%d",&pos);
                insert_after(val,pos);
                break;
            case 4:
                printf("\nEnter the value to insert=");
                scanf("%d",&val);
                printf("\nEnter the value of the node=");
                scanf("%d",&pos);
                insert_before(val,pos);
                break;
            case 5:
                display();
                break;
            case 6:
                del_beg();
                break;
            case 7:
                del_last();
                break;
            case 8:
                printf("\nEnter the position=");
                scanf("%d",&pos);
                del_pos(pos);
                break;
            case 9:
                printf("\nEnter the value of the node=");
                scanf("%d",&val);
                del_any(val);
                break;
            case 10:
                rev();
                break;
            case 11:
                printf("\nEnter the value to search=");
                scanf("%d",&val);
                ser(val);
                break;
            case 12:
                sort();
                break;
            case 13:
                printf("\nProgramme exited.");
                exit(0);
            default:
                printf("\nWrong choice.");
        }
    }
}
NODE* create_node(int val)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->value=val;
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}
void insert_last(int val)
{
    NODE *p=create_node(val);
    if(st==NULL)
        st=p;
    else
    {
        NODE *q=st;
        while(q->rlink!=NULL)
            q=q->rlink;
        p->llink=q;
        q->rlink=p;
    }
}
void insert_first(int val)
{
    NODE *p=create_node(val);
    if(st==NULL)
        st=p;
    else
    {
        p->rlink=st;
        st->llink=p;
        st=p;
    }
}
void insert_after(int val,int pos)
{
    if(st==NULL)
        printf("\nList is empty.");
    else
    {
        NODE *p=create_node(val);
        NODE *q=st;
        int flag=0;
        while(q!=NULL)
        {
            if(q->value==pos)
            {
                p->rlink=q->rlink;
                p->llink=q;
                (q->rlink)->llink=p;
                q->rlink=p;
                flag=1;
                break;
            }
            else    
                q=q->rlink;
        }
        if(flag==0)
            printf("\nValue not found.");
    }
}
void insert_before(int val,int pos)
{
    if(st==NULL)
        printf("\nList is empty.");
    else
    {
        NODE *p=create_node(val);
        NODE *q=st;
        int flag=0;
        while(q!=NULL)
        {
            if(q->value==pos)
            {
                p->rlink=q;
                p->llink=q->llink;
                (q->llink)->rlink=p;
                q->llink=p;
                flag=1;
                break;
            }
            else
                q=q->rlink;
        }
        if(flag==0)
            printf("\nValue not found.");
    }
}
void display()
{
    NODE *cur=st;
    int count=0;
    while(cur!=NULL)
    {
        printf("\nData at postion %d is %d",++count,cur->value);
        cur=cur->rlink;
    }
}
void del_beg()
{
    if(st==NULL)
        printf("\nList is empty.");
    else if(st->rlink==NULL)    
    {
        NODE *p=st;
        st=NULL;
        free(p);
    }
    else
    {
        NODE *cur=st;
        st=st->rlink;
        st->llink=NULL;
        cur->rlink=NULL;
        free(cur);
    }
}
void del_last()
{
    if(st==NULL)
        printf("\nList is empty.");
    else if(st->rlink==NULL)
    {
        NODE *p=st;
        st=NULL;
        free(p);
    }
    else
    {
        NODE *cur=st;
        while(cur->rlink!=NULL)
            cur=cur->rlink;
        (cur->llink)->rlink=NULL;
        cur->llink=NULL;
        free(cur);
    }
}
void del_pos(int pos)
{
	NODE *curr=st,*temp;
	while((pos-1)>1&&curr!=NULL)
	{
		curr=curr->rlink;
		pos--;
	}
	if(curr==NULL)
	{
		printf("\n Position is outside the list.");
		return;
    }
	temp=curr->rlink;
	curr->rlink=temp->rlink;
	free(temp);    
}
void del_any(int val)
{
    if(st->value== val)
        del_beg();
    else
    {
        NODE *cur=st;
        int flag=0;
        while(cur!=NULL)
        {
            if(cur->value==val)
            {
                (cur->llink)->rlink=cur->rlink;
                free(cur);
                flag=1;
                break;
            }
            else
                cur=cur->rlink;
        }
        if(flag==0)
            printf("\nValue does not exist.");
    }
}
void rev()
{
    NODE *curr=st,*prev=NULL,*sprev=NULL;
	while(curr!=NULL)
	{
		sprev=prev;
		prev=curr;
		curr=curr->rlink;
		prev->rlink=sprev;
	}
	st=prev;
}
void ser(int val)
{
    if(st==NULL)
        printf("\nList is empty.");
    else
    {
        int count=0,flag=0;
        NODE *cur=st;
        while(cur!=NULL)
        {
            count++;
            if(cur->value==val)
            {
                printf("\n%d found at %d",val,count);
                flag=1;
            }
            cur=cur->rlink;
        }
        if(flag==0)
            printf("\nValue not found.");
    }
}
void sort()
{
    NODE *curr=st, *index = NULL;
    int temp;
    if(st==NULL) 
	{
  		printf("\nList is empty.");
    } 
	else 
	{
  		while(curr!=NULL) 
		{
    		index=curr->rlink;
			while (index!=NULL) 
			{
    			if(curr->value>index->value) 
				{
      				temp=curr->value;
      				curr->value=index->value;
      				index->value=temp;
    			}
    			index=index->rlink;
    		}
    		curr=curr->rlink;
  		}
  	}
}
