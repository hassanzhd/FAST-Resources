#include<stdio.h>

float x,y,z;
gallon(float u)
{	
	float x;
	x=u/180;
	printf("%f\n", x);
}
labor(float v)
{	
	float y;
	
	y=x*3;
	printf("%f", y);
	
	}

paint_cost(float p, float q)
{	
	int z;
	 
	
}

main()
{
	int i;
	int rooms,x,y,z;
	int wallspace;
	int total_wall=0;
	int price;
	printf("Enter number of rooms: ");
	scanf("%d", &rooms);
	
	for(i=1;i<=rooms;i++)
	{
	
	printf("Enter approximate wall space: ");
	scanf("%d", &wallspace);
	wallspace=wallspace*4;
	total_wall=total_wall+wallspace;			
	
	}
	
	printf("Enter price per gallon: ");
	scanf("%d", &price);
		
	gallon(total_wall);
	labor(total_wall);
	paint_cost(total_wall,price);
//	labor_charges(total_wall,price);
//	total_cost(total_wall,price);
	
}
