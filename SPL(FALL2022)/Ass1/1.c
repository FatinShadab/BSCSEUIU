/*
Program that will decide whether a number is positive or not.
*/
#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    if (number < 0){
        printf("Negative");
    }
    else{
        printf("Positive");
    }
    return 0;
}