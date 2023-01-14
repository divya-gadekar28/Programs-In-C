#include<stdio.h>
#include<conio.h>
struct node{
int data;
struct node *link;
}*top=NULL;

int isEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}

void push(int info)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
	printf("stack overflow");
	exit(1);
	}
	newnode->data=info;
	newnode->link=NULL;
	newnode->link=top;
	top=newnode;
}

int pop()
{
	int val;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(isEmpty())
	{
	printf("stack underflow");
	exit(1);
	}
	temp=top;
	val=top->data;
	top=top->link;
	free(temp);
	temp=NULL;
	return val;
}

void display()
{
	struct node *print;
	print=top;
	if(isEmpty())
	{
	printf("stack underflow");
	exit(1);
	}
	printf("stack elements are :");
	while(print)
	{
	printf("%d\t",print->data);
	print=print->link;
	}
}

int peek()
{
	if(isEmpty())
	{
	printf("stack underflow");
	exit(1);
	}
	return top->data;
}
void main()
{
	int choice,n,info;
	clrscr();
	while(1)
	{
	printf("\n press 1:to push");
	printf("\n press 2:to pop");
	printf("\n press 3:quit");
	printf("\npress 4:to display the stack");
	printf("\npress 5:to display topmost element");
	printf("\nenter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("enter the element you want to push:");
	scanf("%d",&info);
	push(info);
	break;
	case 2:
	n=pop();
	printf("deleted element is %d",n);
	break;
	case 3:
	exit(1);
	break;
	case 4:
	display();
	break;
	case 5:
	peek();
	printf("\ntopmost element in an stack is %d",top->data);
	break;
	default:
	printf("\nwrong choice");
	break;
	}
	}
getch();
}