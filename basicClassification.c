#include "NumClass.h"
#include <stdio.h>
#include <math.h>
int Factorial(int);







int isStrong(int num)
{
    int temp = num;
    int sum = 0;
    while (temp != 0)
    {
        sum += Factorial(temp%10);
        temp /= 10;
    }
    
    return (num == sum);
}

int isPrime(int num)
{
    int i;
    for(i=2; i<num ; i++)
    {
        if( num%i == 0) { return 0; }
    }
    return 1;
}

int Factorial(int num)
{
    int factorial = 1;
    while (num > 1)
    {
        factorial *= num;
        num--;
    }
    return factorial;
}