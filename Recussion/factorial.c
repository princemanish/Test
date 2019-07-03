#include<stdio.h>
#include<stdlib.h>

int factorial(int n)
{
   int ret;
   if(n == 1)
   {
    return 1;
   }
   else
   {
    return (ret= n * factorial(n-1));
   }
}
int main()
{
   int nu, fact;
   printf("Enter the number greater then or equal to 1 \n");
   scanf("%d", &nu);
   printf("number is %d\n",nu);
   printf("The value of factorial is %d\n",factorial(nu));
return 0;
}
