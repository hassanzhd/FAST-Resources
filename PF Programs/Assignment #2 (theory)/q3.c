#include <stdio.h>
ke(int m, int v)
{	
	int kinetic;
	kinetic=(m*v*v)*0.5;
	printf("Kinetic energy of mass %d Kg and velocity %d m/s is : %d Joules", m , v , kinetic);
}

main()
{
	int mass,velocity;
	printf("Enter mass of object: ");
	scanf("%d", &mass);
	printf("Enter velocity of object: ");
	scanf("%d", &velocity);
	ke(mass,velocity);
}
