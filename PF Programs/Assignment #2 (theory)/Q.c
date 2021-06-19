#include<stdio.h>
#include<math.h>
	distance()
{	
	int x1a,x2a,y1a,y2a;
	float dis;
	printf("Enter points to calculate distance from x1 , y1 to x2 , y2: \n\n");
	printf("Enter A(x1, y1): ");
	scanf("%d%d", &x1a, &y1a);
	printf("\n");
	printf("Enter B(x2, y2): ");
	scanf("%d%d", &x2a, &y2a);
	dis=sqrt((x2a-x1a)*(x2a-x1a)+(y2a-y1a)*(y2a-y1a));
	printf("\n");
	printf("Distance between A and B = %f", dis);
}

	ar()
{
	float x1,y1,x2,y2,x3,y3,a,b,c,area,s;
	printf("Enter vertices of triangle i.e x1 , y1 ; x2 , y2 ; x3 , y3 to calculate area of triangle: \n\n");
	printf("Enter x1, y1: ");
	scanf("%f%f", &x1, &y1);
	printf("Enter x2, y2: ");
	scanf("%f%f", &x2, &y2);
	printf("Enter x3, y3: ");
	scanf("%f%f", &x3, &y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("%f", area);	
	}
main()
{	
	distance();
	printf("\n");
	printf("\n");
	ar();
}
