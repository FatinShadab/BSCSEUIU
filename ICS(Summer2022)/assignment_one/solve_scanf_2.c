/*
Question:  Write a C program where you will declare two integer variables, input them using scanf, and perform the basic arithmetic operations on them. 

Sample input 
=====================================================
18 7

Sample output
=====================================================
18 + 7 = 25
18 – 7 = 11
18 * 7 = 126
18 / 7 = 2
18 % 7 = 4
*/

#include <stdio.h>

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d + %d = %d\n", a, b, (a + b));
    printf("%d - %d = %d\n", a, b, (a - b));
    printf("%d * %d = %d\n", a, b, (a * b));
    printf("%d / %d = %d\n", a, b, (a / b));
    printf("%d %% %d = %d", a, b, (a % b));

    return 0;
}