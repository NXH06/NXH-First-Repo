#include<stdio.h>
int main()
{
   int *p;
   int arr[]={6,4,-2,-5,3,5,-5,-6,9};
   int n;
   n=sizeof(arr)/sizeof(arr[0]);
   printf("Size of array is: %d\n",n);
   p=&arr[0];
   for (int i=0;i<n;i++)
   {
      printf("Element [%d]: value %d, address %p\n",i,*p,p);
      p+=1;
   }
   return 0;
}