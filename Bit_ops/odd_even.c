#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
int n;
printf("Enter the number to be checked\n");
scanf("%d",&n);
printf("Number entered is %d\n",n);
if(n & 1 << 0)
printf("The given number is odd\n");
else
printf("The given number is even\n");
return 0;
}
