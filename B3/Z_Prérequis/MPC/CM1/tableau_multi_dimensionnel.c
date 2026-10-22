# include <stdio.h>
char tab[3][4] = {"123","456","789"};
char *foo[3] = {NULL,NULL,NULL};
/* char **foo; possible avec malloc */
int main (void){
    foo[0] = tab[0];
    foo[1] = tab[1];
    foo[2] = tab[2];
    printf(foo[1][1]);
    return 0;
}
