#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    int pid;
    for (int i = 0; i < 3; i++) {
        pid = fork();
        switch (pid){
        case -1: // error
            printf("Error!\n");
            break; // don't forget that switch-case cascades down the cases...
        case 0: // child
            printf("Freshly forked.\n");
            break;
        default: // parent: returns child's pid
            printf("\tFork ID: %d\n", pid);
            if (i == 0) { // original/root process
                sleep(1); // so that it terminates last
            }
            break;
        }
    }
}
// 7 IDs printed, or 7 forks created. Combined with the original process, that's 8 (or 2^3)