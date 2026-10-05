#include "kfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DROITS S_IRUSR | S_IWUSR // équivalent: 00600 (= 00400 + 00200). Check man creat(2)

int kputc(int c, KFILE *f) {
    assert(f);
    if (f->magic != MAGIC) {
        // ERROR
    }
    if (f->off == SIZE) {
        if (kflush(f) == EOF) {
            return EOF;
        }
    }
    /* 0 <= f->buf <= SIZE - 1 */
    f->buf[f->off++] = c;
    return c;
}

KFILE *kopen(char *path) {
    KFILE *res;
    int fd;
    fd = creat(path, DROITS);
    if (fd == -1) {
        return NULL;
    }
    res = malloc(sizeof(KFILE));
    if (res == NULL) {
        return NULL;
    }
    res->fd = fd;
    res->off = 0;
    return res;
}

int kclose(KFILE *f) {
    assert(f);
    if (f->off) {
        kflush(f);
    }
    if (close(f->fd) == -1) {
        return EOF;
    }
    free(f);
    return 0;
}
