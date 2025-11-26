#include <stdio.h>
int isPrime (int p) {
    if (p < 2) {
        return 0;
    }
    for (int i = 2; i*i <= p; i++) {
        if (p%i == 0) {
            return 0;
        }
    };
    return 1;
}
int isSpheneRecur(int n, int count, int start) {
    if (count == 3) {
        return (n == 1);
    }
    if (n == 1) {
        return (count == 3);
    }
    for (int i = start; i <= n; i++) {
        if (n%i == 0 && isPrime(i)) {
            return isSpheneRecur(n/i, count + 1, i + 1);
        }
    }
    return 0;
} // Time complexity: O(n^(3/2)), 
// because isPrime has complexity of O(sqrt(n)) and is invoked a maximum of 3 times

int main() {
    int n;
    printf("> Input number: ");
    scanf("%d",&n);
    for (int j = 30; j <= n; j++)
        if (isSpheneRecur(j, 0, 2)) {
            printf("%d ", j); 
        }
    return 0;
}