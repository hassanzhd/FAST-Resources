#include<stdio.h>
#include<stdlib.h>
int main()
{
  
  int **arr= (int **)calloc(4,sizeof(int *));
  int i,j;
  for( i = 0; i <4; i++)
  {
    *(arr+i)=calloc(4,sizeof(int));
  }

  for( i = 0; i < 4; i++)
  {

    for( j = 0; j< 4; j++)
    {
      printf("Enter element of %d row and %d column: ", i+1,j+1);
      scanf("%d", &arr[i][j]);
    }    

  }

  for( i = 0; i < 4; i++)
  {
    
    for( j = 0; j < 4; j++)
    {
      printf("%d\t", *(*(arr+i)+j));
    }
    printf("\n");
  }
  
  return 0;
}
