/*
Write a program (WAP) that will reverse the digits of an input integer.
*/
#include <stdio.h>

int main(){

    int num,r,reverse=0;

    scanf("%d", &num);

    while(num){
        r = num%10;
        reverse = reverse * 10 + r;
        num = num / 10;
    }

    printf("%d", reverse);

    return 0;
}