#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // check if the amount of arguments is correct
        printf("Usage: \'%s <programA> <programB>\'\n", argv[0]);
        exit(1);
    }
    char *programA = argv[1];
    char *programB = argv[2];
    int pipeAtoB[2];  // A stdout -> B stdin
    int pipeBtoA[2];  // B stdout -> A stdin
    if (pipe(pipeAtoB) == -1 || pipe(pipeBtoA) == -1) {
        perror("pipe");
        exit(1);
    }
    pid_t pidA, pidB;

    pidA = fork();
    if (pidA == -1) {
        perror("fork");
        exit(1);
    }
    if (pidA == 0) {  // B writes out, A reads in
        // Left of pipe (write end) is 1, right of pipe (read end) is 0
        close(pipeAtoB[0]); // won't read from AtoB
        close(pipeBtoA[1]); // won't write to BtoA
        dup2(pipeAtoB[1], 1); // writes to AtoB - must write first to ensure there is data for the other process to read
        dup2(pipeBtoA[0], 0); // reads from BtoA
        close(pipeAtoB[1]);
        close(pipeBtoA[0]);
        execlp(programA, programA, NULL);
        // Only throw error if execlp fails
        perror("execlp A");
        exit(1);
    }

    pidB = fork();
    if (pidB == -1) {
        perror("fork");
        exit(1);
    }
    if (pidB == 0) {
        close(pipeBtoA[0]);
        close(pipeAtoB[1]);
        dup2(pipeBtoA[1], 1);
        dup2(pipeAtoB[0], 0);
        close(pipeBtoA[1]);
        close(pipeAtoB[0]);
        execlp(programB, programB, NULL);
        perror("execlp B");
        exit(1);
    }
    // Close all pipes after finishing forks
    close(pipeAtoB[0]);
    close(pipeAtoB[1]);
    close(pipeBtoA[0]);
    close(pipeBtoA[1]);
    // Wait for both child processes to finish
    int statusA, statusB;
    waitpid(pidA, &statusA, 0);
    waitpid(pidB, &statusB, 0);
    // Check if child processes succeeded
    if (WIFEXITED(statusA) && WIFEXITED(statusB)) {
        printf("Both programs completed successfully.\n");
        exit(0);
    }
    else {
        printf("One or both child processes failed\n");
        exit(1);
    }
}