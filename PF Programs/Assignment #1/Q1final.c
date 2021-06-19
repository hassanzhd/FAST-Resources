#include <stdio.h>
main ()   {
		float usage, bill, extra, increment;
		printf("PROGRAM TO CALCULATE WATER BILL BASED ON USAGE IN CUBIC FEET\n");
		printf("************************************************************\n");
		printf("                                                            \n");
		printf("Enter Water Usage In Cubic Feet: ");
		scanf("%f", &usage);
		if (usage<=1000) {
			bill= 15;
			printf("Water Bill is: $%f",bill);
		}
			else if (usage>1000&&usage<=2000)
		{
			bill=0.0175*usage;
			printf("Water Bill is $%f", bill);	
		}
					else if (usage>2000&&usage<=3000)
		{
			bill=0.02*usage;
			printf("Water Bill is $%f",bill);
		}
								else if (usage>3000)
								{
								printf("Water bill is $70.00");
						
								}








}

