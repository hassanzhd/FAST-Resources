#include<stdio.h>
int main()
{
  
  void *arr[3];

  int i;
  for( i = 0; i < 3; i++)
  {
    printf("Enter element: ");
    scanf("%d", (int *)(arr+i));
  }

  
  for( i = 0; i < 3; i++)
  {
    printf("%d\t", *((int *)arr+i));
  }
  
  int sum=0;
  for( i = 0; i < 3; i++)
  {
    sum+=*(((int *)arr+i));
  }

  printf("\n");
  printf("%d", sum);
  

  return 0;
}
