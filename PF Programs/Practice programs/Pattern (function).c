#include<stdio.h>
lines(int num)
	{	int i, j;
		for(i=1;i<=num;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

main()
{	int num;
	printf("Enter number of lines: ");
	scanf("%d", &num);
	lines(num);
	
}



