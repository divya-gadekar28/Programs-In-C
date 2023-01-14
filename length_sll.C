#include<stdio.h>
typedef struct node
{
int info;
struct node *next;
}NODE;

void createlist(NODE *head)
	{
	int n , count ;
	NODE *last, *newnode;
	printf("How many nodes:");
	scanf("%d", &n);
	last = head;
	for(count = 1 ; count<=n; count++)
	{
	newnode = (NODE *) malloc(sizeof(NODE));
	newnode->next = NULL;
	printf("\n Enter the node data:");
	scanf("%d", &newnode->info);
	last->next = newnode;
	last = newnode;
	}
	}

void display(NODE *head)
{
NODE *temp;
for(temp=head->next; temp!=NULL; temp=temp->next)
{
printf("%d\t", temp->info);
}
}

void length_sll(struct node *head)
{
	int length=0;
	while(head!=NULL)
	{
	head=head->next;
	length++;
	}
	printf("\nlength of above SLL is %d",length-1);
}

void main()
{
NODE* head;
int choice , n , pos;
head=(NODE*)malloc(sizeof (NODE));
head->next=NULL;
do
{
printf("\n1:CREATE");
printf("\n2:DISPLAY") ;
printf("\n3:FIND LENGTH OF SLL");
printf("\n4:EXIT");
printf("\nENTER YOUR CHOICE: ");
scanf("%d",&choice) ;
switch(choice)
     {
     case 1 :
     createlist(head);
     break;
     case 2 :
	  display(head);
	  break;
     case 3:
     length_sll(head);
     break;
     case 4: exit(1);
     break;
     }
     } while (choice!=8);
}