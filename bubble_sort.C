#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int i,n,a[10],j,temp;
	clrscr();
	printf("how many elements?");
	scanf("%d",&n);
	printf("enter %d elements in an array",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
	{
		if(a[j]<a[j+1])
		{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
	printf("%d\t",a[j]);
	}
	getch();
}

