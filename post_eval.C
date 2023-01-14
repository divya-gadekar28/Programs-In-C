#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100

int stack[MAX];
char infix[MAX],postfix[MAX];
int top=-1;

void inToPost();
int space(char);
int precedence(char);
int isFull();
int isEmpty();
void print();
void push(int);
int pop();
int post_eval();

int post_eval()
{
	int i,a,b;
	for(i=0;i<strlen(postfix);i++)
	{
	if(postfix[i]>='0'&&postfix[i]<='9')
	{
	push(postfix[i]-'0');
	}
	else
	{
	a=pop();
	b=pop();
	switch(postfix[i])
	{
	case '+':push(b+a);
		 break;
	case '-':push(b-a);
		 break;
	case '*':push(b*a);
		 break;
	case '/':push(b/a);
		 break;
	case '^':push(pow(b,a));
		 break;
	}
	}
	}
	return pop();
}

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
void push(int val)
{
	if(isFull())
	{
	printf("\nstack overflow");
	exit(1);
	}
	top++;
	stack[top]=val;
}

int pop()
{
	int val;
	if(isEmpty())
	{
	printf("\nstack underflow");
	exit(1);
	}
	val=stack[top];
	top--;
	return val;
}

void main()
{
	int result;
	clrscr();
	printf("enter an infix expression:");
	gets(infix);
	inToPost();
	result=post_eval();
	print();
	printf("after evaluating postfix expr answer is:%d",result);
	getch();
}
