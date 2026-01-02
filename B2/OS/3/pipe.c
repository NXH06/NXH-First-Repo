#include <stdio.h>
#include <unistd.h>
// ps -ef | grep firefox
int main() {
    int pfd[2];
    pipe(pfd);

    int pid = fork();
    if (pid == 0) { // child
        char* cmd[] = {"ps", "-ef", NULL};
        dup2(pfd[1], 1);
        close(pfd[0]); close(pfd[1]);
        execvp(cmd[0], cmd);
    }
    else {
        char* cmd[] = {"grep", "NetworkManager", NULL};
        dup2(pfd[0], 0);
        close(pfd[1]); close(pfd[0]);
        execvp(cmd[0], cmd);
    }
    return 0;
}