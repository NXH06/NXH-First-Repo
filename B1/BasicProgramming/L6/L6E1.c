#include<stdio.h>
int add(int*x,int*y)
{
   return *x+*y;
}
int main()
{
   int a,b;
   printf("a: ");
   scanf("%d",&a);
   printf("b: ");
   scanf("%d",&b);
   printf("Sum: %d\n",add(&a,&b));     // Sum of 2 variables using pointers
   return 0;
}