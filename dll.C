#include<stdio.h>
typedef struct node
{
int info;
struct node *prev , *next;
}NODE;

void createlist( NODE *head)
	{
	int n, count;
	NODE *last, *newnode;
	printf("How many nodes you have to create in : DLL");
	scanf("%d", &n);
	last = head;
	for(count=1; count<=n; count++)
		{
		newnode = (NODE *)malloc(sizeof(NODE));
		newnode->next = newnode->prev = NULL;
		printf("\n Enter the node data:");
		scanf("%d",&newnode->info);
		last->next = newnode;
		newnode->prev = last;
		last = newnode;
		}
	}
void display(NODE *head)
	{
	NODE *temp;
	for(temp=head->next; temp!=NULL; temp=temp->next)
	printf("%d\t",temp->info);

	}
int search(NODE *head, int num)
	{
	NODE *temp; int pos;
	for(temp=head->next, pos=1; temp!=NULL; temp=temp->next, pos++)
	if(temp->info==num)
	return pos;
	return -1;
	}
void insert(NODE *head, int num, int pos)
	{
	NODE *newnode, *temp, *temp1;
	int i;
	/* move temp to node at pos -1*/
	for(temp=head, i=1; (temp!=NULL)&&(i<=pos-1); i++)
	temp = temp->next;
	if (temp==NULL)
	{
	printf("position is out of range");
	return;
	}
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->info=num;
	newnode->next = newnode->prev=NULL;
	temp1=temp->next;
	newnode->next=temp1;
	temp1->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	}
void deletepos(NODE *head, int pos)
	{ 
	NODE *temp, *temp1;
	int i;
	/* move temp to node at pos-1 */
	for(temp=head, i=1; (temp->next!=NULL) && (i<=pos-1); i++)
	temp= temp->next;
	if(temp->next==NULL)
	{
	printf("position is out of range");
	return;
	}
	temp1=temp->next;
	temp->next = temp1->next;‬
	if(temp1->next!=NULL)
	temp1->next->prev=temp;
	free(temp1);
	}


void main()
	{
	NODE *head;
	int choice, n, pos;
	head= (NODE *) malloc(sizeof(NODE));
	head->prev = head->next =NULL;
	do
	{
	printf("\n1: create");
	printf("\n2: search");
	printf("\n3: display");
	printf("\n4: insert");
	printf("\n5: Delete");
	printf("\n7: exit");
		printf("\n: Enter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1 :
		createlist(head);
		break;
		case 2 :
		printf("\n enter the element to be searched:");
		scanf("%d",&n);
		pos=search(head,n);
		if(pos==-1)
		printf("\n Element not found");
		else
		printf("\nElement found at position %d",pos);
		break;
		case 3 :
		display(head);
		break;
		case 4 :
		printf("\n Enter the element and position");
		scanf("%d%d",&n,&pos);
		insert(head,n,pos);
		display(head);
		break;
		case 5 :
		printf("\n Enter the position");
		scanf("%d",&pos);
		deletepos(head,pos);
		display(head);
		break;

		}
		}
		while(choice !=7);
	}
