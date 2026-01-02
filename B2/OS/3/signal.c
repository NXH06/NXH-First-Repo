#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("\n[Signal received: %d]\n", sig);
    switch(sig) {
        case SIGTSTP:
            printf("Pause for 3 seconds!\n");
            sleep(3);
            break;
        case SIGINT:
        case SIGTERM:
            printf("\tProgram terminated.\n");
            exit(0);
            break;
        default:
            printf("Unhandled signal...\n");
            break;
    }
}
int main() {
    signal(SIGTSTP, handler);
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1) {
        printf("Normal behavior.\n");
        sleep(1);
    }
    return 0;
}