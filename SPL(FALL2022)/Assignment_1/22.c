/*
Write a program (WAP) that will run and show keyboard
inputs until the user types an ’A’ at the keyboard. 
*/
#include <stdio.h>

int main(){
    int count=0;
    char chr;

    while(1){
        chr = getchar();
        fflush(stdin);
        if (chr == 'A') break;
        printf("Input %d:%c\n", ++count, chr);
    }

    return 0;
}