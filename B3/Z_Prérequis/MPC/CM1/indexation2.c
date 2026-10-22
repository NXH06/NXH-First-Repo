# include <stdio.h>
# define N 5
int main(){
    int *p;
    int tab[N]={3,1,7,9,4};
    printf("Ordre croissant:\n");
    for (p=&tab[0]; p <= &tab[N-1]; p++)
        printf("%d ",*p);
    printf("\nOrdre decroissant:\n");
    for (p=tab+N-1; p >= tab; p--)
        printf("%d ",p[0]);
    putchar('\n');
    return 0;
}