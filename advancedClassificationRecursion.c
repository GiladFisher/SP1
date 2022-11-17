#include <stdio.h>
#include<math.h>
#include "NumClass.h"

void fillArray(int array[], int index, int in){
    if (index < 0) {
        return;
    }
    array[index] = in % 10;
    fillArray(array, index -1, in/10 );
}

int scanArray(int array[], int index, int no_digit){
    if(index >= (no_digit -1 -index)){
        return 1;
    }
    if(array[index] != array[(no_digit -1 -index)]){
        return 0;
    }
    return scanArray(array, index+1, no_digit);
}

int sumArms(int in, int no_digit){
    if (in < 10){
        return (int)pow(in, no_digit);
    }
    return sumArms(in/10, no_digit) + (int)pow(in % 10, no_digit);
}
int numberOfDigits(int in){
    if(in == 0){
        return 0;
    }
    return 1 + numberOfDigits(in/10);
}
int isArmstrong(int in){
    int no_digit = numberOfDigits(in);
    int temp = in;
    int sum = sumArms(temp, no_digit);
    if (sum == in){
        return 1;
    }
    return 0;
}

int isPalindrome(int in){
    int no_digit = numberOfDigits(in);
    int temp = in;
    int digit_arr[no_digit];
    int index = no_digit - 1;
    fillArray(digit_arr, index, temp);
    return scanArray(digit_arr,0,no_digit);
}

//int scanPalindrome
