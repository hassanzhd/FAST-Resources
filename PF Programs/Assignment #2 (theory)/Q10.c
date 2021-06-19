#include<stdio.h>
int findHighest(int a, int b, int c, int d, int e);
int findLowest(int a, int b, int c, int d, int e);
int getJudgedata()
{	
	int score;
	printf("Enter score: ");
	scanf("%d", &score);
	return score;
	
}

double calcScore(double a, double b, double c, double d, double e)
{	
	double lowest,highest,sum,avg;
	lowest=findLowest(a,b,c,d,e);
	highest=findHighest(a,b,c,d,e);
	sum=a+b+c+d+e-lowest-highest;
	avg=sum/3;
	printf("Average is: %f", avg);
	
}

int findLowest(int a, int b, int c, int d, int e)
{	

	if(a<b && a<c && a<d && a<e)
	{
			return a; 
	}
		
	else if(b<a && b<c && b<d && b<e)
	{
			return b; 
	}
	
	else if(c<a && c<b && a<d && a<e)
	{
			return c; 
	}
	
	else if(d<a && d<b && d<c && d<e)
	{
			return d; 
	}
	
	else if(e<a && e<b && e<c && e<d)
	{
			return e; 
	}
	
}

int findHighest(int a, int b, int c, int d, int e)
{	
		if(a>b && a>c && a>d && a>e)
	{
			return a; 
	}
		
	else if(b>a && b>c && b>d && b>e)
	{
			return b; 
	}
	
	else if(c>a && c>b && a>d && a>e)
	{
			return c; 
	}
	
	else if(d>a && d>b && d>c && d>e)
	{
			return d; 
	}
	
	else if(e>a && e>b && e>c && e>d)
	{
			return e; 
	}
	
	
}
main()
{
	double firstjudge,secondjudge,thirdjudge,fourthjudge,fifthjudge;
	printf("First judge: ");
	firstjudge=getJudgedata();
	printf("Second judge: ");
	secondjudge=getJudgedata();
	printf("Third judge: ");
	thirdjudge=getJudgedata();
	printf("Fourth judge: ");
	fourthjudge=getJudgedata();
	printf("Fifth judge: ");
	fifthjudge=getJudgedata();
	
	calcScore(firstjudge,secondjudge,thirdjudge,fourthjudge,fifthjudge);
	
}
