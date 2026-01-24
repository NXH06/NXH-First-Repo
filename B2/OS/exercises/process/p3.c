#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("This program recreates a 2-pipe command: ps -ef | grep <process_name> | wc -l\n> Enter process name: ");
    char process_name[30];
    scanf("%s", process_name);
    int pipe1[2];
    int pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }
    // The 2 pipes will be performed by 3 children processes (no parent)
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork1");
        exit(1);
    }
    else if (pid1 == 0) {
        close(pipe1[0]); // pipe1 not read from
        close(pipe2[0]); close(pipe2[1]); // pipe2 not used at all
        char* cmd[] = {"ps", "-ef", NULL};
        if (dup2(pipe1[1], 1) == -1) {
            perror("dup2 for write in p1");
            exit(1);
        }
        close(pipe1[1]);
        execvp(cmd[0], cmd);
        // perror only reached if execvp fails
        perror("execvp for ps");
        exit(1);
    }
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork2");
        exit(1);
    }
    else if (pid2 == 0) {
        close(pipe1[1]); // pipe1 not written to
        close(pipe2[0]); // pipe2 not read from
        char* cmd[] = {"grep", process_name, NULL};
        if (dup2(pipe1[0], 0) == -1) {
            perror("dup2 for read in p1");
            exit(1);
        }
        if (dup2(pipe2[1], 1) == -1) {
            perror("dup2 for write in p2");
            exit(1);
        }
        close(pipe1[0]); close(pipe2[1]);
        execvp(cmd[0], cmd);
        perror("execvp for grep");
        exit(1);
    }
    pid_t pid3 = fork();
    if (pid3 == -1) {
        perror("fork3");
        exit(1);
    }
    else if (pid3 == 0) {
        close(pipe1[0]); close(pipe1[1]); // pipe1 not used at all
        close(pipe2[1]); // pipe2 not written to
        char* cmd[] = {"wc", "-l", NULL};
        if (dup2(pipe2[0], 0) == -1) {
            perror("dup2 for read in p2");
            exit(1);
        }
        close(pipe2[0]);
        execvp(cmd[0], cmd);
        perror("execvp for wc");
        exit(1);
    }
    // close all pipes
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    // wait for child processes
    int status1, status2, status3;
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    waitpid(pid3, &status3, 0);
    // WIFEXITED: returns True if child process exited normally
    if (WIFEXITED(status1) && WIFEXITED(status2) && WIFEXITED(status3)) {
        printf("\nAll processes completed successfully.\n");
        exit(0);
    }
    else {
        printf("\nOne or more child processes failed\n");
        exit(1);
    }
}
