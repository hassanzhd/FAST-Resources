#include<stdio.h>
main()
{
	int i,j,space,rows,pri;
	printf("Enter rows: ");
	scanf("%d", &rows);
	for(i=1;i<=rows;i++)
	{	
		
		for(space=1;space<=(2*rows)-(2*i);space++)
		{
			printf(" ");
		}
		
		for(pri=1,j=65;pri<=i;pri++,j++)
		{	
			
			printf("%c ", j);
		}
		
		printf("\n");
	
	}
	for(i=1;i<=rows;i++)
	{	
	
		for(space=2;space<=2*rows;space++)
		{
			printf(" ");
		}
		for(pri=rows,j=65;pri>=i;pri--,j++)
		{
			printf("%c ", j);
		}
		
	
		printf("\n");

	}
}
