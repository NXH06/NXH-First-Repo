#include <stdio.h>

#define TAILLE 16

int main(int argc, char *argv[]) {
    int tableau[TAILLE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int n = TAILLE;

    FILE *f = fopen(argv[1], "w");
    if (!f) {
        printf("Le fichier n'existe pas.");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d\n", tableau[i]);
    }
    fclose(f);
    return 0;
}