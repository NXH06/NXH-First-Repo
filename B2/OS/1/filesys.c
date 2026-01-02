#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    const char *path = "/home/nxh/Desktop/file.txt";
    int fd = open(path, O_RDWR | O_CREAT, 0700); // to prevent C from reading the number as an octal
    const char *message = "Hello world!\nThis is a test message for lecture 1 of the OS course.\n";
    ssize_t p = write(fd, message, strlen(message));
    printf("Byte length of written string: %ld\n", p);
    return 0;
}