#include <stdio.h>
#include <stdlib.h>
// I. Implementation with array
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void displayArr (int arr[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
}
void selectionSortIter (int arr[], int size) {
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
void selectionSortRecur (int arr[], int size, int i) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    swap(&arr[min], &arr[i]);
    if (i < size - 1) {
        selectionSortRecur(arr, size, i + 1);
    }
}
int mainArr() { // This is unused.
    int arr[] = {5, 1, 3, 2, 6, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    displayArr(arr, 6);
    selectionSortIter(arr, size);
    displayArr(arr, 6);
    return 0;
}
// II. Implementation with Data Structure
typedef struct _List {
    int *element;
    int size;
} List;
// Array-based List is used instead of Stack or Heap,
// since the sorting algorithm doesn't follow the FILO or FIFO principles
List *initList (int tempArr[], int size) {
    List *list = (List*)malloc(sizeof(List));
    list->size = size;
    list->element = (int*)malloc(list->size * sizeof(int));
    for (int i = 0; i < size; i++) {
        list->element[i] = tempArr[i];
    }
    return list;
}
void displayList (List list) {
    printf("\n");
    for (int i = 0; i < list.size; i++) {
        printf("%d ",list.element[i]);
    }
}
void selectionSortIterList (List *list) {
    for (int i = 0; i < list->size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < list->size; j++) {
            if (list->element[j] < list->element[min]) {
                min = j;
            }
        }
        swap(&list->element[min], &list->element[i]);
    }
}
int main()
{
    int temp[] = {5, 1, 3, 2, 6, 4};
    int size = sizeof(temp)/sizeof(temp[0]);
    List *list = initList(temp, size);
    displayList(*list);
    selectionSortIterList(list);
    displayList(*list);
    return 0;
}
