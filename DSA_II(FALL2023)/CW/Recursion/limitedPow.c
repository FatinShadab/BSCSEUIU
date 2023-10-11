/*
    Calculate a to the power b
*/

#include <stdio.h>

float recursivePow(int a, int b) {
    if (b == 0) return 1;

    if (b < 0) {
        return 1/(float) a * recursivePow(a, b + 1);
    }

    return a * recursivePow(a, b-1);
}

int main() {
    int a, b; scanf("%d %d", &a, &b);

    printf("%d ^ %d = %f\n", a, b, recursivePow(a, b));

    return 0;
}