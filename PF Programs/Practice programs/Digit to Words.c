# include <stdio.h>
main()
{	
	int num, remainder_100, remainder_10, digi_1, digi_2, digi_3 ;
	
	printf("\t\t\t====================================\n");
	printf("\t\t\tProgram to convert digits into words\n");
	printf("\t\t\t====================================\n");
	printf("\n");
	printf("\n");
	
	printf("Enter Your 3 digit number: ");
	scanf("%d", &num);
	remainder_100 = num%100;
	remainder_10 = remainder_100%10;
	digi_1 = num - remainder_100;	
	digi_2 = remainder_100 - remainder_10;
	digi_3 = remainder_10;
	
	switch(digi_1)
	{
		case 100:
		printf("%d in words: One hundred ", num);	
		break;
		
		case 200:
		printf("%d in words: Two hundred ", num);	
		break;
		
		case 300:
		printf("%d in words: Three hundred ", num);	
		break;
		
		case 400:
		printf("%d in words: Four hundred ", num);	
		break;
		
		case 500:
		printf("%d in words: Five hundred ", num);	
		break;
		
		case 600:
		printf("%d in words: Six hundred ", num);	
		break;
		
		case 700:
		printf("%d in words: Seven hundred ", num);	
		break;
		
		case 800:
		printf("%d in words: Eight hundred ", num);	
		break;
		
		case 900:
		printf("%d in words: Nine hundred ", num);	
		break;
		
		}

	if (digi_2 == 10)
	{
		if (digi_3==0)
		{
			printf("Ten ");
			return 0;
		}
		
		if (digi_3==1)
		{
			printf("Eleven ");
			return 0;
		}
		
		if (digi_3==2)
		{
			printf("Twelve ");
			return 0;
		}
		
		if (digi_3==3)
		{
			printf("Thirteen ");
			return 0;
		}
		
		if (digi_3==4)
		{
			printf("Fourteen ");
			return 0;
		}
		
		if (digi_3==5)
		{
			printf("Fifteen ");
			return 0;
		}
		
		if (digi_3==6)
		{
			printf("Sixteen ");
			return 0;
		}
		
		if (digi_3==7)
		{
			printf("Seventeen ");
			return 0;
		}
		
		if (digi_3==8)
		{
			printf("Eighteen ");
			return 0;
		}
		
		if (digi_3==9)
		{
			printf("Nineteen ");
			return 0;
		}
		
	}
		
	switch(digi_2)
	{
		case 20:
		printf("Twenty ");	
		break;
		
		case 30:
		printf("Thirty ");	
		break;
		
		case 40:
		printf("Fourty ");	
		break;
		
		case 50:
		printf("Fifty ");	
		break; 
		
		case 60:
		printf("Sixty ");	
		break;
		
		case 70:
		printf("Seventy ");	
		break;
		
		case 80:
		printf("Eighty ");	
		break;
		
		case 90:
		printf("Ninety ");	
		break;
		
		}		
		
	switch(digi_3)
	{
		case 1:
		printf("One");	
		break;
		
		case 2:
		printf("Two");	
		break;
		
		case 3:
		printf("Three");	
		break;
		
		case 4:
		printf("Four");	
		break;
		
		case 5:
		printf("Five");	
		break;
		
		case 6:
		printf("Six");	
		break;
		
		case 7:
		printf("Seven");	
		break;
		
		case 8:
		printf("Eight");	
		break;
		
		case 9:
		printf("Nine");	
		break;
		
		}	
	
}
