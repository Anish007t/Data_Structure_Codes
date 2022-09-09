#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *link;
};
struct node *push(struct node *top,char data)
{
	struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=top;
    top=ptr;
    return top;
};
struct node *pop(struct node *top)
{
    if(top==NULL)
    {
        printf("\nStack Underflow\n");
        return top;
    }
    struct node *ptr;
    ptr=top;
    top=top->link;
    free(ptr);
    return top;
}
int main()
{
    struct node *top1=NULL,*top2=NULL;
    char str[300],ch,ch2;
    int i;
    printf("Enter expression: ");
    gets(str);
    int count=strlen(str);
    str[count+2]='\0';
    for(i=count-1;i>=0;i--)
        str[i+1]=str[i];
    str[count+1]=')';
    str[0]='(';
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65&&str[i]<=90)
            top2=push(top2,str[i]);
        else
            top1=push(top1,str[i]);
        if (top1->data==')')
        {
            top1=pop(top1);
            while(top1->data!='(')
            {
                ch=top1->data;
                top1=pop(top1);
                top2=push(top2,ch);
            }
        	top1=pop(top1);
		}
   		else if(top1->data=='(')
        	continue;
    	else if(top1->data=='+'||top1->data=='-')
    	{
        	if((top1->link)->data=='(')
        		continue;
        	else
        	{
            	ch2=top1->data;
            	top1=pop(top1);
            	while (top1->data!='(')
            	{
                	ch=top1->data;
                	top1=pop(top1);
                	top2=push(top2,ch);
            	}
            	top1=push(top1,ch2);
       		}
    	}
 		else if(top1->data=='*'||top1->data=='/')
		{
    		if(top1->link->data=='(')
    			continue;
    		else if(top1->link->data=='^'||top1->link->data=='/'||top1->link->data=='*')
    		{
        		ch2=top1->data;
        		top1=pop(top1);
        		while(top1->data!='('&&top1->data!='+'&&top1->data!='-')
        		{
            		ch=top1->data;
            		top1=pop(top1);
            		top2=push(top2,ch);
        		}
        		top1=push(top1,ch2);
    		}
		}
		else if(top1->data=='*'||top1->data=='/')
		{
    		if(top1->link->data=='(')
    			continue;
    		else if(top1->link->data=='^')
    		{
        		ch2=top1->data;
        		top1=pop(top1);
        		while(top1->data='('&&top1->data!='+'&&top1->data!='-'&&top1->data!='*'&&top1->data!='/')
        		{
            		ch=top1->data;
            		top1=pop(top1);
            		top2=push(top2,ch);
        		}
    		top1=push(top1,ch2);
    		}
		}
	}
	struct node *ptr;
	ptr=top2;
	for(i=0;ptr!=NULL;i++)
	{
    	str[i]=ptr->data;
    	ptr=ptr->link;
	}
	str[i]='\0';
	strrev(str);
	printf("\n\nExpression: ");
	puts(str);
	return 0;
}
