#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *path = "./file.txt";
    // wipe file before running program again
    remove(path);
    int fd = open(path, O_RDWR | O_CREAT, 0600); // leading zero: to prevent C from reading the number as an octal
    char buf[256];
    // Initial message
    const char *message = "Hello world!\nThis is a test message for lecture 1 of the OS course.\nGoodbye world!\n";
    ssize_t mes_len = write(fd, message, strlen(message));
    printf("Byte length of written string: %ld\n", mes_len);
    // Seek back to beginning of file before reading
    lseek(fd, 0, SEEK_SET);
    int readval = read(fd, buf, 12);
    printf("Read by buffer: %s\n(return code: %d)\n", buf, readval);
    // Seek backwards from the end to write some more stuff
    lseek(fd, -15, SEEK_END);
    printf("> Writing another string...\n");
    message = "A few more things to do...\n";
    mes_len = write(fd, message, strlen(message));
    printf("Byte length of written string: %ld\n", mes_len);
    close(fd);
    return 0;
}