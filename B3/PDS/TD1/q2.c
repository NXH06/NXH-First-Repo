#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#define TAILLE 16

int main(int argc, char *argv[]) {
    assert(argc == 2);
    int fd = open(argv[1], O_RDONLY);
    assert(fd != -1);
    char tampon[TAILLE];
    int n;
    
    while ((n = read(fd, tampon, TAILLE)) != 0) {
        // écrire à stdout
        write(1, tampon, n);
    }
    close(fd);
    return 0;
}