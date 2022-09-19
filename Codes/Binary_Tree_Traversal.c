#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *llink,*rlink;
};
struct node *header=NULL;
void create();
void inorder2traverse();
void preorder2traverse();
void postorder2traverse();
int traversal(int);
int main()
{
	int ch;
	create();
	printf("\n ...................................................");
	printf("\n\t Press 1 for Inorder Traversal.\n\t Press 2 for Preorder Traversal.\n\t Press 3 for Postorder Traversal. ");
	printf("\n ...................................................");
	printf("\n Enter your choice: ");
	scanf("%d",&ch);
	if(ch>3||ch<=0)
		printf("\n !!! Wrong Choice !!!");
	else
		traversal(ch);
	return 0;
}
void create()
{
	struct node *newn,*ptr,*ptr1=NULL;
	int n;
	printf("\n Enter the number of nodes: ");
	scanf("%d",&n);
	while(n>0)
	{
		newn=(struct node*)malloc(sizeof(struct node));
		printf("\n Enter the data: ");
		scanf("%d",&newn->data);
		newn->llink=newn->rlink=NULL;
		if(header==NULL)
		{
			header=newn;
			n--;
			continue;
		}
		ptr=header;
		if(ptr->data>newn->data)
			ptr1=ptr->llink;
		else
			ptr1=ptr->rlink;
		while(ptr1!=NULL)
		{
			ptr=ptr1;
			if(ptr->data>newn->data)
				ptr1=ptr->llink;
			else
				ptr1=ptr->rlink;
		}
		if(ptr->data>newn->data)
			ptr->llink=newn;
		else
			ptr->rlink=newn;
		n--;
	}
	return;
}
void inorder2traverse(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder2traverse(ptr->llink);
		printf("\n %d",ptr->data);
		inorder2traverse(ptr->rlink);	
	}
}
void preorder2traverse(struct node *ptr)
{
	if(ptr!=NULL)
	{
	    printf("\n %d",ptr->data);
		preorder2traverse(ptr->llink);
		preorder2traverse(ptr->rlink);
	}
	return;
}
void postorder2traverse(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder2traverse(ptr->llink);
		postorder2traverse(ptr->rlink);
		printf("\n %d",ptr->data);
	}
}
int traversal(int ch)
{
	struct node *ptr;
	if(header==NULL)
	{
		printf("\n Tree not found.");
		return 0;
	}
	ptr=header;
	if(ch==1)
	{
		printf("\n The tree elements are inorder manner: ");
		inorder2traverse(ptr);
	}
	else if(ch==2)
	{
		printf("\n The tree elements are preorder manner: ");
		preorder2traverse(ptr);
	}
	else if(ch==3)
	{
		printf("\n The tree elements are postorder manner: ");
		postorder2traverse(ptr);
	}
	return 0;
}
