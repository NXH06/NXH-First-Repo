#include <stdio.h>
#include <stdlib.h>

void myexit() {
    printf("\nGoodbye world\n\n");
}

int main() {
    printf("Hello world\n");
    atexit(myexit) ;
    printf("Just before exiting...\n");
    return 0;
}