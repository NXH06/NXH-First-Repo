#include <stdio.h>

#define TAILLE 16

int main(int argc, char *argv[]) {
    int n = TAILLE;

    FILE *f = fopen(argv[1], "w");
    if (!f) {
        printf("Le fichier n'existe pas.");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d\n", tableau[i]);
    }
    fclose(f);
    return 0;
}