#include<stdio.h>
#define size 6
main()
{
	int gallons[size],initial[size],final[size],miles[size];
	float avg_miles[size],total=0;
	int i;
	for(i=0;i<6;i++)
	{
		printf("Enter no of gallons filled for %d fillup: ", i+1);
		scanf("%d", &gallons[i]);
		printf("Enter initial odometer reading: ");
		scanf("%d", &initial[i]);
		printf("Enter final odometer reading: ");
		scanf("%d", &final[i]);
		miles[i]=final[i]-initial[i];
		avg_miles[i]=miles[i]/gallons[i];	
		printf("Average miles per gallon for %d fillup = %f\n",i+1, avg_miles[i]);
		printf("\n\n");
	}	
	
	total=(avg_miles[0]+avg_miles[1]+avg_miles[2]+avg_miles[3]+avg_miles[4]+avg_miles[5])/size;
	printf("Average miles per gallon after six fillups = %f", total);
	
}
