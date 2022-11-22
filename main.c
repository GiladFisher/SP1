#include "NumClass.h"
#include <stdio.h>
#include <math.h>


int main()
{

int x,y;

printf("Enter the 1st number: ");
scanf("%d", &x);
printf("Enter the 2nd number: ");
scanf("%d", &y);

if ( y < x )
{
    int temp = x;
    x = y;
    y = temp;
}

int i;

printf("The Armstrong numbers are: ");
for(i=x ; i<=y ; i++)
{   
    if( isArmstrong(i) )
    {
        printf("%d ",i);
    }
}
printf("\n");


printf("The Palindromes are: ");
for(i=x ; i<=y ; i++)
{
    if( isPalindrome(i) )
    {
        printf("%d ",i);
    }
}
printf("\n");

printf("The Prime numbers are: ");
for(i=x ; i<=y ; i++)
{
    if( isPrime(i) )
    {
        printf("%d ",i);
    }
}
printf("\n");

printf("The Strong numbers are: ");
for(i=x ; i<=y ; i++)
{
    if( isStrong(i) )
    {
        printf("%d ",i);
    }
}
printf("\n");

return 0;
}