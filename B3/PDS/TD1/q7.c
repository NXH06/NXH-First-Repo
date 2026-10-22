#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char nom[128];
    char prenom[128];
    int age;
    int taille_cm;
} personne;

int main(int argc, char *argv[]) {
    personne bd[3] = {
        {"Nguyen", "Xuan Hien", 20, 170},
        {"Asdf", "Ghjkl", 99, 9000},
        {"Zxcv", "Bnm", 11, 1000}
    }; // liste de personnes
    int n_personnes = 3;

    int fd = open("binfile.bin", O_WRONLY | O_CREAT);
    assert(fd != -1);
    for (int i = 0; i < n_personnes; i++) {
        write(fd, bd + i, sizeof(personne));
    }
    close(fd);
}