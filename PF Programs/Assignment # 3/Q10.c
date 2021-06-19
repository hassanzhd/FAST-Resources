#include<stdio.h>
int power(int a, int b)
{
	
	if(b==0)
	{
		return 1;
	}
	
	else 
	{
		return a*power(a,b-1);
	}
	
}
main()
{
	
	int number,exponent;
	printf("Enter number: ");
	scanf("%d", &number);
	printf("Enter exponent: ");
	scanf("%d", &exponent);
	printf("%d^%d = %d", number, exponent, power(number,exponent)); 
	
}

