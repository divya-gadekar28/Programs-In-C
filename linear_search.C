#include<stdio.h>
#include<conio.h>
void main()
{
	int key,arr[10],i,n,result;
	clrscr();
	printf("\nhow many elements:");
	scanf("%d",&n);
	printf("\nenter %d elements",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	printf("\nenter the element to be searched:");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
	if(arr[i]==key)
	{
	printf("\nelement found at %d position",i+1);
	}
	}
	getch();
}
