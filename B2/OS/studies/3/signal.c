#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) { // handler
    printf("\n[Signal received: %d]\n", signum);
    switch(signum) {
        case SIGTSTP: // keyboard stop (not SIGSTOP, which is unstoppable)
            printf("Pause for 3 seconds!\n");
            sleep(3);
            break;
        case SIGINT: // cascade to case SIGTERM
        case SIGSTOP:
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
    // set handlers
    signal(SIGTSTP, handler);
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1) {
        printf("Normal behavior.\n");
        sleep(1);
    }
    return 0;
}