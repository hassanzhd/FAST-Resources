#include<stdio.h>
main()
{
	int rows,space,pri,i,j,num=1;
	printf("Enter rows: ");
	scanf("%d", &rows);
	printf("\n\n");
	for(i=0;i<rows;i++)
	{
		for(space=1;space<=rows-i;space++)
		{
		
			printf("  ");
		
		}
		
		for(j=0;j<=i;j++)
		{
			if(i==0 || j==0)
			num=1;
			else
			num=num*(i-j+1)/j;
			
			printf("%3d ", num);
		
		}	
		
		printf("\n");
			
	}
}
