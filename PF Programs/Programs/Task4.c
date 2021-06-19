# include <stdio.h>
main ()

{
	int day,month;
	printf("Enter month of birth <1-12, January-December>: ");
	scanf("%d", &month);
	printf("Enter day of birth <1-31>: ");
	scanf("%d", &day);
		
		if (month != 0 && day!=0)
			{
				if (day>31)
				{
					printf("Invalid entry.");
					return 0;
								}				
				if (month==1)
					{
							
						if (day>=1 && day<=19)
						{
							printf("Your Zodiac Sign is Capricorn");
						}
					else printf("Your Zodiac Sign is Aquarius");	
					
					}
				
				if (month==2)
					{
						if ((day==30) || (day==31))
						{
							printf("Value invalid");
							return 0;
						}
						
						if (day>=1 && day<=17)
					
						{
							printf("Your Zodiac Sign is Aquarius");
						}
						
						else printf("Your Zodiac Sign is Pisces");	

					}
				
				if (month==3)
					{
					
						if (day>=1 && day<=19)
							{
								printf("Your Zodiac Sign is Pisces");
							}
					else printf("Your Zodiac Sign is Aries");	

					}
					
				if (month==4)
					{
						if (day==31)
						{
							printf("Value invalid");
							return 0;
						}
						if (day>=1 && day<=19)
						{
							printf("Your Zodiac Sign is Aries");
						}
					else printf("Your Zodiac Sign is Taurus");	

					}
	
				if (month==5)
					{
						if (day>=1 && day<=20)
						{
							printf("Your Zodiac Sign is Taurus");
						}
					else printf("Your Zodiac Sign is Gemini");	

					}
				
				if (month==6)
					{	
						if (day==31)
						{
							printf("Value invalid");
							return 0;
						}
						if (day>=1 && day<=20)
						{
							printf("Your Zodiac Sign is Gemini");
						}
					else printf("Your Zodiac Sign is Cancer");	

					}
					
				if (month==7)
				{		
						if (day>=1 && day<=22)
						{
							printf("Your Zodiac Sign is Cancer");
						}
					else printf("Your Zodiac Sign is Leo");	

					}
						
				if (month==8)
					{	
						
						if (day>=1 && day<=22)
						{
							printf("Your Zodiac Sign is Leo");
						}
					else printf("Your Zodiac Sign is Virgo");	

					}
					
				if (month==9)
					{
						if (day==31)
						{
							printf("Value invalid");
							return 0;
						}
						if (day>=1 && day<=22)
						{
							printf("Your Zodiac Sign is Virgo");
						}	
					else printf("Your Zodiac Sign is Libra");	

					}
					
				if (month==10)
					{	
						if (day>=1 && day<=22)
						{
							printf("Your Zodiac Sign is Libra");
						}			
					else printf("Your Zodiac Sign is Scorpio");	

					}
				
				if (month==11)
					{	if (day==31)
						{
							printf("Value invalid");
							return 0;
						}
					
						if (day>=1 && day<=21)
						{
							printf("Your Zodiac Sign is Scorpio");
						}
					else printf("Your Zodiac Sign is Sagittarius");	

					}
					
				if (month==12)
					{
						if (day>=1 && day<=21)
					{
							printf("Your Zodiac Sign is Sagittarius");
						}	
					else printf("Your Zodiac Sign is Capricorn");	
					
					}				
			}
			
		
	
}
