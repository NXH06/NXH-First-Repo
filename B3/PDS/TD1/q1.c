#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    FILE *f = fopen(argv[1], "r");
    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
    return 0;
}