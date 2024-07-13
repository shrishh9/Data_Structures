#include <stdio.h>
 int main() {
    int array[100],i,j,k,swap,n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter %d integers\n", n);
for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (array[j] > array[j+1])
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
    printf("The sorted array in %d pass is:",i+1);
	    for(k=0;k<n;k++)
	    {
		   printf("%d ",array[k]);
	    }printf("\n");
  }
  printf("\n Sorted list in ascending order:\n");
  for (i = 0; i < n; i++)
     printf("%d\n", array[i]);
    return 0;
} 
