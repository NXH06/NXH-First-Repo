#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define TAILLE 10

typedef struct {
    char nom[128];
    char prenom[128];
    int age;
    int taille_cm;
} personne;

int main(int argc, char *argv[]) {
    int n_personnes = 3;
    personne tampon[TAILLE];

    int fd = open("binfile.bin", O_RDONLY);
    assert(fd != -1);
    int n;
    while ((n = read(fd, tampon, TAILLE * sizeof(personne))) > 0) {
        for (int i = 0; i < n / sizeof(personne); i++) {
            personne p = tampon[i];
            printf("Personne %d:\n", i + 1);
            printf("\tNom complet: %s %s\n", p.prenom, p.nom);
            printf("\tAge: %d\n", p.age);
            printf("\tTaille en centimètres: %d\n", p.taille_cm);
        }
    }
    close(fd);
}