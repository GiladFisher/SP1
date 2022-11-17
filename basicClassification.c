#include <stdio.h>
#include "NumClass.h"
// in stands for input
int isPrime(int in){
    for (int i = 2; i < in/2; i++){
        if(in%i == 0){
            return 0;
        } 
    }
    return 1;
}

int isStrong(int in){
    int temp = in;
    int sum = 0;
    int digit;
    while (temp != 0){
        digit = temp % 10;
        temp = (temp - temp % 10)/10;
        int fac_of_digit = 1;
        for (int i=1; i <= digit; i++){
            fac_of_digit *= i;
        }
        sum += fac_of_digit;
    }
    if(sum == in){
        return 1;
    }
    return 0;
}