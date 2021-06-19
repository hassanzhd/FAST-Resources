#include<stdio.h>
main()
{
	int id[10], num[10];
	char grade[10];
	int i;
	int a=0,b=0,c=0,d=0,f=0;
	
		for(i=0;i<10;i++)
	{
	
		printf("Enter ID of student # %d: ", i+1);
		scanf("%d", &id[i]);
		printf("Enter number grade: ");
		scanf("%d", &num[i]);
		printf("\n");
		
		if(num[i]>=90 && num[i]<=100)
		{
			grade[i]='A';
			a=a+1;
		}
		
		if(num[i]>=78 && num[i]<=89)
		{
			grade[i]='B';
			b=b+1;
		}
		
		if(num[i]>=65 && num[i]<=77)
		{
			grade[i]='C';
			c=c+1;
		}
		
		if(num[i]>=50 && num[i]<=64)
		{
			grade[i]='D';
			d=d+1;
		}
		
		if(num[i]<50)
		{
			grade[i]='F';
			f=f+1;
		}
		
	
	}
	
		for(i=0;i<10;i++)
		{
			printf("Student Number: %d\n", id[i]);
			printf("Number Grade: %d\n", num[i]);
			printf("Letter Grade: %c\n", grade[i]);
			printf("\n\n");
		}
	

	printf("Number of A grades are: %d\n", a);
	printf("Number of B grades are: %d\n", b);
	printf("Number of C grades are: %d\n", c);
	printf("Number of D grades are: %d\n", d);
	printf("Number of F grades are: %d\n", f);
}
