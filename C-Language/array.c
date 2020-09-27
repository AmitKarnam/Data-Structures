#include<stdio.h>

void main()
{
  int array[5];   /* Declaring an array :  array_name[SIZE_0f_Array] */
  
  /* Array Indexing startes from 0 */
  
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;                /* Initialising array elements */
  array[3] = 4;
  array[4] = 5;
  
  printf("Array Elemnts in order:\n");
  
  for(int i=0;i<5;i++)
    {
       printf("%d ",array[i]);      /* Printing array elements */
    }
  
}

/* OUTPUT 

Array Elemnts in order:
1 2 3 4 5

*/
