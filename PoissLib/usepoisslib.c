#include <stdio.h>
#include "libpoisson.h"

void print_usage(double lambda, int k) {
    long double result = poisson(lambda, k);
    printf("Poisson (lambda = %.2f, k = %d) = %Lf\n", lambda, k, result);
}

int main() {
    print_usage(2.0, 1);
    print_usage(2.0, 10);
    print_usage(2.0, 2);
    print_usage(3.0, 3);
    print_usage(100.0, 3);
    return 0;
}
