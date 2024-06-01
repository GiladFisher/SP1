#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a program that recieves argc argv to calculate the poisson distribution of a given lambda and k
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }
    long double lambda = strtold(argv[1], NULL);
    long double k = strtold(argv[2], NULL);
    long double result = expl(-lambda) * powl(lambda, k) / tgamma(k + 1); // poisson distribution formula
    printf("px(k)= %Lf\n", result);

}
