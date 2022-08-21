/*
Question: Write a C program where you will declare two integer variables, initialize them 
by values of your choice, and perform the basic arithmetic operations on them. The basic 
arithmetic operations are addition (+), subtraction (-), multiplication (*), division (/) and 
remainder (%).

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
    int a = 18, b = 7;

    printf("%d + %d = %d\n", a, b, (a + b));
    printf("%d - %d = %d\n", a, b, (a - b));
    printf("%d * %d = %d\n", a, b, (a * b));
    printf("%d / %d = %d\n", a, b, (a / b));
    printf("%d %% %d = %d", a, b, (a % b));

    return 0;
}