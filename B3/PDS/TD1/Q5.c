#include <stdio.h>
#include <assert.h>

#define TAILLE 10

int main(int argc, char *argv[]) {
    int tableau[TAILLE] = {0,1,2,3,4,5,6,7,8,9};
    int n = TAILLE;

    FILE *f = fopen(argv[1], "w");
    assert(f);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d\n", tableau[i]);
    }
    fclose(f);
    return 0;
}