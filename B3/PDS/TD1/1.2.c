#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int writehex() {
    int data = 825391;
    int f = open("writefile.txt", O_WRONLY | O_CREAT, 0x777);
    int r = write(f, &data, sizeof(int));
    close(f);
}


int writestring() {
    char tampon[16];
    int data = 825391;

    int n = snprintf(tampon, 16, "%s", data);
    int f = open("writefile.txt", O_WRONLY | O_CREAT, 0x777);
    int r = write(f, tampon, n);
    close(f);
}

int main(int argc, char *argv[]) {
    writestring();
    return 0;
}