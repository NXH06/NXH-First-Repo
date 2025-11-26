#include <stdio.h>
#include "gcd.h"
int main()
{
   int a,b,c,d,gcd1,gcd2;
   printf("input 4 numbers: \n");
   scanf("%d%d%d%d",&a,&b,&c,&d);
   gcd1=gcd_find(a,b);
   gcd2=gcd_find(c,d);
   int gcd=gcd_find(gcd1,gcd2);
   printf("the GCD is: %d",gcd);
   return 0;
}