#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct node
{
int data;
struct node *left;
struct node *right;
};

// globally initialized root pointer
struct node *root = NULL;
// function prototyping
struct node *create_node(int);
void insert(int);
void inorder(struct node *);
void postorder();
void preorder();
int get_data();

void main()
{
int userChoice;
int data;
clrscr();
while (1)
{
printf("\n1. Insert");
printf("\n2. Inorder ");
printf("\n3. Post Order ");
printf("\n4. Pre Oder ");
printf("\n5. Exit");
printf("\n\nEnter Your Choice: ");
scanf("%d", &userChoice);
printf("\n");
switch(userChoice)
{
case 1:
data = get_data();
insert(data);
break;
case 2:
inorder(root);
break;
case 3:
postorder(root);
break;
case 4:
preorder(root);
break;
case 5:
exit(1);
break;
default:
printf("\n\tInvalid Choice\n");
break;
}}
getch();
}

// creates a new node
struct node *create_node(int data)
{
struct node *new_node = (struct node *)malloc(sizeof(struct node));
if (new_node == NULL)
{
printf("\nMemory for new node can't be allocated");
return NULL;
}
new_node->data = data;
new_node->left = NULL;
new_node->right = NULL;
return new_node;
}
// inserts the data in the BST
void insert(int data)
{
struct node *new_node = create_node(data);
struct node *temp = root;
struct node *prev = NULL;
if (new_node != NULL)
{
// if the root is empty then make a new node as the root node
if (root == NULL)
{
root = new_node;
printf("\n* node having data %d was inserted\n", data);
return;
}
while (temp != NULL)
{
prev = temp;
if (data > temp->data)
{
temp = temp->right;
}
else
{
temp = temp->left;
}
}
// found the last node where the new node should insert
if (data > prev->data)
{
prev->right = new_node;
}
else
{
prev->left = new_node;
}
printf("\n* node having data %d was inserted\n", data);
}
}

// inorder traversal of the BST
void inorder(struct node *root)
{
if (root == NULL)
{
return;
}
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
// preorder traversal of the BST
void preorder(struct node *root)
{
if (root == NULL)
{
return;
}
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
// postorder travsersal of the BST
void postorder(struct node *root)
{
if (root == NULL)
{
return;
}
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
// getting data from the user
int get_data()
{
int data;
printf("\nEnter Data: ");
scanf("%d", &data);
return data;
}
