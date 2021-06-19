#include<stdio.h>
main()
{	int hardness,carbon_content,tensile_strength;
	printf("Enter Hardness: ");
	scanf("%d", &hardness);
	printf("Enter Carbon Content: ");
	scanf("%d", &carbon_content);
	printf("Enter Tensile Strength: ");
	scanf("%d", &tensile_strength);
	
	if(hardness==0 || carbon_content==0 || tensile_strength==0 )
	{
		printf("Enter Valid Entries.");	
	}
	
	if(hardness!=0 && carbon_content!=0 && tensile_strength!=0)
	{
	
		if(hardness>50 && carbon_content<70 && tensile_strength>5600)
		{
			printf("Grade is 10");
			return 0;
		}
		 if (hardness>50 && carbon_content<70 && tensile_strength<=5600)
		{
			printf("Grade is 9");
			return 0;;
		}	
		 if (hardness<=50 && carbon_content<70 && tensile_strength>5600)
		{
			printf("Grade is 8");
			return 0;
		}
		 if (hardness>50 && carbon_content>=70 && tensile_strength>5600)
		{
			printf("Grade is 7");
			return 0;
		}	
		 if (hardness>50 || carbon_content<70 || tensile_strength>5600)
		{
			printf("Grade is 6");
			return 0;
		}	
		else {
			printf("Grade is 5");
			return 0;
		}
}

	
	}
