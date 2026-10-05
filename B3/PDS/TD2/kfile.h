#include <stdio.h>
#include <assert.h>

#define SIZE 256
#define MAGIC 0xFA32C10F

typedef struct {
    long magic;
    char buf[SIZE];
    int fd;
    int off; // indice où lire/écrire du buf
} KFILE;

int kflush(KFILE *f) {
    assert(f);
    if (write(f->fd, f->buf, f->off) != f->off) {
        return EOF;
    }
    f->off = 0;
    return 0;
}

