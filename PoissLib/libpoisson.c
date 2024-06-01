#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a library that has a function to calculate the poisson distribution of a given lambda and k

long double poisson(long double lambda, long double k) {
    return expl(-lambda) * powl(lambda, k) / tgamma(k + 1); // poisson distribution formula
}