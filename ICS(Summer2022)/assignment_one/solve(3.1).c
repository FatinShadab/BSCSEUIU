/*
Question: Write a C program where you will declare an integer, a floating point 
and a character variable, initialize them by values of your choice, and print these values.

Sample output 
=====================================================
Integer value = 17
Floating point value = 3.508
Character value = W

*/

#include <stdio.h>

int main(){
    int integer = 17;
    float float_value = 3.508;
    char character = 'W';

    printf("Integer value = %d\n", integer);
    printf("Floating point value = %.3f\n", float_value);
    printf("Integer value = %c", character);

    return 0;
}