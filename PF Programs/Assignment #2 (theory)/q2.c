#include<stdio.h>


without(int x)
{	int sum=0;
	while(x>0)
	{
		sum=sum+(x%10);
		x=x/10;
	}

	return sum;
	
	}

rec(int a)
{	
	int sum1=0;
	if(a<=0)
	{
		return 0;
	
		}
			
	else
	{
		
	return a%10+rec(a/10);

	
	}
}

main()
{
	int digit;
	printf("Enter a five digit number: ");
	scanf("%d", &digit);
	without(digit);
	printf("%d\n", without(digit));
	printf("%d\n", rec(digit));
	
	
}
