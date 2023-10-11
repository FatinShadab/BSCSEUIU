/*
    Calculate the factorial of n.
*/

#include <stdio.h>

int limitedFactorialFunction(int n) {
    if (n == 0) return 1;

    return n * limitedFactorialFunction(n-1);
}

int main() {
    int n; scanf("%d", &n);

    printf("Factorial of %d : %d\n", n, limitedFactorialFunction(n));

    return 0;
}