#include <stdio.h>
#include<math.h>
#include "NumClass.h"
int isArmstrong(int in){
    int no_digit = 0;// number of digits
    int temp = in;
    do{
        temp = temp/10;
        no_digit++;
    }while (temp != 0);
    temp = in;
    int sum = 0;
    int digit;
    while (temp != 0){
        digit = temp % 10;
        temp = (temp - temp % 10)/10;
        sum += (int)pow(digit, no_digit);
    }
    if (sum == in){
        return 1;
    }
    return 0;
}
int isPalindrome(int in){
    int no_digit = 0;// number of digits
    int temp = in;
    do{
        temp = temp/10;
        no_digit++;
    }while (temp != 0);
    temp = in;
    int digit_arr[no_digit];
    int index = no_digit - 1;
    int digit;
    while (temp != 0){
        digit = temp % 10;
        temp = (temp - temp % 10)/10;
        digit_arr[index] = digit;
        index--;
    }
    for (int i = 0; i < no_digit - i -1; i++){
        if(digit_arr[i] != digit_arr[no_digit -1 -i]){
            return 0;
        }
    }
    return 1;
}