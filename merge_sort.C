#include<stdio.h>

void disp();
void mergesort(int,int,int);
void msortdiv(int,int);
int a[50],n;
void main()
{
    int i;
    clrscr();
    printf("\n\nEnter the value of n:\n");
    scanf("%d",&n);
    printf("\nEnter the elements for an array:\n\n");
    for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
    }
    printf("\nArray before sorting:\n");
    for(i=0;i<n;i++)
    {
	printf("%d\t",a[i]);
    }

    msortdiv(0,n-1);
    printf("\n\n\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
	 printf("%d\t",a[i]);
    }
    getch();
}

void mergesort(int low,int mid,int high)
{
     int t[50],i,j,k;
     i=low;
     j=mid+1;
     k=low;
     while((i<=mid) && (j<=high))
     {
	 if(a[i]>=a[j])
	 {
	    t[k++]=a[j++];
	 }
	 else
	 {
	     t[k++]=a[i++];
	 }
     }

     while(i<=mid)
	 t[k++] = a[i++];
     while(j<=high)
	 t[k++] = a[j++];
     for(i=low;i<=high;i++)
     {
	 a[i]=t[i];
     }
}

void msortdiv(int low,int high)
{
    int mid;
    if(low!=high)
    {
	mid=((low+high)/2);
	msortdiv(low,mid);
	msortdiv(mid+1,high);
	mergesort(low,mid,high);
    }
}
