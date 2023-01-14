/*
Program that will decide whether a number is even or odd.
*/
#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    if (number % 2 == 0){
        printf("Even");
    }
    else{
        printf("Odd");
    }

    return 0;
}