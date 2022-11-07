/*
Program that will read from the console a random positive nonzero number and determine if it is a power of 2. 
*/
#include <stdio.h>

int main(){

    int number;

    scanf("%d", &number);

    int chk = number & (number - 1);

    if (chk == 0){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}