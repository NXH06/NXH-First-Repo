#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {
    char *src, *dest;
    int fd;
    if (argc != 3) {
        printf("Usage: \'./copy <source> <dest>\'\n"); // run using "./copy foo.txt bar.txt"
        exit(1);
    }
    src = argv[1];
    dest = argv[2];
    fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR); // can use octal permission 0600 here, but less readable
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    if (dup2(fd, 1) == -1) {
        perror("dup2");
        exit(1);
    }
    close(fd); // close original file pointer
    // the main command is here
    if (execlp("cat", "cat", src, NULL) == -1) {
        perror("execl");
        exit(1);
    }
    return 0;
}