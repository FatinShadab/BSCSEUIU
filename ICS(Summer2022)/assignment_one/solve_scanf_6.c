/*
Question:  Write a C program which will calculate the area of a circle, given its radius.
(Assume that pi = 3.14159)

Sample input                                    Sample output    
    5                                           Area = 78.53975
*/

#include <stdio.h>

int main(){
    const float PI = 3.14159;
    int r;

    scanf("%d", &r);

    printf("Area = %.5f", PI*(r*r));
    
    return 0;
}