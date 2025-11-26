#include<stdio.h>
int main()
{
   int n;
   float sum=0;
   printf("Put in a number N: \n");
   scanf("%d",&n);
   for (int i=1; i<=n; i++)
   {
      sum+=(float)1/i;
   }
   printf("The harmonics series is: %f",sum);
}