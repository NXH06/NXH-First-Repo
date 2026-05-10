#include <stdio.h>
#include <stdlib.h>
int fastPow (int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return fastPow(a, n / 2) * fastPow(a, n / 2);
    }
    else {
        return a * fastPow (a, (n - 1) / 2) * fastPow (a, (n - 1) / 2);
    }
}
// Including base case, function is called log2(n) + 1 or log2(n) + 2 times depends on whether n is even or odd
// Therefore, time complexity is O(log(n))
// Only individual integer values are used, so space complexity is also O(log(n))
int main () {
    int a, n;
    printf("Input: ");
    scanf("%d", &a);
    scanf("%d", &n);
    printf(">> a^n = %d", fastPow(a, n));
    return 0;
}