#include <stdio.h>
#include <stdlib.h>

// a program that crashes due to accessing an invalid memory location

int main() {
    int i = 0;
    int *p;
    *p = 0xdeadbeef;
    return 0;
}