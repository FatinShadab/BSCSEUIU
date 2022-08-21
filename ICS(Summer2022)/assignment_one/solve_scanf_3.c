/*
Question:   Write a C program where you will declare two floating point variables, input them using scanf, and perform the basic arithmetic operations on them. 

Sample input 
=====================================================
95.401  22.622

Sample output 
=====================================================
95.401 + 22.622 = 118.023 
95.401 – 22.622 = 72.779 
95.401 * 22.622 = 2158.161422 
95.401 / 22.622 = 4.217178
*/


#include <stdio.h>

int main(){
    float a, b;

    scanf("%f %f", &a, &b);

    printf("%.3f + %.3f = %.3f\n", a, b, (a + b));
    printf("%.3f - %.3f = %.3f\n", a, b, (a - b));
    printf("%.3f * %.3f = %.6lf\n", a, b, (a * b));
    printf("%.3f + %.3f = %.6f", a, b, (a / b));

    return 0;
}