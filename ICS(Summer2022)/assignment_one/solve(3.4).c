/*
Question: Write a C program where you will declare four integer variables (say a, b, c and d)
initialize them by values of your choice, and calculate a * b + (a – c) / d + b. 

Sample output 
=====================================================
21 * 15 + (21 – 34) / 6 + 15 = 327

*/

#include <stdio.h>

int main(){
    int a = 21;
    int b = 15;
    int c = 34;
    int d = 6;

    int result = a * b + (a - c) / d + b;

    printf("%d * %d + (%d - %d) / %d + %d = %d", a, b, a, c, d, b, result);

    return 0;
}