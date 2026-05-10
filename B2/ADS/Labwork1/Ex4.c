// PSEUDOCODE
// (insert here a simple algorithm to check if a number is a prime)
// input n
// if n < 30 or n is prime
//      n is not a sphenic number
// int arr[3]
// int count = 0
// int n_original = n
// for i in range 2 to n
//      if n%i == 0 and i is prime
//          add i to array
//          count <- count + 1
//          n <- n/i
//      if n == 1 or count == 3
//          exit loop
// if n == 1 and count == 3
//      n is a sphenic number
// else
//      n is not a sphenic number
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
int isSphene(int n) {
    if (n < 30 || isPrime(n)) {
        return 0;
    }
    int arr[3] = {0}; int count = 0;
    for (int i = 2; i <= n; i++) {
        if (n%i == 0 && isPrime(i)) {
            count++;
            arr[count-1] = i;
            n /= i;
            if (n%i == 0) {
                return 0;
            }
            printf("n = %d; count = %d; i = %d; arr: %d, %d, %d\n",n,count,i,arr[0],arr[1],arr[2]);
        }
        if (n == 1 || count == 3) {
            break;
        }
    }
    if (n == 1 && count == 3) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    int n;
    printf("> Input number: ");
    scanf("%d",&n);
    if (isSphene(n)) {
        printf(">> SPHENIC"); 
    }
    else {
        printf(">> NOT SPHENIC"); 
    }
    return 0;
}