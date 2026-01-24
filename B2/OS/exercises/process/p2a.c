#include <stdio.h>
int Acompute1() {
    return 25;
}
void Acompute2(int resB) {
    fprintf(stderr, "Received value from B is %d\n", resB); // use stderr for debugging, since stdout gets piped into stdin
}
int main() {
    int resA = Acompute1();
    printf("%d\n", resA); // scanf scans until newline (similar to how user presses enter key)
    fflush(stdout);
    int resB;
    scanf("%d", &resB);
    Acompute2(resB);
    return 0;
}