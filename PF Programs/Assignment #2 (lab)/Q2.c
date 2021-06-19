#include <stdio.h>
int IterativeSum()
{	int i;
	int sum2=0;
	
	for(i=1;i<=10;i++)
	{
		sum2=sum2+i;
	}
	printf("Sum of first 10 natural numbers by iteration is: %d", sum2);
	
}

int RecursiveSum(int sum1)
{
	if (sum1==0)
	{
		return 0;
	}
	else
	{
	
	return sum1+RecursiveSum(sum1-1);
	
	}		
}

main()
{	int choice,ie,sum;
	printf("Program to display sum of natural numbers according to user prefrence\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("Enter your prefrence <1. Iterative Sum, 2. Recursive Sum> :  ");	
	scanf("%d", &choice);
	
	if(choice==1)
	{
			IterativeSum();
		
	}
	
	if(choice==2)
	 {	
			
		printf("Sum of first 10 natural numbers by recursion is: %d\n",RecursiveSum(10));
			
	}
		}
	
	
