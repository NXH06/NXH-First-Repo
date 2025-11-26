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
void merge (int arr[], int left, int mid, int right) { // merge 2 subarrays of arr[]: arr[left...mid] & arr [mid+1...right]
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int L[size1], R[size2]; // initialize temp arrays
    int i, j, k; // initialize indexes for for and while loops
    // Copy the subarrays into the temp arrays
    for (i = 0; i < size1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < size2; j++) {
        R[j] = arr [mid + 1 + j];
    }
    i = 0; j = 0; k = left;
    // Merge subarrays by writing elements of temp arrays into arr[]
    while (i < size1 && j < size2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of either subarray (if there are still any)
    while (i < size1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < size2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[j]);
    return i;
}
// int partitionHoare (int arr[], int low, int high) {}
void quickSort (int arr[], int low, int high) {
    if (low < high) {
        int pivotPos = partition (arr, low, high);
        quickSort (arr, low, pivotPos - 1);
        quickSort (arr, pivotPos + 1, high);
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
    quickSort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}