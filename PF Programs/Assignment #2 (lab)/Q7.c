#include <stdio.h>
int greatest_common(int number1, int number2)
{
    if (number2 != 0)
       return greatest_common(number2, number1%number2);
    else 
       return number1;

}
int main()	
{
   int number1, number2;
   printf("Enter two positive integers: ");
   scanf("%d %d", &number1, &number2);

   printf("G.C.D of %d and %d is %d.", number1, number2, greatest_common(number1,number2));

}


