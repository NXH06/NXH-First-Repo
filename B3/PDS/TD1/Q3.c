#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define TAILLE 16

int main(int argc, char *argv[]) {
    int tableau[TAILLE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int n = TAILLE;

    int f = open("writefile.txt", O_WRONLY | O_CREAT, 0x777);
    for (int i = 0; i < n; i++) {
        write(f, tableau + i, sizeof(int)); // tableau + i -> &(tableau[i])
    }
    close(f);
    return 0;
}