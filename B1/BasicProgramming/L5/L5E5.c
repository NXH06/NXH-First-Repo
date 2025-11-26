#include<stdio.h>
int main()
{
    int n;
    printf("Enter matrix size (n): ");
    scanf("%d",&n);
    int arr[n][n];
    int sum=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("Enter matrix element (%d,%d): ",i+1,j+1);
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
    }
    printf("Sum of all matrix elements: %d\n",sum);
    printf("Transposed matrix: \n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
}