#include "kfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#define DROITS S_IRUSR | S_IWUSR // équivalent: 00600 (= 00400 + 00200). Check man creat.2
#define MODES O_RDWR | O_CREAT

int kputc(int c, KFILE *f) {
    assert(f);
    if (f->magic != MAGIC) {
        // ERROR
    }
    /* 0 <= f->offset <= SIZE - 1 */
    if (f->offset == SIZE) {
        if (kflush(f) == EOF) {
            return EOF;
        }
    }
    f->buf[f->offset++] = c;
    return c;
}
int kgetc(KFILE *f) {
    assert(f);
    // TODO: continuer
}
KFILE *kopen(char *path) {
    KFILE *res;
    int fd;
    fd = open(path, MODES);
    if (fd == -1) {
        return NULL;
    }
    res = malloc(sizeof(KFILE));
    if (res == NULL) {
        return NULL;
    }
    res->fd = fd;
    res->offset = 0;
    return res;
}
int kclose(KFILE *f) {
    assert(f);
    if (f->offset) {
        kflush(f);
    }
    if (close(f->fd) == -1) {
        return EOF;
    }
    free(f);
    return 0;
}

int main() {
    KFILE *kf;
    kf->fd = open("read.txt", O_WRONLY | O_CREAT | O_TRUNC); // Effacer le contenu du fichier avant d'écrire dedans
    assert(kf->fd != -1);
    kf->magic = MAGIC;
    kf->offset = 0;
    
    for (int i = 0; i < SIZE * 2 + 1; i++) {
        kputc('$', kf);
    }
    return 0;
}
