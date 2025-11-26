#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Input 3 numbers: \n");
    scanf("%d%d%d",&a,&b,&c);
    if (a>=b && a>=c)
    {
        printf("Max: %d",a);
        if (b>c)
        {printf("Min: %d",c);}
        else
        {printf("Min: %d",b);}
    }
    else
    {printf("Min: %d",a);}
return 0;
}