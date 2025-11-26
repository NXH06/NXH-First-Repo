#include<stdio.h>
int main()
{
    int n=64;
    int* p=&n;
    int** p2=&p;
    printf("%d\n%d\n%d\n%d\n%d\n",n,p,p2,*p2,*p);
    int arr[]={1,2,3,4,5,11,22,33,44,55};
    int* ptr=arr;
    printf("array element no. 8: %d",ptr[7]);
}