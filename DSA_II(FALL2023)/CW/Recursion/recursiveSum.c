#include <stdio.h>

int sumOfRangeN(int n) {
    if (n == 0) {
        return 0;
    }

    return n + sumOfRangeN(n-1);
}

int main() {

    int n; scanf("%d", &n);

    printf("Sum of range [1 - %d] : %d\n", n, sumOfRangeN(n));

    return 0;
}