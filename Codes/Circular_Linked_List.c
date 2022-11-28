#include<stdio.h>
#include<stdlib.h>
typedef struct record
{
    int value;
    struct record *next;
}NODE;
NODE *last=NULL;
NODE* create_node(int);
void insert_last(int);
void insert_beg(int);
void insert_after(int,int);
void insert_before(int,int);
void display();
void delete_beg();
void delete_last();
void delete_pos(int);
void delete_any(int);
void rev();
void ser(int);
void sort();
int main()
{
    int choice,data,val;
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
                printf("\nEnter the data=");
                scanf("%d",&data);
                insert_last(data);
                break;
            case 2:
                printf("\nEnter the data=");
                scanf("%d",&data);
                insert_beg(data);
                break;
            case 3:
                printf("\nEnter the data=");
                scanf("%d",&data);
                printf("\nEnter the value=");
                scanf("%d",&val);
                insert_after(data,val);
                break;
            case 4:
                printf("\nEnter the data=");
                scanf("%d",&data);
                printf("\nEnter the value=");
                scanf("%d",&val);
                insert_before(data,val);
                break;
            case 5:
                display();
                break;
            case 6:
                delete_beg();
                break;
            case 7:
                delete_last();
                break;
            case 8:
                printf("\nEnter the Pos=");
                scanf("%d",&val);
                delete_pos(val);
                break;
            case 9:
                printf("\nEnter the val=");
                scanf("%d",&val);
                delete_any(val);
                break;
            case 10:
                rev();
                break;
            case 11:
                printf("\nEnter the value=");
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
    return 0;
}
NODE* create_node(int data)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->value=data;
    temp->next=NULL;
    return temp;
}
void insert_last(int data)
{
    NODE* p=create_node(data);
    if(last==NULL)
    {
        last=p;
        last->next=last;
    }
    else
    {
        p->next=last->next;
        last->next=p;
        last=last->next;
    }
}
void insert_beg(int data)
{
    NODE* p=create_node(data);
    if(last==NULL)
    {
        last=p;
        last->next=last;
    }
    else
    {
        p->next=last->next;
        last->next=p;
    }
}
void insert_after(int data,int pos)
{
    if(last==NULL)
        printf("\nList is empty.");
    else if(last->value==pos)
    {
        insert_last(data);
    }
    else
    {
        NODE *q;
        int f=0;
        q=last->next;
        while(q!=last)
        {
            if(q->value==pos)
            {
                NODE* p=create_node(data);
                p->next=q->next;
                q->next=p;
                f=1;
                break;
            }
            else
                q=q->next;
        }
        if(f==0)
            printf("\nValue not present in the list.");
    }
}
void insert_before(int data,int pos)
{
    if(last==NULL)
        printf("\nList is empty.");
    else if((last->next)->value==pos)
    {
        insert_beg(data);
    }
    else
    {
        int f=0;
        NODE *q=last->next;
        while(q->next!=last)
        {
            if((q->next)->value==pos)
            {
                NODE* p=create_node(data);
                p->next=q->next;
                q->next=p;
                f=1;
                break;
            }
            else    
                q=q->next;
        }
        if(f==0)
            printf("\nValue not present.");
    }
}
void display()
{
    int count=0;
	NODE *curr=last->next;
	printf("\n Current List is: \n");
    do
    {
        printf("\n Data at position %d is = %d \n",++count,curr->value);
		curr=curr->next;
    } while (curr!=last->next);
}
void delete_beg()
{
    if(last==NULL)
        printf("\nList is empty.");
    else
    {
        if(last->next==last)
        {
            NODE *p=last;
            free(p);
            last=NULL;
        }
        else
        {
            NODE *p=last->next;
            last->next=p->next;
            free(p);
        }
    }
}
void delete_last()
{
    if(last==NULL)
        printf("\nList is empty.");
    else
    {
        if(last->next==last)
        {
            NODE *p=last;
            free(p);
            last=NULL;
        }
        else
        {
            NODE *p=last->next;
            while(p->next!=last)
                p=p->next;
            p->next=last->next;
            last->next=NULL;
            free(last);
            last=p;
        }
    }
}
void delete_any(int val)
{
    if((last->next)->value==val)
        delete_beg();
    else if(last->value==val)
        delete_last();
    else
    {
        NODE *curr=last->next;
        int f=0;
        while(curr->next!=last)
        {
            if((curr->next)->value==val)
            {
                NODE *temp=curr->next;
                curr->next=temp->next;
                free(temp);
                f=1;
                break;
            }
            else
                curr=curr->next;
        }
        if(f==0)
            printf("\nValue not present.");
    }
}
void delete_pos(int pos)
{
    NODE *u,*v;
    int del,w=0;

    del=pos-1;

    u=last->next;
    while(w!=del)
    {
        v=u;
        u=u->next;
        w++;
    }
    v->next=u->next;
    free(u);
}
void rev()
{
    NODE *head=last->next;
    last=head;
    NODE *prev=head;
    NODE *cur=head->next;
    head=head->next;
    while(head!=last)
    {
        head=head->next;
        cur->next=prev;
        prev=cur;
        cur=head;
    }
    cur->next=prev;
    head=prev;
}
void ser(int val)
{
    if (last==NULL)
    {
        printf("\nList is empty.");
    }
    else
    {
        NODE *curr=last->next;
        int flag=0,i=0;
        do
        {
            i++;
            if(curr->value==val)
            {
                printf("\n%d is at position %d",val,i);
                flag=1;
            }
            curr=curr->next;
        } while (curr!=last->next);
        if(flag==0)
            printf("\nValue does not exist.");
    }
}
void sort()
{
    NODE *head=last->next,*curr=last->next,*index=NULL;
    int temp;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        do
        {
            index=curr->next;
            while(index!=head)
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
        } while (curr->next!=head);
    }
}