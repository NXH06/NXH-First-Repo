#include <stdio.h>
int power (int n, int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= n;
    }
    return result;
}
int digitCount (int n) {
    int digits = 0;
    while (n != 0) {
        n /= 10;
        digits += 1;
    }
    return digits;
}
int isArmstrongIter (int n) {
    int sum = 0;
    int digits = digitCount(n);
    int temp = n;
    while (temp != 0) {
        sum += power((temp%10), digits);
        temp /= 10;
    }
    if (sum == n) {
        return 1;
    }
    else {
        return 0;
    }
}
// Complexity of the iterative function: O(log(n)^2)
// because the function power() and the "while (temp != 0)" loop each has complexity of O(log(n))
int isArmstrongRecur (int n, int digits, int match) {
    if (n == 0) {
        return (match == 0);
    }
    match -= power((n%10),digits);
    n /= 10;
    return isArmstrongRecur (n, digits, match);
}
// Complexity of the recursive function: O(log(n)^2), same reason as the iterative function
int main() {
    int n;
    printf("\nInput number: ");
    scanf("%d", &n);
    printf("Iter: %d, Recur: %d", isArmstrongIter(n), isArmstrongRecur(n, digitCount(n), n));
    return 0;
}