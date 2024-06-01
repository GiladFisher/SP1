#include <stdio.h>
#include <stdlib.h>

// a program that crashes due to infinite recursion
void crash() {
    int j = 1;
    crash();
}
int main() {
    int i = 0;
    crash();
    return 0;
}