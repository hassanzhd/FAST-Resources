#include<stdio.h>
main()
{	
	int bolts, nuts ,washers, cost_of_washers, cost_of_bolts, cost_of_nuts,total;
	printf("Enter number of bolts: ");
	scanf("%d", &bolts);
	printf("Enter number of nuts: ");
	scanf("%d", &nuts);
	printf("Enter number of washers: ");
	scanf("%d", &washers);
	if(nuts<0 || washers<0 || bolts<0)
	{
		printf("Enter Valid Entry.");
	}
	cost_of_bolts=bolts*5;
	cost_of_nuts=nuts*3;
	cost_of_washers=washers*1;
	total= cost_of_washers + cost_of_bolts + cost_of_nuts;
	printf("\n");
	printf("\n");
	printf("\tNumber of bolts:\t%d\n", bolts);
	printf("\tNumber of nuts: \t%d\n", nuts);
	printf("\tNumber of washers:\t%d\n", washers);
	printf("\n");
	if(nuts>=bolts && washers>=2*bolts)
	{
		printf("\tCheck the order:\tOrder is OK.\n");
		printf("\tTotal Cost:\t\t%d", total);
	}
	
	else if(nuts<bolts && washers>=2*bolts)
	{
		printf("\tCheck the order:\ttoo few nuts.\n");
		printf("\tTotal Cost:\t\t%d", total);
	}
	
	else 
	{
		printf("\tCheck the order:\ttoo few nuts. too few washers.\n");
		printf("\tTotal Cost:\t\t%d", total);
}

}
