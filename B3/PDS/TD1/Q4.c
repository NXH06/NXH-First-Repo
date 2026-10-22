#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define TAILLE 10

int main(int argc, char *argv[]) {
    int fd, n;
    int tampon[TAILLE];

    fd = open("binfile.bin", O_RDONLY);
    assert(fd != -1);
    while ((n = read(fd, tampon, TAILLE * sizeof(int))) > 0) {
        assert(n % sizeof(int) == 0);
        for (int i = 0; i < n / sizeof(int); i++) {
            printf("%d ", tampon[i]);
        }
    }
    assert(close(fd) != -1);
    return 0;
}