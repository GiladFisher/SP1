#include <stdio.h>
#include<math.h>
#include "NumClass.h"
int main(){
    int bot = 0;
    int top = 0;
    scanf("%d",&bot);
    scanf("%d", &top);
    if ((top - bot) >= 0){
        for (int i = bot; i < top; i++){
            if(isPrime(i)){
                printf("%d ",i);
            }            
        }
        printf("\n");
        for (int i = bot; i <= top; i++){
            if(isArmstrong(i)){
                printf("%d ",i);
            }
        }
        printf("\n");
        for (int i = bot; i < top; i++){
            if(isStrong(i)){
                printf("%d ",i);
            }
        }
        printf("\n");
        for (int i = bot; i < top; i++){
            if(isPalindrome(i)){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
// cd /mnt/c/Users/Selfisher/Documents/GitHub/SP_1