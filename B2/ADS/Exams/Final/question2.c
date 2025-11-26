#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int frequency;
} Element;
typedef struct {
    int size;
    Element data[100];
} List;
List *init () {
    List *list = (List*)malloc(sizeof(List));
    list->size = 0;
    return list;
}
Element initElement (int val, int freq) {
    Element element;
    element.value = val;
    element.frequency = freq;
    return element;
}
int isEmpty (List *list) {
    return (list->size == 0);
}
void display (List *list) {
    printf("\nList size: %d", list->size);
    printf("\n");
    for (int i = 0; i <= list->size - 1; i++) {
        printf("Value: %d | Frequency: %d\n", list->data[i].value, list->data[i].frequency);
    }
}
void add (List *list, int val, int freq) {
    for (int i = 0; i <= list->size - 1; i++) {
        if (list->data[i].value == val) {
            printf("\nValue already exists. Increasing frequency of existing element instead...");
            list->data[i].frequency += freq;
            return;
        }
    }
    list->data[list->size] = initElement (val, freq);
    (list->size)++;
}
void delete (List *list, int val) {
    int i = 0;
    while (i <= list->size - 1) {
        if (list->data[i].value == val) {
            printf("\nDeleting element...");
            for (int j = i; j <= list->size - 1; j++) {
                list->data[j].value = list->data[j + 1].value;
                list->data[j].frequency = list->data[j + 1].frequency;
            }
            (list->size)--;
            return;
        }
        i++;
    }
    printf("\nNo such element.");
}
int main() {
    List *list = init();
    int tempSize;
    int tempVal, tempFreq; 
    printf("Enter amount of elements to add: ");
    scanf("%d", &tempSize);
    printf("Generating list...");
    for (int i = 0; i <= tempSize - 1; i++) {
        add(list, i, 5); // add elements with incrementing positive integer values and freqency of 5
    }
    display(list);
    // Attemping to add already existing values
    add(list, 1, 5);
    add(list, 2, 5);
    add(list, 3, 5);
    display(list);
    delete(list, 8);
    display(list);
    return 0;
}