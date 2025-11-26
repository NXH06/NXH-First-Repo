// PSEUDOCODE FOR ITERATION APPROACH
// sumDigitIter (int n)
    // int sum = 0
    // while n > 0
        // sum = sum + n%10
        // n = floor(n/10)
    // return sum
#include <stdio.h>
int sumDigitIter (int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
} // complexity: O(log n) since the amount of times the program loops is equal to the number of digits in n
int sumDigitRecur (int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return sumDigitRecur(n / 10) + n % 10;
    }
} //complexity: also O(log n), same reason as above
int main() {
    int n = 12345678;
    printf("%d, %d",sumDigitIter(n),sumDigitRecur(n));
    return 0;
}