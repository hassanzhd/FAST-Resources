#include<stdio.h>
#include <math.h>
presentValue( double a, double b, double c )
{	
	int i;
	double p_value;
	double sum;
	sum=1+b;
	sum=(pow(sum,c));
	p_value=a/sum;
	printf("Amount to deposit today is = %lf", p_value);
		
}

main()
{
	double years,f_value,interest;
	printf("Enter future value: ");
	scanf("%lf", &f_value);
	printf("Enter annual interest rate: ");
	scanf("%lf", &interest);
	printf("Enter no of years: ");
	scanf("%lf", &years);
	presentValue(f_value,interest,years);
}
