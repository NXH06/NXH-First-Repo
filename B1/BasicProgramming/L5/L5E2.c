#include <stdio.h>
#include "L5_functions.h"
int main()
{
   int n;
   printf("Enter a number: ");
   scanf("%d",&n);
   printf("The sum of even and odd numbers up to this number are: %d, %d",sumevenodd(n,0),sumevenodd(n,1));
   return 0;
}