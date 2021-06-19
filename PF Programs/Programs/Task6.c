# include <stdio.h>
# include <math.h>
# include <conio.h>
main()
{	int operation;
	int number_1, number_2, Addition, Subtraction, Multiplication;
	int Modulo, Square,power;
	float div, Square_root,Cube_root,exponent, ans;
	printf("CALCULATOR\n");
	printf("\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Modulo\n");
	printf("6. Square\n");
	printf("7. Square Root\n");
	printf("8. Cube Root\n");
	printf("9. Exponent\n");	
	printf("10. Logarithm\n");
	printf("11. Sinusoidal\n");
	printf("12. Co-sinusoidal\n");
	printf("13. Tangent\n");
	printf("14. Absolute\n");
	printf("\n");
	printf("Enter option <1-14> to perform operation ");
	scanf("%d", &operation);
	switch (operation)
	{
		case 1:
		printf("Enter 2 numbers to perform addition: ");
		scanf("%d%d", &number_1, &number_2);
		Addition = number_1+number_2;
		printf("The Sum/Addition of the two numbers is %f", Addition);	
		break;
		
		case 2:
		printf("Enter 2 numbers to perform subtraction: ");
		scanf("%d%d", &number_1, &number_2);
		Subtraction = number_1-number_2;
		printf("The difference of the two numbers is %f", Subtraction);
		break;
		
		case 3:
		printf("Enter 2 numbers to perform multiplication: ");
		scanf("%d%d", &number_1, &number_2);
		Multiplication = number_1*number_2;
		printf("The product of the two numbers is %f", Multiplication);
		break;
		
		case 4:
		printf("Enter 2 numbers to perform division: ");
		scanf("%d%d", &number_1, &number_2);
		div = number_1/number_2;
		printf("The division of the two numbers gives %f", div);
		break;
		
		case 5:
		printf("Enter 2 numbers to perform modulo: ");
		scanf("%d%d", &number_1, &number_2);
		Modulo = number_1%number_2;
		printf("The Modulo of the two numbers is %d", Modulo);
		break;
		
		case 6:
		printf("Enter number to perform square: ");
		scanf("%d", &number_1);
		Square = number_1*number_1;
		printf("The Square of the number is %d", Square);
		break;
		
		case 7:
		printf("Enter number to perform square root: ");
		scanf("%d", &number_1);
		Square_root = sqrt(number_1);
		printf("The Square of the number is %f", Square_root);
		break;
		
		case 8:
		printf("Enter number to perform cube root: ");
		scanf("%d", &number_1);
		Cube_root = cbrt(number_1);
		printf("The Square of the number is %f", Cube_root);
		break;

		case 9:
		printf("Enter number to perform exponent: ");
		scanf("%d", &number_1);
		printf("Enter power");
		scanf("%d", power);
		exponent = pow(number_1, power);
		printf("The Square of the number is %f", exponent);
		break;

		case 10:
		printf("Enter number to perform logarithm: ");
		scanf("%d", &number_1);
		ans = log(number_1);
		printf("The log of the number is %f", ans);
		break;
		
		case 11:
		printf("Enter number to perform sin: ");
		scanf("%d", &number_1);
		ans = sin(number_1);
		printf("The sin of the number is %f", ans);
		break;
		
		case 12:
		printf("Enter number to perform cos: ");
		scanf("%d", &number_1);
		ans = cos(number_1);
		printf("The cos of the number is %f", ans);
		break;
		
		case 13:
		printf("Enter number to perform tan: ");
		scanf("%d", &number_1);
		ans = tan(number_1);
		printf("The tan of the number is %f", ans);
		break;
		
		case 14:
		printf("Enter number to perform absolute value: ");
		scanf("%d", &number_1);
		ans = abs(number_1);
		printf("The absolute of the number is %f", ans);
		break;










	}
	
}

