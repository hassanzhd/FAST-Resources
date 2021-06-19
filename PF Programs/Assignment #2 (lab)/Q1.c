#include <stdio.h>
int even(int num2)
{
		num2=num2/2;
		if(num2==1)
		{
			printf("Last Value is: %d\n", num2);
		}
	else
	{
		
	printf("The next value is: %d\n", num2);
		
	}	
	return num2;
	
}

int odd(int num3)
{
	
	
		num3=(num3*3)+1;
		if(num3==1)
		{
			printf("Last value is: %d", num3);
		}
	else
	{
		printf("The next value is: %d\n", num3);
	}	
		return num3;
}

main()
	{
		int num1,i;
		printf("Enter Number: ");
		scanf("%d", &num1);
		if(num1<1)
		{
			printf("Error\n");
		}
		i=0;
		while(num1>1)
		{	
			i++;
		
		if(num1%2==0)
		{
			num1=even(num1);		
		}
		else 
			{
				num1=odd(num1);
			}
			
		}
		
		
		printf("Total operations performed: %d", i);
	
	}

