#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#define SIZE 16
#define MAGIC 0xFA32C10F

typedef struct {
    long magic;
    char buf[SIZE];
    int fd;
    int offset; // indice où lire/écrire du buf
} KFILE;

int kflush(KFILE *f) {
    assert(f);
    // Si le nombre d'octets écrit au fichier est moins que le nombre d'octets que le tampon contient, l'écriture a échouée quelque part et on n'est pas arrivé à vider le tampon correctement
    if (write(f->fd, f->buf, f->offset) != f->offset) {
        return EOF;
    }
    // Réinitialiser l'indice sans vider le tampon - on va en écrire au-dessus plus tard
    f->offset = 0;
    return 0;
}

