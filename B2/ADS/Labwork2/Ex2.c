#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// Chosen implementation: Doubly Linked List (since trains can only be added at the end)
typedef struct _Node {
    int amount;
    int capacity;
    char *id;
    struct _Node *pNext;
    struct _Node *pPrev;
} Node;
typedef struct _List {
    int size;
    Node *pHead;
    Node *pTail;
} List;
void initList (List *L) {
    L->size = 0;
    L->pHead = NULL;
    L->pTail = NULL;
}
Node *initNode (int newAmount, int newCapacity, char *newid) {
    Node *node = (Node*)malloc(sizeof(*node));
    node->amount = newAmount;
    node->capacity = newCapacity;
    node->id = newid;
    node->pNext = NULL;
    node->pPrev = NULL;
    return node;
}
int length (List *L) {
    return L->size;
}
int lengthByCounting (List *L) {
    Node *current = L->pHead;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->pNext;
    }
    return count;
}
int isEmpty (List *L) {
    return (length(L) == 0);
}
void displayList (List *L) {
    printf("\n-----\n");
    Node *current = L->pHead;
    int count = 1;
    while (current != NULL)
    {
        printf("Car %d (ID: %s) - %d/%d passengers\n", count, current->id, current->amount, current->capacity);
        current = current->pNext;
        count++;
    }
    printf(">> Length of train: %d\n-----\n", L->size);
}
Node *traverse (List *L, int index) {
    if (isEmpty(L)) {
        printf("List is empty!");
        return NULL;
    }
    Node *current = NULL;
    if (index >= 0) { // traverse forward from head (index 0)
        current = L->pHead;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
    }
    else { // negative index - traverse backward from tail (index -1)
        current = L->pTail;
        for (int i = -1; i > index; i--) {
            current = current->pPrev;
        }
    }
    return current;
}
void insertNodeFirst (Node *pNew, List *L) {
    if (pNew->amount > pNew->capacity) {
        printf("Car exceeds capacity!\n");
        return;
    }
    if (isEmpty(L)) {
        L->size++;
        L->pHead = pNew;
        L->pTail = pNew;
    }
}
void insertNode (Node *pNew, int index, List *L) { // pass in an index, then init pNext & pPrev by traversing to index
    if (pNew->amount > pNew->capacity) {
        printf("Car exceeds capacity!\n");
        return;
    }
    if (index > L->size || -index > L->size) {
        printf("Invalid index!\n");
        return;
    }
    if (index == 0 || -index == L->size + 1) { // +1 because negative index starts from -1
        printf("Insert car at head...");
        Node *oldNext = L->pHead;
        pNew->pNext = oldNext;
        oldNext->pPrev = pNew;
        L->pHead = pNew;
    }
    else if (index == -1 || index == L->size) {
        printf("Insert car at tail...");
        Node *oldPrev = L->pTail;
        pNew->pPrev = oldPrev;
        oldPrev->pNext = pNew;
        L->pTail = pNew;
    }
    else {
        printf("Insert car at position %d...",index);
        Node *oldPrev = traverse(L, index - 1);
        Node *oldNext = traverse(L, index);
        pNew->pNext = oldNext;
        pNew->pPrev = oldPrev;
        oldPrev->pNext = pNew;
        oldNext->pPrev = pNew;
    }
    L->size++;
}
void removeNodeIfEmpty (List *L) {
    Node *p = L->pHead;
    if (p->amount == 0) {
        printf("Remove empty car...");
        L->size--;
        L->pHead = p->pNext;
        p->pNext->pPrev = NULL;
        free(p);
        return;
    }
    int current = 0;
    while ((p->amount != 0) && current < length(L)) {
        p = p->pNext;
        current++;
    }
    if (p != NULL) {
        printf("Remove empty car...");
        L->size--;
        p->pPrev->pNext = p->pNext;
        if (current == length(L)) {
            L->pTail = p->pPrev;
        }
        else {
            p->pNext->pPrev = p->pPrev;
        }
        free(p);
    }
}
void removeNode (Node *p, List *L) {
    L->size--;
    if (p->pPrev == NULL) {
        L->pHead = p->pNext;
    }
    else {
        p->pPrev->pNext = p->pNext;
    }
    if (p->pNext == NULL) {
        L->pTail = p->pPrev;
    }
    else {
        p->pNext->pPrev = p->pPrev;
    }
    free(p);
}
int main() {
    List *L = (List*)malloc(sizeof(List));
    // memset(L, 0, sizeof(L));
    initList(L);
    int newAmount, newCapacity, newid; // variables for inserting
    insertNodeFirst(initNode(11, 20, "C01"), L);
    displayList(L);
    insertNode(initNode(12, 20, "C02"), -1, L);
    displayList(L);
    insertNode(initNode(0, 20, "C03"), -1, L);
    displayList(L);
    insertNode(initNode(14, 20, "C04"), 0, L);
    displayList(L);
    insertNode(initNode(21, 20, "TOOFULL"), 0, L);
    removeNodeIfEmpty(L);
    displayList(L);
    insertNode(initNode(19, 20, "A99"), 2, L);
    displayList(L);
    insertNode(initNode(18, 20, "BADINDEX"), 5, L);
    return 0;
}