/*
Question:. Write a C program where you will declare four floating point variables 
(say a, b, c and d), initialize them by values of your choice, and calculate
(a + b – c) * d – a / d.

Sample output
===================================================== 
(2.3 + 5.8 – 1.1) * 3.5 – 2.3 / 3.5 = 23.842857
*/

#include <stdio.h>

int main(){
    float a = 2.3;
    float b = 5.8;
    float c = 1.1;
    float d = 3.5;

    float res = (a + b - c) * d - a / d;

    printf("(%.1f + %.1f - %.1f) * %.1f - %.1f / %.1f = %f", a, b, c, d, a, d, res);

    return 0;
}