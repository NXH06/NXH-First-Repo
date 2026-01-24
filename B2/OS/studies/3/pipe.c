#include <stdio.h>
#include <unistd.h>

// ps -ef | grep firefox
int main() {
    int p[2];
    if (pipe(p) == -1) {
        perror("pipe");
        exit(1);
    }
    int pid = fork();
    if (pid == 0) { // child
        char* cmd[] = {"ps", "-ef", NULL};
        dup2(p[1], 1);
        close(p[0]); close(p[1]);
        execvp(cmd[0], cmd);
    }
    else { // parent
        char* cmd[] = {"grep", "-i", "firefox", NULL};
        dup2(p[0], 0);
        close(p[0]); close(p[1]);
        // no need to wait for child to finish writing, since pipe buffers data between 2 processes anyway
        execvp(cmd[0], cmd);
    }
    return 0;
}