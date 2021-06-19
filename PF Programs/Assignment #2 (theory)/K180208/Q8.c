#include <stdio.h>
#include <string.h>

double getSales(Region)
{	
	double sales;
	printf("Enter sales: ");
	scanf("%lf", &sales);
	
	while(sales<0)
	{	
		printf("Enter Valid number. \n");
		printf("Enter sales: ");
		scanf("%lf", &sales);
		}

	return sales;
	
}

void findHighest(double a, double b, double c, double d)
{
	if(a>b && a>c && a>d )
	{
		printf("Highest Sales in Northeast = %lf", a);
	}
	
		if(b>a && b>c && b>d )
	{
		printf("Highest Sales in Southeast = %lf", b);
	}
	
		if(c>a && c>b && c>d )
	{
		printf("Highest Sales in Northwest = %lf", c);
	}
	
		if(d>a && d>b && d>c )
	{
	
		printf("Highest Sales in Southwest = %lf", d);
	}
	
	
}



main()
{
	int northeast,southeast,northwest,southwest;
	
	printf("Sales of Northeast: \n");
	northeast=getSales("Northeast");
	printf("Sales of Southeast: \n");
	southeast=getSales("Southeast");
	printf("Sales of Northwest: \n");
	northwest=getSales("Northwest");
	printf("Sales of Southwest: \n");
	southwest=getSales("Southwest");

	printf("\n");
	
	findHighest(northeast,southeast,northwest,southwest);


}
