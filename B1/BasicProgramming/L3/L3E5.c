#include<stdio.h>
int main()
{
   int n;
   printf("input: \n");
   scanf("%d",&n);
   int temp1=1, temp2=1, temp3;
   int sum=temp1+temp2;
   for (int i=3; i<=n; i++)
   {
      temp3=temp1+temp2;
      sum+=temp3;
      temp1=temp2, temp2=temp3;
   }
   printf("sum: %d",sum);
}