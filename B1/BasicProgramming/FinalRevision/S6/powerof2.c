#include<stdio.h>
int main()
{
    float n; 
    printf("enter number: ");
    scanf("%f",&n);
    while (n>1)
    {
        n/=2;
    }
    printf("new value: %f\n",n);
    if (n==1)
    {printf("n is a power of 2");}
    else
    {printf("nope!");}
    return 0;
}