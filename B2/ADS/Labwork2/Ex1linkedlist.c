#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// REMEMBER: FIRST DIGIT OF INTEGER IS sign digit
// Chosen implementation: Singly Linked List
typedef struct _Node {
    int data;
    struct _Node *pNext;
} Node;
typedef struct _List {
    int size;
    Node *pHead;
} List;
void initList (List *L) {
    L->size = 0;
    L->pHead = NULL;
}
Node *initNode (int newData) {
    Node *node = (Node*)malloc(sizeof(*node));
    node->data = newData;
    node->pNext = NULL;
    return node;
}
int length (List *L) {
    return L->size; // note: L->size INCLUDES sign digit!
}
int isEmpty (List *L) {
    return (length(L) == 0);
}
void displayList (List *L) {
    printf("\n");
    Node *current = L->pHead;
    if (current->data == 1)
    {
        printf("(+)");
    }
    else
    {
        printf("(-)");
    }
    current = current->pNext;
    while (current != NULL)
    {
        printf("%d",current->data);
        current = current->pNext;
    }
}
Node *traverse (List *L, int index) {
    if (isEmpty(L)) {
        printf("List is empty!");
        return NULL;
    }
    Node *current = L->pHead;
    for (int i = 1; i < index; i++) { // position of sign digit is 0, position of first actual digit is 1
        current = current->pNext;
    }
    return current;
}
void insertNodeFirst (Node *pNew, List *L) {
    if (isEmpty(L)) {
        L->size++;
        L->pHead = pNew;
    }
}
void insertNode (Node *pNew, Node *pPrev, List *L) {
    L->size++;
    pNew->pNext = pPrev->pNext;
    pPrev->pNext = pNew;
}
void removeNodeByValue (List *L, int val) {
    Node *p = L->pHead;
    if (p->data == val) {
        L->size--;
        L->pHead = p->pNext;
        free(p);
        return;
    }
    Node *q = p->pNext;
    int current = 1;
    while ((p->data != val) && current < length(L)) {
        q = p;
        p = p->pNext;
    }
    if (p != NULL) {
        L->size--;
        q->pNext = p->pNext;
        free(p);
    }
}
int sumDigits (List *L) {
    int sumDigits = 0;
    Node *current = L->pHead->pNext; // skip the sign digit
    while (current != NULL) {
        sumDigits += current->data;
        current = current->pNext;
    }
    return sumDigits;
}
int main() {
    List *L = (List*)malloc(sizeof(List));
    // memset(L, 0, sizeof(L));
    initList(L);
    int newData; // variable for inserting
    printf("> Input sign digit (1 for positive, -1 or otherwise for negative): ");
    scanf("%d", &newData);
    insertNodeFirst(initNode(newData), L);
    while (1) {
        printf("> Input digit (any negative number to stop): ");
        scanf("%d",&newData);
        if (newData >= 10) {
            printf("Not a digit!\n");
            continue;
        }
        else if (newData < 0) {
            printf("Number input process terminated!\n-----");
            break;
        }
        else {
            insertNode(initNode(newData), traverse(L, L->size), L);
        }
    }
    displayList(L);
    removeNodeByValue(L, 8);
    displayList(L);
    insertNode(initNode(0), (traverse(L, 4)), L);
    displayList(L);
    printf("\n>> The length of the integer (EXCLUDING sign digit) is: %d",length(L) - 1);
    printf("\n>> The sum of the digits (EXCLUDING sign digit) is: %d",sumDigits(L));
    return 0;
}