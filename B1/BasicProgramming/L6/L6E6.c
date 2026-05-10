#include<stdio.h>
#include<stdlib.h>
void swap(int* x, int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    void (*function) (int*, int*);
    function=swap;
    int x=15; int y=20;
    printf("\nbefore swap: %d, %d",x,y);
    (*function)(&x,&y);
    printf("\nafter swap: %d, %d",x,y);
    return (0);
}