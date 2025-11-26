#include<stdio.h>
#include<math.h>
#include"sorting_algorithms.h"
int main()
{
    float arr[]={7, 5, -8, 29, 0, sqrt(2),-cbrt(4)};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("> Array before sorting: ");
    arrayprint(arr, n);
    int sortalg;
    printf("Choose sorting algorithm: (1 for selection sort, 2 for insertion sort, 3 for bubble sort) ");
    scanf("%d",&sortalg);
    switch (sortalg)
    {
        case 1: printf("Commencing selection sort...\n"); selection_sort(arr,n); break;
        case 2: printf("Commencing insertion sort...\n"); insertion_sort(arr,n); break;
        case 3: printf("Commencing bubble sort...\n"); bubble_sort(arr,n); break;
        default: printf("Not a valid option. Please restart the program."); goto end;
    }
    
    printf("Sorting finished!\n> Array after sorting: ");
    arrayprint(arr, n);
    end:
    return 0;
}
