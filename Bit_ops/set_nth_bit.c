#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
unsigned int n,nu;
printf("Enter the number whose nth bit to be set\n");
scanf("%d",&nu);
printf("Number entered is %d\n",nu);
printf("Enter nth bit to be set\n");
scanf("%d",&n);
printf("Number entered is %d\n",n);

nu=nu | (1 << (n));
printf("Number after bit set is %d\n",nu);

return 0;
}
