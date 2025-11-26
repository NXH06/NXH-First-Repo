#include<stdio.h>
void swap(int*x,int*y)
{
   int temp = *x;
   *x=*y;
   *y=temp;
}
int main()
{
   int a,b;
   printf("a: "); scanf("%d",&a);
   printf("b: "); scanf("%d",&b);
   swap(&a,&b);
   printf("Swapped: %d and %d\n",a,b);     // Swapping 2 variables using pointers
   return 0;
}