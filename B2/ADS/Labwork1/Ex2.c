#include <stdio.h>

void findMax(int *max, int a) {
    if (a > *max) {
        *max = a;
    }
}
int main() {
    int max = 15;
    int a = 20;
    printf("\n%d",max);
    findMax(&max,a);
    printf("\n%d",max);
    return 0;
}