#include <stdio.h>
#include <stdlib.h>
// REMEMBER: FIRST DIGIT OF INTEGER IS SIGN BIT
struct _List {
    int size;
    int capacity;
    int *val;
};
typedef struct _List List;
void init (List *L, int capacity) {
    L->size = 0;
    L->capacity = capacity;
    L->val = (int*)malloc(L->capacity);
}
int length (List *L) {
    return L->size;
}
int display (List *L) {
    printf("\n");
    if (L->val[0]==1)
    {
        printf("(+1)");
    }
    else
    {
        printf("(-1)");
    }
    for (int i=1; i<length(L); i++)
    {
        printf("%d",L->val[i]);
    }
}
void addDigit (List *L, int index, int val_insert) {
    if (length(L)==L->capacity)
    {
        printf("List is full!");
        return;
    }
    else if (index < 0 || index > length (L))
    {
        printf("Invalid index!");
        return;
    }
    else
    {
        for (int i=length(L); i>index; i--)
        {
            L->val[i] = L->val[i-1];
        }
        L->val[index] = val_insert;
        L->size+=1;
    }
}
void removeDigit (List *L, int index) {
    if (length(L)==0)
    {
        printf("List is empty!");
        return;
    }
    else if (index < 0 || index > length (L))
    {
        printf("Lnvalid index!");
        return;
    }
    else
    {
        for (int i=index-1; i<length(L); i++)
        {
            L->val[i] = L->val[i+1];
        }
        L->size-=1;
    }
}
int sumDigits (List *L) {
    int sumDigits=0;
    for (int i=1; i<length(L); i++)
    {
        sumDigits+=L->val[i];
    }
    return sumDigits;
}
int main() {
    List *L = (List*)malloc(sizeof(List));
    init (L,1000);
    printf("Enter amount of digits (including sign digit): ");
    scanf("%d",&L->size);
    printf("Enter sign digit: ");
    scanf("%d", &L->val[0]);
    for (int i=1; i<L->size; i++)
    {
        printf("Enter digit: ");
        scanf("%d",&L->val[i]);
    }
    display(L);
    addDigit(L,4,0);
    display(L);
    removeDigit(L,7);
    removeDigit(L,7);
    removeDigit(L,7);
    display(L);
    printf("\nThe length of the integer is: %d",length(L));
    printf("\nThe sum of the digits is: %d",sumDigits(L));
    return 0;
}