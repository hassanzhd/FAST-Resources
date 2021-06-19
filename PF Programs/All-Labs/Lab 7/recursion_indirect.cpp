#include<stdio.h>
int func1(int);
int func2(int);
int func1(int n)
{
if (n<=1)
	return 1;
else
	return func2(n);
}
int func2(int n)
{
	return n*func1(n-1);
}
int main()
{
	int f = func1(5);
	printf("%d",f);
}
