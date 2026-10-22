#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <linux/limits.h>

static char **dirs; // pour que la variable soit modifiée quand on la passe comme argument à filldirs()

void filldirs() {
    int n; // indice de ":"
    char *path = getenv("PATH");
    assert(path);
    char *tmp;

    // Traiter le cas du PATH vide
    if (*path == '\0') n = 1;
    // Déterminer la taille du path pour faire malloc() ensuite
    else {
        n = 2;
        for (tmp = path; *tmp; tmp++) {
            if (*tmp == ':') n++; // ne pas transformer ':' en '\0' immédiatement afin de préserver la valeur de path
        }
    }
    dirs = malloc(n * sizeof(char*));
    assert(dirs);
    dirs[n - 1] = NULL; // tableau terminé par un pointeur NULL
    if (n == 1) return;

    // Le premier élément est la chaîne contenant tous les répertoires dans PATH, pour que tmp puisse les scanner et les ajouter au reste du tableau
    dirs[0] = path;
    n = 1;
    for (tmp = path; *tmp; tmp++) {
        if (*tmp == ':') {
            *tmp = '\0';
            dirs[n++] = tmp + 1;
        }
    }
    return;
}

int which(char *cmd) { // 1 (true): commande trouvée, 0 (false) sinon
    char tmp[PATH_MAX + 1];
    int i = 0;
    while (dirs[i]) {
        snprintf(tmp, PATH_MAX + 1, "%s/%s", dirs[i], cmd);
        if (!access(tmp, X_OK)) {
            puts(tmp);
            return 1;
        }
        i++;
    }
    return 0;
}

// Afficher tous les répertoires dans PATH si le programme est appelé sans arguments supplémentaires
int main(int argc, char *argv[]) {
    filldirs();
    int state = EXIT_SUCCESS;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            if (which(argv[i]) == 0) {
                printf("Commande \"%s\" non trouvée.\n", argv[i]);
                state = EXIT_FAILURE;
            }
        }
    }
    else {
        for (int i = 0; dirs[i]; i++) {
            puts(dirs[i]);
        }
    }
    return state;
}