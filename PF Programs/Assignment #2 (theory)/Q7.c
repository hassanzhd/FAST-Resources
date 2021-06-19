#include<stdio.h>

float calculateRetail(float x, float y)
{	int retail;
	y=y/100;
	retail=(x*y)+x;
	return retail;
}

main()
{	float wholesale_cost,percentage;
	printf("Enter wholesale cost: $");
	scanf("%f", &wholesale_cost);
	printf("Enter markup percentage: ");
	scanf("%f", &percentage);
	printf("Retail price = $%.3f" , calculateRetail(wholesale_cost,percentage));

}
