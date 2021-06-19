#include <stdio.h>
main ()
{	float discount,bill,charge;
	int numberofpeople,age,prefrence;
	printf("PROGRAM TO CALCULATE BILL OF PEOPLE STAYING IN HOTEL\n");
	printf("****************************************************\n");
	printf("                                                    \n");	
	
	printf("Enter The Number Of People Staying:");
	scanf("%d",&numberofpeople);
	printf("Enter your ages:");
	scanf("%d", &age);
	printf("Are You On A Buisness Or Personal Trip? <1=Buisness,0=Personal>");
	scanf("%d", &prefrence);
	
	switch (numberofpeople)
	{
		case 1:
		charge = 0;
		break;
		
		case 2:
		charge = 85;
		break;
		
		case 3:
		charge= 90;
		break;
		
		case 4:
		charge = 95;
		break;
		
		default:
		charge = (numberofpeople-4)*6+95;	
			
		
		
	}
	
	if (charge!=0)
	{
			if (prefrence==1)
		{
			discount = charge*0.2;
			bill = charge-discount;
			printf("The discount you get is $%f\n",discount);
			printf("You bill is : $%f\n", bill);
			
				}
						else if (age>60)
						{
							discount = charge*0.15;
							bill = charge-discount;
							printf("The discount you get is $%f\n", discount);
							printf("Your bill is $%f\n", bill);
						}
						
						else {
								printf("You get no discount\n");
								printf("Your bill is $%f\n", charge);
							}
	}		
	
			else {
						printf("Data is invalid please try again.");
														}
		return 0;
	
	
	
	
	
}
