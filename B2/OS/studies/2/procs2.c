#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t pid;
char *argv[2];
char cmd[50];

void doexec() {
    if (execvp(argv[0],argv) == -1)
        perror("execvp");
        exit(0);
}

int main() {
    printf("This is a special shell program!\nIt takes only the base command, no arguments. Sorry.\n");
    while (1) {
        printf("> ");
        scanf("%s", cmd);
        argv[0] = cmd;
        argv[1] = NULL; // so that the terminal knows where to stop parsing the argument
        switch (pid = fork()) { // switch-case statement on fork id directly
            case -1:
                perror("fork");
                break;
            case 0:
                doexec();
            default:
                if (waitpid(pid, NULL, 0) == -1) {
                    perror("waitpid");
                }
        }
    }
}
