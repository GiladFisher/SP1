#include <stdio.h>
#include <stdlib.h>

// a program that crashes due to dividing by zero

int main() {
    int i = 0;
    int j = 1;
    int k = j / i;
    return 0;
}