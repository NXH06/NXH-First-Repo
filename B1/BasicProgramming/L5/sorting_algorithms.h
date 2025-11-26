#include<stdio.h>
void arrayprint (float arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%.2f ",arr[i]);
    }
    printf("\n");
}
void selection_sort(float arr[],int n)
{
    int i, j, pos;
    float temp;
    for (i=0;i<n;i++)
    {
        pos=i;
        for (j=i+1;j<n;j++) {
            if (arr[j]<arr[pos])
            {pos=j;}
        }
        if (pos!=i) {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
        arrayprint(arr, n);
    }
    
}
void insertion_sort (float arr[], int n) 
{
    int i, j;
    float temp;
    for (i = 1; i<n; i++) 
    {
        temp = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>temp) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp ;
        arrayprint(arr, n);
    }
}
void bubble_sort (float arr[], int n) 
{
    int i, j;
    float temp ;
    for (i = 0; i<n-1; i++) 
    {
        for (j = 0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        arrayprint(arr, n);
    }
}
