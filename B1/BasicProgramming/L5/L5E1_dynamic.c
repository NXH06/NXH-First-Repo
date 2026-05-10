#include<stdio.h>
int main()
{
   int a[1000],i,n;
   int min,max;
   printf("Enter size of array: ");
   scanf("%d",&n);
   printf("Enter elements of array: ");
   for (i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
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