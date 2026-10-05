#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <linux/limits.h>

static char **dirs; // pour que la variable soit modifiée quand on la passe comme argument à filldirs()

void filldirs() {
    int n; // indice de ":"
    char *path = getenv("PATH");
    char *tmp;
    assert(path);

    // Traiter le cas du PATH vide
    if (*path == '\0') n = 1;
    // Déterminer la taille du path pour faire malloc() ensuite
    else {
        n = 2;
        for (tmp = path; *tmp; tmp++) {
            if (*tmp == ':') n++;
        }
    }
    dirs = malloc(n * sizeof(char*));
    assert(dirs);
    dirs[n - 1] = NULL;
    if (n == 1) return;

    dirs[0] = path;
    n = 1;
    for (tmp = path; *tmp; tmp++) {
        if (*tmp == ':') {
            dirs[n++] = tmp + 1;
            *tmp = '\0';
        }
    }
    return;
}

int which(char *cmd) {
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

int main() {
    // filldirs();
    which("ls");
}