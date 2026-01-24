#include <stdio.h>
int Bcompute1() {
    return 100;
}
void Bcompute2(int resA) {
    fprintf(stderr, "Received value from A is %d\n", resA); // use stderr for debugging, since stdout gets piped into stdin
}
int main() {
    int resB = Bcompute1();
    printf("%d\n", resB); // scanf scans until newline (similar to how user presses enter key)
    fflush(stdout);
    int resA;
    scanf("%d", &resA);
    Bcompute2(resA);
    return 0;
}