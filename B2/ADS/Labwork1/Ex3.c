#include <stdio.h>
struct complex {
    float real, imag;
};
struct complex complexAdd (struct complex n1, struct complex n2) {
    struct complex sum;
    sum.real = n1.real+n2.real;
    sum.imag = n1.imag+n2.imag;
    return sum;
}
struct complex complexMultiply (struct complex n1, struct complex n2) {
    struct complex product;
    product.real = n1.real*n2.real;
    product.imag = n1.imag*n2.imag;
    return product;
}
void complexPrint(struct complex n) {
    printf("%.3f + %.3fi",n.real,n.imag);
}
int main() {
    struct complex n1,n2,sum,product;
    printf("> Input first complex number (real, imaginary): ");
    scanf("%f",&n1.real);
    scanf("%f",&n1.imag);
    printf("> Input second complex number: ");
    scanf("%f",&n2.real);
    scanf("%f",&n2.imag);
    sum=complexAdd(n1,n2);
    product=complexMultiply(n1,n2);
    printf(">> Sum: "); complexPrint(sum);
    printf("\n>> Product: "); complexPrint(product);
    return 0;
}