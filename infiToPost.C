#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX],postfix[MAX];
int top=-1;

void inToPost();
int space(char);
int precedence(char);
int isFull();
int isEmpty();
void print();
void push(char);
int pop();


void inToPost()
{
	int i,j=0;
	char next,symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!space(symbol))
		{
		switch(symbol)
		{
		case '(':push(symbol);
			 break;
		case ')':while((next=pop())!='(')
			 {
			 postfix[j++]=next;
			 }
			 break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		while(!isEmpty()&&precedence(stack[top])>=precedence(symbol))
		{
		postfix[j++]=pop();
		}
		push(symbol);
		break;
		default:
		postfix[j]=symbol;
		j++;
		}
		}
	}
	while(!isEmpty())
	{
	postfix[j++]=pop();
	}
}

int space(char c)
{
	if(c==' '||c=='\t')
	return 1;
	else
	return 0;
}

int precedence(char symbol)
{
	switch(symbol)
	{
	case '^':return 3;
	case '/':
	case '*':
	return 2;
	case '+':
	case '-':
	return 1;
	default:return 0;
	}
}

void print()
{
	int i=0;
	printf("\nequivalent postfix expr:\n");
	while(postfix[i])
	{
	printf("%c",postfix[i++]);
	}
}

int isEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}

int isFull()
{
	if(top==MAX-1)
	return 1;
	else
	return 0;
}

void push(char s)
{
	if(isFull())
	{
	printf("\nstack overflow");
	exit(1);
	}
	top++;
	stack[top]=s;
}

int pop()
{
	char c;
	if(isEmpty())
	{
	printf("\nstack underflow");
	exit(1);
	}
	c=stack[top];
	top--;
	return c;
}

void main()
{
	clrscr();
	printf("enter an infix expression:");
	gets(infix);
	inToPost();
	print();
	getch();
}
