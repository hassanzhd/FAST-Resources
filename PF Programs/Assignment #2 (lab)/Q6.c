#include<stdio.h>

int Fibonacci(int no)
{
   if ( no == 0 )
      return 0;
   else if ( no == 1 )
      return 1;
   else
      return ( Fibonacci(no-1) + Fibonacci(no-2) );
}

int main()
{
   int n, i = 0, a;
   
	printf("Enter range: ");		 	
	scanf("%d",&n);
 
   printf("Fibonacci series: \n");
 
   for ( a = 1 ; a <= n ; a++ )
   {
      printf("%d ", Fibonacci(i));
      i++; 
   }
 
   return 0;
}
 
