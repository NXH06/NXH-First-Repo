#include<stdio.h>
int main()
{
	int a=20,b=50;
	printf("before swap: a=%d, b=%d",a,b);
	a=b-a;
	b=b-a;
	a=a+b;
	printf("\nafter swap: a=%d, b=%d",a,b);
}