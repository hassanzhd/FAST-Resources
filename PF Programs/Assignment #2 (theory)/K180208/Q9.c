#include <stdio.h>
#include <string.h>

getNumAccidents(Region)
{	
	int accidents;
	printf("Enter number of accidents: ");
	scanf("%d", &accidents);
	
	while(accidents<0)
	{	
		printf("Enter Valid number. \n");
		printf("Enter number of accidents: ");
		scanf("%d", &accidents);
		}

	return accidents;
	
}

findlowest(int a, int b, int c, int d, int e)
{
	if(a<b && a<c && a<d && a<e )
	{
		printf("Lowest number of accidents happened in North = %d", a);
	}
	
		if(b<a && b<c && b<d && b<e )
	{
		printf("Lowest number of accidents happened in South = %d", b);
	}
	
		if(c<a && c<b && c<d && c<e )
	{
		printf("Lowest number of accidents happened in East = %d", c);
	}
	
		if(d<a && d<b && d<c && a<e )
	{
		printf("Lowest number of accidents happened in West = %d", d);
	}
	
		if(e<a && e<b && e<c && a<d )
	{
		printf("Lowest number of accidents happened in Central = %d", e);
	}
	
}



main()
{
	int north,south,east,west,central;
	
	printf("North: \n");
	north=getNumAccidents("North");
	printf("South: \n");
	south=getNumAccidents("South");
	printf("East: \n");
	east=getNumAccidents("East");
	printf("West: \n");
	west=getNumAccidents("West");
	printf("Central: \n");
	central=getNumAccidents("Central");
	printf("\n");
	


    findlowest(north,south,east,west,central);


}
