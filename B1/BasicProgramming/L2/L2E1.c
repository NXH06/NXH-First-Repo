#include<stdio.h>
int main()
{
    float far, cel;
    printf("Input Celsius value: ");
    scanf("%f",&cel);
    far=cel*1.8+32;
    printf("The equivalent Farenheit value is: %.3f", far);
    return 0;
}