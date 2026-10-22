#include <stdio.h>

int tab[2] = {1,2};
int *p = tab;
int main (void){
    printf("%d, %d\n", tab[0], tab[1]);
    *(tab+1) = *tab;
    printf("%d, %d\n", tab[0], tab[1]);
    return 0;
}