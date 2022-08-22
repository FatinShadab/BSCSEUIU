/*
Question:  Write a C program where you will declare four integer variables (say a, b, c and d), 
input them using scanf, and calculate a * b + (a – c) / d + b.

Sample input                                                  Sample output   
21 15 34 6                                           21 * 15 + (21 – 34) / 6 + 15 = 327 
*/

#include <stdio.h>

int main(){
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int res = a * b + (a - c) / d + b;

    printf("%d * %d + (%d - %d) / %d + %d = %d", a, b, a, c, d, b, res);
    
    return 0;
}