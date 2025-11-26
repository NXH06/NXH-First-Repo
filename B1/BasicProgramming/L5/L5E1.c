#include<stdio.h>
int main()
{
   int n=10;
   int a[10]={4,2,6,5,8,6,7,4,12,10};
   int min,max,i;
   min=max=a[0];
   for(int i=1;i<n;i++)
   {
      if (a[i]>max)
      {max=a[i];}       // find max
      if (a[i]<min)
      {min=a[i];}       // find min
   }
   printf("the max and min of the list is: %d and %d",max,min);
   return(0);
}