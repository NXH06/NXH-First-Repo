#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display (int arr[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
}
void selection (int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
void insertion (int arr[], int size) {
    int i, j;
    for (i = 0; i <= size - 1; i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}
void bubble (int arr[], int size) {
    int swapped = 1;
    int sizeUnsorted = size;
    while (swapped == 1) {
        swapped = 0;
        for (int i = 1; i <= sizeUnsorted - 1; i++) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }
        sizeUnsorted--;
    }
}
int main() {
    // initialize array with 10 random values between 0 and 100
    int arr[10] = {0};
    int size = 10;
    srand(time(NULL)); // making sure the rand() is actually random by using a seed randomization function
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    display(arr, size);
    bubble(arr, size);
    display(arr, size);
    return 0;
}