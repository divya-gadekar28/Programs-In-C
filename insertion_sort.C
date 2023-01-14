#include<stdio.h>
#include<conio.h>
void insertion(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
void main()
{
	int result,n,i,arr[10];
	clrscr();
	printf("how many elements:");
	scanf("%d",&n);
	printf("enter %d elements in an array\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion(arr,n);
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
	printf("%d\t",arr[i]);
	}
	getch();
}
