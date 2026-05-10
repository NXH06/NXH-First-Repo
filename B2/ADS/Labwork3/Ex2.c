#include <stdio.h>
#include <stdlib.h>
typedef struct _Site {
    char *title;
    char *url;
} Site;
typedef struct _Stack {
    int top;
    int capacity;
    Site **site; // double pointer: pointer to an array of Site* pointers
} Stack;
void initStack (Stack *st, int n) {
    st->top = -1;
    st->capacity = n;
    st->site = (Site**)malloc(st->capacity);
}
Site *initSite (char *title, char *url) {
    Site *site = (Site*)malloc(sizeof(Site));
    site->title = title;
    site->url = url;
    return site;
}
int size (Stack *st) {
    return st->top + 1;
}
int isEmpty (Stack *st) {
    return (st->top < 0);
}
int isFull (Stack *st) {
    return (st->top == st->capacity - 1);
}
void displayList (Site *currentSite, Stack *backw, Stack *forw) {
    printf("\n-----");
    for (int i = 0; i <= backw->top; i++) {
        printf("\n%s (%s)", backw->site[i]->title, backw->site[i]->url);
    }
    printf("\n%s (%s) ----> [YOU ARE HERE] ",currentSite->title, currentSite->url);
    for (int i = forw->top; i >= 0; i--) {
        printf("\n%s (%s)", forw->site[i]->title, forw->site[i]->url);
    }
    printf("\n>> Backward: %d, Forward: %d", size(backw), size(forw));
    printf("\n-----\n");
}
void push(Stack *st, Site *currentSite) {
    if (isFull(st)) {
        printf(">> Stack is full!");
        return;
    }
    else {
        st->top++;
        st->site[st->top] = currentSite;
    }
}
void pop(Stack *st) {
    if (isEmpty(st)) {
        printf(">> Stack is empty!");
        return;
    }
    else {
        st->top--;
    }
}
void goBackward (Site **currentSite, Stack *backw, Stack *forw) { // double pointer needed to actually change value of current in main()
    if (isEmpty(backw)) {
        printf(">> Backward stack empty!");
        return;
    }
    push(forw, *currentSite);
    *currentSite = backw->site[backw->top];
    pop(backw);
}
void goForward (Site **currentSite, Stack *backw, Stack *forw) { // same as goBackward
    if (isEmpty(forw)) {
        printf(">> Forward stack empty!");
        return;
    }
    push(backw, *currentSite);
    *currentSite = forw->site[forw->top];
    pop(forw);
}
int main()
{
    Stack *forward = (Stack*)malloc(sizeof(Stack));
    Stack *backward = (Stack*)malloc(sizeof(Stack));
    initStack(forward, 100);
    initStack(backward, 100);
    int choice = 0;
    push(backward, initSite("Wikipedia","wikipedia.com"));
    push(backward, initSite("Facebook", "facebook.com"));
    push(backward, initSite("Spotify", "open.spotify.com"));
    Site *current = initSite("Minecraft","minecraft.net");
    push(forward, initSite("Moodle USTH","moodle.usth.edu.vn"));
    push(forward, initSite("YouTube","youtube.com"));
    displayList(current, backward, forward);
    while (1) {
        printf("\n> Enter 1 to go backward, 2 to go forward, 0 to quit: ");
        scanf("%d",&choice);
        switch (choice) {
            default:
                goto endProgram;
            case 1:
                goBackward(&current, backward, forward);
                displayList(current, backward, forward);
                break;
            case 2:
                goForward(&current, backward, forward);
                displayList(current, backward, forward);
                break;
        }
    }
    endProgram:
    printf("=== Program terminated ===");
    return 0;
}