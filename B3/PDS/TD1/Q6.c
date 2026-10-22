#include <stdio.h>
#include <assert.h>

#define TAILLE 10

int main(int argc, char *argv[]) {
    int n = TAILLE;
    int tableau[n];

    FILE *f = fopen(argv[1], "r");
    assert(f);
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d\n", tableau + i); // scanf lire de f et écrire à &(tableau[i])
        printf("%d\n", tableau[i]);
    }
    fclose(f);
    return 0;
}