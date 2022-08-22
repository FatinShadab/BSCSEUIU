/*
Question:  . Write a C program which will take as input the height of an object in centimeters,
and represent it in meter-centimeter format.

Sample input                        Sample output    
    157                         1 meter 57 centimeter
    2309                        23 meter 9 centimeter
*/

#include <stdio.h>

int main(){
    int height;

    scanf("%d", &height);

    printf("%d meter %d centimeter", height/100, height%100);

    return 0;
}