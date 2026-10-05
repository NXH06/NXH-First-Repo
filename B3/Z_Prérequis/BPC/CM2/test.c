# include <stdio.h>
# include "fact.h"
int main (){
    int n;
    puts ("Donnes moi un entier");
    scanf ("%d", &n);
    printf ("La factorielle de %d est %d\n", n, fact(n));
    return 0;
}