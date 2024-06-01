#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b){
    return a > b ? a : b;
}
int firstalg(int n, int array[]){
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
                for (int k = a; k <= b; k++) {
                    sum += array[k];
                }
            best = max(best,sum);
        }
    }
    return best;
}

int secondalg(int n, int array[]){
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best,sum);
        }
    }
    return best;
}

int thirdalg(int n, int array[]){
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    return best;
}

int* generateArray(int n, int seed){
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 - 50;
    }
    return array;
}


int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Error\n");
        return 1;
    }
    int n = atoi(argv[1]);
    int seed = atoi(argv[2]);
    srand(seed);
    int* array = generateArray(n, seed);
    printf("which algo?: ");
    int algo;
    scanf("%d", &algo);
    if(algo == 1){
        int best = firstalg(n, array);
        printf("First algorithm: %d\n", best);
    }
    else if(algo == 2){
        int best = secondalg(n, array);
        printf("Second algorithm: %d\n", best);
    }
    else if(algo == 3){
        int best = thirdalg(n, array);
        printf("Third algorithm: %d\n", best);
    }
    else{
        printf("Invalid input\n");
    }
}