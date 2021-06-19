# include <stdio.h>
main()
{
	float current_salary,increment, new_salary;
	int years_of_service;
	printf("****************************************\n");
	printf("Program to calculate increment in salary\n");
	printf("****************************************\n");
	printf("\n");
	printf("Enter Years of service: ");
	scanf("%d", &years_of_service);
	printf("Enter Current Salary: ");
	scanf("%f", &current_salary);
	if (years_of_service>3 && current_salary>=10000)
		{
			if (current_salary>=10000 && current_salary<15000)
			{
				increment = current_salary*0.07;
				new_salary = increment+current_salary;
				printf("\n");				
				printf("You get an increment of: $%f\n", increment);
				printf("Your new salary is $%f", new_salary);
			}
			
			if (current_salary>=15000 && current_salary<20000)
			{
				increment = current_salary*0.04;
				new_salary = increment+current_salary;
				printf("\n");			
				printf("You get an increment of: $%f\n", increment);
				printf("Your new salary is: $%f", new_salary);
			}
			
			if (current_salary>=20000 && current_salary<40000)
			{
				increment = current_salary*0.025;
				new_salary = increment+current_salary;
				printf("\n");
				printf("You get an increment of: $%f\n", increment);
				printf("Your new salary is: $%f", new_salary);
			}
			
			if (current_salary>=40000)
			{
				increment = current_salary*0.02;
				new_salary = increment+current_salary;
				printf("\n");
				printf("You get an increment of: $%f\n", increment);
				printf("Your new salary is: $%f", new_salary);
			}
										
		}
	else printf("Sorry! You recieve no increment");		
	
}
