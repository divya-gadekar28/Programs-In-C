#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
char stack[MAX];
int check_balance(char *s);
int match_char(char,char);
void push(char s);
int pop();
int isFull();
int isEmpty();

int check_balance(char *s)
{
	char temp;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='{'||s[i]=='['||s[i]=='(')
		push(s[i]);
		if(s[i]=='}'||s[i]==']'||s[i]==')')
		{
			if(isEmpty())
			{
				printf("\nRight brackets are more than left brackets");
				return 0;
			}
			else
			{
				temp=pop();
				if(!match_char(temp,s[i]))
				{
				printf("\nmismatched brackets");
				return 0;
				}
			}
		}
	}
	if(isEmpty())
	{
		printf("\nbrackets are well balanced");
		return 1;
	}
	else
	{
		printf("\nleft brackets are more than right");
		return 0;
	}
}

int match_char(char a,char b)
{
	if(a=='['&&b==']')
	return 1;
	else if(a=='{'&&b=='}')
	return 1;
	else if(a=='('&&b==')')
	return 1;
	else
	return 0;
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
	char expr[MAX];
	int balance;
	clrscr();
	printf("enter the algebric expression:\n");
	gets(expr);
	balance=check_balance(expr);
	if(balance==1)
	printf("\nthe expression is valid");
	else
	printf("\ninvalid expression");
	getch();
}
