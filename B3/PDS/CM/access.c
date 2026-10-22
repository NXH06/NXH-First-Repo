#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    char *home = getenv("HOME");
    char filepath[256]; // limite arbitraire
    strcpy(filepath, home);
    strcat(filepath, argv[1]);

    // access retourne 0 au cas de termination normale
    int res = access(filepath, R_OK);
    if (!res) {
        printf("Le fichier est accessible.\n");
        return 1;
    }
    else {
        printf("Le fichier n'est pas accessible.\n");
        return 0;
    }
}