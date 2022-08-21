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