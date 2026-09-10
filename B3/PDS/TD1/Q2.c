#include <stdio.h>
#include <assert.h>
#include <fcntl.h>

#define TAILLE 16

int main(int argc, char *argv[]) {
    assert(argc > 1);
    int fd, n;
    char tampon[TAILLE];
    fd = open(argv[1], O_RDONLY);
    assert(fd != -1);
    while ((n = read(fd, tampon, TAILLE)) > 0) {
        for (int i = 0; i < n; i++) {
            write(1, tampon + i, 1);
        }
    }
    assert(close(fd) != -1);
    return 0;
}