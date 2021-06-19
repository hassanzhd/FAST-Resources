# include <stdio.h>
main ()
{
	float number_of_units,bill;
	printf("Enter number of units consumed: ");
	scanf("%f", &number_of_units);
		
		if (number_of_units!=0)
		{
			if (number_of_units>=1 && number_of_units<=100)
					{
						bill = number_of_units*5.25;
						printf("Your electricity bill is $%f", bill);
						return 0;	
								}
		if (number_of_units>=101 && number_of_units<=200)
					{
						bill = number_of_units*7.75;
						printf("Your electricity bill is $%f", bill);					
										}		
		
		if (number_of_units>=201 && number_of_units<=300)
					{
						bill = number_of_units*8.92;
						printf("Your electricity bill is $%f", bill);					
						return 0;	
										}														
		
		if (number_of_units>=301 && number_of_units<=400)
					{
						bill = number_of_units*11.55;
						printf("Your electricity bill is $%f", bill);					
						return 0;
										}				
			
		if (number_of_units>400)
					{
						bill = number_of_units*12.71;
						printf("Your electricity bill is $%f", bill);					
						return 0;
										}		
						
		}
		
}
