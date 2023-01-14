//Program for Circular Singly LinkedList-create and display
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;
void create();
void display();
void main()
{
	int ch;
	clrscr();
	do
	{
	printf("\n 1.Create Circular SLL");
	printf("\n 2.Display Circular SLL");
	printf("\n 3.Exit");
	printf("\n Enter ur choice :");
	scanf("%d",&ch);
	switch(ch)
	  {
		 case 1:create();
			break;
		 case 2:display();
			break;
		 case 3:exit(0);
	   }
	}while (ch!=3);
	getch();
}
void create()
{
	int x;
	NODE *temp,*q;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("\n Enter value of data :");
	scanf("%d",&x);
	temp->data=x;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
		start->next=start;
	}
	else
	{
		q=start;
		while(q->next!=start)
			q=q->next;
		temp->next=q->next;
		q->next=temp;
	}
}

void display()
{
	NODE *q;
	q=start;
	do
	{
		printf("%d->",q->data);
		q=q->next;
	}while(q!=start);
//	printf("NULL");
}