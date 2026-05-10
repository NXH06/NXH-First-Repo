#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* arr=(int*)malloc(5*sizeof(int));
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int size=0;
    for (int i=1;i<=n;i++)
    {
        printf("Enter element [%d]:",i);
        scanf("%d",&arr[i-1]);
    }
    printf("Array complete.\n");
    for (int i=1;i<=n;i++)
    {printf("Element %d: %d\n",i,arr[i-1]);}
    free(arr);
    return 0;
}