# include<stdio.h>
main()
{
	char first_roman_number,second_roman_number, third_roman_number;
	int number_1,number_2,number_3,decimal;
	printf("PROGRAM TO CONVERT THREE DIGIT ROMAN NUMERALS TO DECIMAL NUMBER\n");
	printf("***************************************************************\n");
	printf("\n");
	printf("Enter First Roman Number (Use I, V, X, L, C, D, USE ZERO FOR NULL): ");
	scanf(" %c",&first_roman_number);
	printf("Enter Second Roman Number (Use I, V, X, L, C, D, USE ZERO FOR NULL): ");
	scanf(" %c",&second_roman_number);
	printf("Enter Third Roman Number (Use I, V, X, L, C, D, USE ZERO FOR NULL): ");
	scanf(" %c",&third_roman_number);
	
		switch(first_roman_number)
	{
		case 'I' :
		number_1 = 1;
		break;	
		
		case 'V' :
		number_1 = 5;
		break;
		
		case 'X' :
		number_1 = 10;
		break;
		
		case 'L' :
		number_1 = 50;
		break;
		
		case 'C' :
		number_1 = 100;
		break;
		
		case 'D' :
		number_1 = 500;
		break;
		
		default :
		number_1 = 0; 
	}
	
		switch(second_roman_number)
	{
		case 'I' :
		number_2 = 1;
		break;	
		
		case 'V' :
		number_2 = 5;
		break;
		
		case 'X' :
		number_2 = 10;
		break;
		
		case 'L' :
		number_2 = 50;
		break;
		
		case 'C' :
		number_2 = 100;
		break;
		
		case 'D' :
		number_2 = 500;
		break;
		
		default :
		number_2 = 0; 
	}

		switch(third_roman_number)
	{
		case 'I' :
		number_3 = 1;
		break;	
		
		case 'V' :
		number_3 = 5;
		break;
		
		case 'X' :
		number_3 = 10;
		break;
		
		case 'L' :
		number_3 = 50;
		break;
		
		case 'C' :
		number_3 = 100;
		break;
		
		case 'D' :
		number_3 = 500;
		break;
		
		default :
		number_3 = 0; 
	}	
		
		if ((number_1==number_2 && number_2==number_3) || number_1==0 || number_2==0 || number_3==0 )
		{
			decimal=number_1+number_2+number_3;
			printf("\nEquivalent Decimal Number is: %d", decimal);
		}
		
			else if ((number_1>number_2) || (number_1==0))
				{
					if (number_2>number_3)
					{
						decimal = number_1+number_2+number_3;
						printf("\nEquivalent Decimal Number is: %d", decimal);
											}
					if (number_2<number_3)
						{
							decimal = number_1+(number_3-number_2);
							printf("\nEquivalent Decimal Number is: %d", decimal);
												}						
				}
			else printf("Entry is invalid.");
				
				
				
				
	
}
