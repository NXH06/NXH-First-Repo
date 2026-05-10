#include<stdio.h>
int main()
{
   int n;
   long product=1;
   printf("Put in a number N: \n");
   scanf("%d",&n);
   int temp=n;
   while (temp!=0)
   {
      product*=temp%10;
      temp/=10;
   }
   printf("The product of the number's digits is: %ld",product);
}