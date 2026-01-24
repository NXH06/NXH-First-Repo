#include <stdio.h>
#include <unistd.h>

int main() {
    int p[2];
    pipe(p);
    int pid = fork();
    if (pid == 0) { // child
        char* cmd[] = {"./gendoc", NULL};
        dup2(p[1], 1);
        close(p[0]); close(p[1]);
        execvp(cmd[0], cmd);
    }
    else { // parent
        char* cmd[] = {"./print", NULL};
        dup2(p[0], 0);
        close(p[0]); close(p[1]);
        execvp(cmd[0], cmd);
    }
    return 0;
}