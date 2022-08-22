/*
Question:  Write a C program where you will declare four floating point variables (say a, b, c and d), input them using scanf, and calculate (a + b – c) * d – a / d.

Sample input                                                 Sample output    
2.3 5.8 1.1 3.5                               (2.3 + 5.8 – 1.1) * 3.5 – 2.3 / 3.5 = 23.842857
*/

#include <stdio.h>

int main(){
    float a, b, c, d;

    scanf("%f %f %f %f", &a, &b, &c, &d);

    float res = (a + b - c) * d - a / d;

    printf("(%.1f + %.1f - %.1f) * %.1f - %.1f / %.1f = %f", a, b, a, c, d, b, res);
    
    return 0;
}