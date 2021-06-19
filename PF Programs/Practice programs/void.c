#include<stdio.h>
int main()
{
  
  int g[3];
  void *arr=g;
  int *a=arr;

  int i;
  for( i = 0; i < 3; i++)
  {
    printf("Enter element: ");
    scanf("%d", a+i);
  }

  for( i = 0; i <3; i++)
  {
    printf("%d\t", *(a+i));
  }
  
  
  return 0;
}
