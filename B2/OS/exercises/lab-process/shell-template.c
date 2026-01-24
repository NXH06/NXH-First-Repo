#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "readcmd.h"
// compile command: gcc shell-template.c readcmd.c -o myshell
void trace_cmd(char ***cmd) {
    int i, j;
    /* Display each command of the pipe */
    /* cmd is a table of table of strings, each table ends with a NULL element */
    printf("\ttrace_cmd:\n");
    for (i = 0; cmd[i] != 0; i++) {
        char **cmdi = cmd[i];
        printf("\tcmd[%d]: ", i);
        for (j = 0; cmdi[j] != 0; j++) {
            printf("(%s) ", cmdi[j]);
        }
        printf("\n");
    }
}
int execute_command(char **argv) { // for executing a "simple" command (without pipes)
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }
    else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        return -1;
    }
    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}
int execute_piped_commands(char ***cmd) {
    int num_cmds = 0;
    int i;
    pid_t pid;
    int status;
    while (cmd[num_cmds] != 0) {
        num_cmds++;
    }
    if (num_cmds == 0) {
        return 0;
    }
    else if (num_cmds == 1) {
        return execute_command(cmd[0]);
    }
    int pipefds[2 * (num_cmds - 1)]; // 2 pipe ends between each pair of cmds; there is 1 pipe less than there are cmds
    for (i = 0; i < num_cmds - 1; i++) {
        if (pipe(pipefds + 2 * i) == -1) {
            perror("pipe");
            return -1;
        }
    }
    for (i = 0; i < num_cmds; i++) {
        pid = fork();
        if (pid == -1) {
            perror("fork");
            return -1;
        }
        if (pid == 0) {
            // if not first command, connect read end of previous pipe to stdin
            if (i > 0) {
                if (dup2(pipefds[2 * (i - 1)], 0) == -1) {
                    perror("dup2");
                    exit(1);
                }
            }
            // if not last command, connect write end of next pipe to stdout
            if (i < num_cmds - 1) {
                if (dup2(pipefds[2 * i + 1], 1) == -1) {
                    perror("dup2");
                    exit(1);
                }
            }
            // close all pipe ends (file descriptors)
            for (int j = 0; j < 2 * (num_cmds - 1); j++) {
                close(pipefds[j]);
            }
            execvp(cmd[i][0], cmd[i]);
            perror("execvp");
            exit(1);
        }
    }
    for (int j = 0; j < 2 * (num_cmds - 1); j++) {
            close(pipefds[j]);
        }
    for (i = 0; i < num_cmds; i++) {
        wait(&status);
    }
    return WEXITSTATUS(status);
}

int main() {
    int spid, status;
    char ***cmd;
    while (1) {
        printf("myshell > ");
        cmd = readcommand();
        trace_cmd(cmd);
        if (!cmd[0]) {
            continue;
        }
        if (!strcasecmp(cmd[0][0], "exit")) {
            return 0;
        }
        execute_piped_commands(cmd);
    }
}
