# include <stdio.h>
main ()
{
	float measure_1,measure_2,measure_3;
	printf("**************************************************************************\n");
	printf("Program to determine what kind of triangle depending upon specified values\n");
	printf("**************************************************************************\n");
	printf("\n");
	printf("Enter first measure angle of the triangle: ");
	scanf("%f", &measure_1);
	printf("Enter second measure angle of the triangle: ");
	scanf("%f", &measure_2);
	printf("Enter third measure angle of the triangle: ");
	scanf("%f", &measure_3);
		if( measure_1==0 || measure_2==0 || measure_3==0)
			{
				printf("Triangle cannot be formed as angles are invalid");
				return 0;
			
			}
			
				if(measure_1+measure_2+measure_3!=180)
			{
				printf("Triangle cannot be formed as angles are not equal to 180");
				return 0;
			
			}
			
		
		if (measure_1+measure_2+measure_3==180)
		{
			
				if (measure_1 == measure_2 && measure_2 == measure_3)
			{
				
				printf("Entered values form an equilateral triangle");
			}
				
				else if(measure_1 == measure_2 || measure_2 == measure_3 || measure_1 == measure_3)
					{
						printf("Entered values form an isosceles triangle ");
					}
				
						else if (measure_1 != measure_2 && measure_2 != measure_3)
							{
							
								printf ("Entered values form a scalene triangle");
							}
							
								}
								
										
	
	return 0;
}
