/*
Question: . Write a C program where you will declare an integer and a floating point variable,
input them using scanf, and print these values. 

Sample input 
=====================================================
 17  3.508

Sample output
=====================================================
Integer value = 17
Floating point value = 3.508
*/

#include <stdio.h>

int main(){
    int a;
    float b;

    scanf("%d %f", &a, &b);

    printf("Integer value = %d\nFloating point value = %.3f", a, b);

    return 0;
}