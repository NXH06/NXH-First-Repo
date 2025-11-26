// kPSEUDOCODE
// input n
// lastDigit <- n%10
// digits <- floor(log10(n))
// firstDigit <- n/(10^digits)
// n_swapped <- lastDigit * (10^digits)
// n_swapped <- n_swapped + n%(10^digits)
// n_swapped <- n_swapped - lastDigit + firstDigit
#include <stdio.h>
#include <math.h>
int main() {
    int n, firstDigit, lastDigit, digits;
    printf("> Input number: ");
    scanf("%d",&n);
    lastDigit = n%10;           // get first and last digits of number
    digits = (int)log10(n);
    firstDigit = (int)n/pow(10,digits);
    int n_swapped;              // swap the digits
    n_swapped = lastDigit*(int)pow(10,digits);
    n_swapped += (int)(n%(int)pow(10,digits));
    n_swapped = n_swapped-lastDigit+firstDigit;
    printf(">> The swapped number is: %d\n",n_swapped);
    return 0;
}