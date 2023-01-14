// Binary Search in C

#include<stdio.h>
#include<conio.h>
int binarySearch(int array[], int x, int low,int high)
{
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

void main()
{
  int array[50],n,i,x,result;
  printf("how many elements?");
  scanf("%d",&n);
  printf("enter %d elements in an array",n);
  for(i=0;i<n;i++)
  {
  scanf("%d",&array[i]);
  }
  printf("enter the element to be searched");
  scanf("%d",&x);
  result = binarySearch(array,x,0,n-1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result+1);
  getch();
}