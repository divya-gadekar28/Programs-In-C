#include<stdio.h>

void quicksort (int x[20], int first, int last)
{
     int pivot, j, temp, i;
     if(first < last)
     {
	  pivot=first;
	  i=first;
	  j=last;

		 while(i < j)
		 {
	     while(x[i] <= x[pivot] && i<last)
		  i++;
	     while( x[j] > x[pivot] )
		  j--;
	     if(i<j)
	     {
		  temp = x[i];
		  x[i] = x[j];
		  x[j] = temp;
	     }
	}

	temp = x[pivot];
	x[pivot] = x[j];
	x[j] = temp;

	quicksort(x,first,j-1);
	quicksort(x,j+1,last);
     }
}

void main()
{
      int x[20], size, i;
      clrscr();
      printf("\tQuick sort\n");
      printf("-----------------------------------\n");
      printf("How many numbers you want to sort?\n");
      scanf("%d",&size);
      printf("\nEnter %d elements:\n",size);
      for(i=0;i<size;i++)
      {
	  scanf("%d",&x[i]);
      }
      quicksort(x,0,size-1);
      printf("\nSorted elements after applying quick sort: \n\n");
      for(i=0;i<size;i++)
      {
	  printf( " %d", x[i] );
      }
      getch();
}
