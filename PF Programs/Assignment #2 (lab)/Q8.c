#include <stdio.h>
int display(int row, int column)
{	int i,j,u;
	printf("\n");
	for(u=1;u<=column;u++)
	{
		printf("\t%d", u);
	}
	
	for(i=1;i<=row;i++)
	{	
		printf("\n%d*",i);
		for(j=1;j<=column;j++)
		{
			printf("\t%d", i*j);
		}
	
			}		
}


main()
{
	int num,multiples;
	printf("Enter Number of which tables is to be generated: ");
	scanf("%d", &num);
	printf("Enter Muliples till which table is to be generated: ");
	scanf("%d", &multiples);
	display(num, multiples);
}
