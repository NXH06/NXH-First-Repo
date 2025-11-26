#include <stdio.h>
int main()
{
    unsigned int a=5, b=9;
    printf("%u\n%u\n%u\n%u\n",a&b,a|b,a^b,~a);
    return 0;
}