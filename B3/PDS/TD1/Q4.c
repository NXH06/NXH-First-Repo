#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define TAILLE 16

// Q3 a écrit le tableau (16 nombres de 0 à 15) au fichier "writefile.txt", donc Q4 va en lire
int main(int argc, char *argv[]) {
    assert(argc > 1);
    int fd, n;
    int tampon[TAILLE];
    fd = open(argv[1], O_RDONLY);
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