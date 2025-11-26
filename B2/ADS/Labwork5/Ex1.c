#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void flip (int arr[], int size) {
    for (int i = 0; i <= (size / 2) - 1; i++) {
        swap (&arr[i], &arr[size - 1 - i]);
    }
}
int findMaxIndex (int arr[], int size) {
    int maxIndex = 0;
    int max = arr[maxIndex];
    for (int i = 1; i <= size - 1; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
void sort (int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int maxIndex = findMaxIndex (arr, size);
    flip (arr, maxIndex + 1);
    display(arr, 10);
    flip (arr, size);
    display(arr, 10);
    sort (arr, size - 1);
}
// First flip of sort(): runs a maximum of n/2 times
// Second flip of sort(): always run n/2 times
// sort() always get called n - 1 times
// Therefore, time complexity is O(n^2) in all cases
int main() {
    // initialize array with 10 random values between 0 and 100
    int arr[10] = {0};
    int size = 10;
    srand(time(NULL)); // making sure the rand() is actually random by using a seed randomization function
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    display(arr, size);
    sort(arr, size);
    display(arr, size);
    return 0;
}