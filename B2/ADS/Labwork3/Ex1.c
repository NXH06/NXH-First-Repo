#include <stdio.h>
#include <stdlib.h>
typedef struct _Item {
    char *name;
    int price;
    int quantity;
} Item;
typedef struct _Customer {
    Item *item;
    int quantityToPurchase;
    struct _Customer *pNext;
} Customer;
typedef struct _Queue {
    Customer *pFront;
    Customer *pBack;
    int size;
} Queue;
Queue *initQueue () {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->pFront = NULL;
    q->pBack = NULL;
    q->size = 0;
    return q;
}
Item *initItem (char *name, int price, int quantity) {
    Item *item = (Item*)malloc(sizeof(Item));
    item->name = name;
    item->price = price;
    item->quantity = quantity;
    return item;
}
Customer *initCustomer (Item *item, int quantityToPurchase) {
    Customer *cus = (Customer*)malloc(sizeof(Customer));
    cus->item = item;
    cus->quantityToPurchase = quantityToPurchase;
    cus->pNext = NULL;
    return cus;
}
int length (Queue *q) {
    return (q->pBack - q->pFront);
}
int isEmpty (Queue *q) {
    return (q->pBack == NULL);
}
void displayItem (Item item) {
    printf("\n%s ($%d): %d in stock",item.name, item.price, item.quantity);
}
void purchaseItem (Item *item, int quantityPurchased) {
    if (quantityPurchased > item->quantity) {
        printf("\nNot enough items in stock! Purchase of %s (x%d) failed.", item->name, quantityPurchased);
        return;
    }
    printf("\nPurchase of %s (x%d) successful.", item->name, quantityPurchased);
    item->quantity -= quantityPurchased;
}
void enqueue (Queue *q, Customer *newCus) {
    if (isEmpty(q)) {
        q->pFront = newCus;
        q->pBack = newCus;
    }
    else {
        newCus->pNext = q->pBack;
        q->pBack = newCus;
    }
    q->size++;
}
Customer *dequeue (Queue *q) { // remove customer from front of queue, THEN return the dequeued customer
    if (isEmpty(q)) {
        printf("Queue is empty!");
        return NULL;
    }
    Customer *dequeued = q->pFront;
    if (q->size == 1) {
        q->pFront = NULL;
        q->pBack = NULL;
    }
    else {
        Customer *current = q->pBack;
        while (current->pNext != q->pFront){
            current = current->pNext;
        }
        q->pFront = current;
        q->pFront->pNext = NULL;
    }
    q->size--;
    return dequeued;
}
int main() {
    Queue *q = initQueue();
    Item *item1 = initItem("Laptop", 500, 10);
    Item *item2 = initItem("Headphones", 100, 10);
    Item *item3 = initItem("Smartphone", 200, 10);
    enqueue(q, initCustomer(item1, 4));
    enqueue(q, initCustomer(item2, 10));
    enqueue(q, initCustomer(item3, 12));
    enqueue(q, initCustomer(item3, 9));
    enqueue(q, initCustomer(item1, 8));
    enqueue(q, initCustomer(item1, 6));
    while (!isEmpty(q)) {
        Customer *currentCus = dequeue(q);
        Item *currentItem = currentCus->item;
        displayItem(*currentItem);
        purchaseItem(currentItem, currentCus->quantityToPurchase);
    }
    printf("\n>> Queue emptied.");
    return 0;
}