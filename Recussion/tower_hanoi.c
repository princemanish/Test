#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void tower_hanoi(int n1, char src1,char intr1, char dst1)
{
  if(n1==1)
  { 
   printf("Move from src to dst %c ->  %c \n", src1,dst1);
  }
  else
  {
  tower_hanoi(n1-1,src1,dst1,intr1);
  tower_hanoi(1,src1,intr1,dst1);
  tower_hanoi(n1-1,intr1,src1,dst1);
  }
}



int main()
{
int n;
char src='A';
char intr='B';
char dst='C';
printf("Enter the value of n\n");
scanf("%d",&n);
printf("The value of n is %d\n",n);
tower_hanoi(n,src,intr,dst);
return 0;
}
