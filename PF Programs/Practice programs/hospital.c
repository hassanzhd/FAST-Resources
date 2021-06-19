#include<stdio.h>
#include<stdlib.h>
main()
{
	char qua[][20]={"Spring", "Fall","Winter","Summer"};
	char unit[][20]={"Emer","Medic","Onco","Ortho","Psyco"};
	int *arr=(int *) calloc(20,sizeof(int));
	
	int i,j;
	for(i=0;i<5;i++)
	{		for(j=0;j<4;j++)
		{
			printf("Enter revenue of %s of %s: ", qua[j],unit[i]);
			scanf("%d", arr+i*4+j);
		}
	}
	
	printf("\n\n");
	
	printf("Unit\t\t%s\t\t%s\t\t%s\t%10s\tTotal\n", qua[0],qua[1],qua[2],qua[3]);
	printf("------------------------------------------------------------------------------\n");
	for(i=0;i<5;i++)
	{	
		int sum=0;
		printf("%s",unit[i]);
		for(j=0;j<4;j++)
		{
			printf("\t\t%d", *(arr+i*4+j));
			sum+=*(arr+i*4+j);
		}
		
		printf("\t%5d",sum);
		printf("\n");
	}
	
	printf("\n");
	
	printf("\n");
	printf("Total\t\t");
	for(j=0;j<4;j++)
	{	
		int sum1=0;
		for(i=0;i<5;i++)
		{
			sum1+=*(arr+i*4+j);
		}
		printf("%d\t\t", sum1);

	}
	
}
