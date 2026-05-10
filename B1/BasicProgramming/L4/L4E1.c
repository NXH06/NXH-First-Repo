#include <stdio.h>
#include "gcd.h"
int main()
{
   int a,b;
   printf("input 2 numbers: \n");
   scanf("%d%d",&a,&b);
   int gcd=gcd_find(a,b);
   printf("the GCD is: %d",gcd);
   return 0;
}