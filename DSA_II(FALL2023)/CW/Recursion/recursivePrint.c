/*
    Prints the numbers from 1 to n
*/

#include <stdio.h>

void recursivePrint(int n) {
    if (n == 0) {
        return;
    }

    recursivePrint(n-1);

    printf("%d ", n);
}


int main() {
    int n; scanf("%d", &n);

    recursivePrint(n);
    printf("\n");

    return 0;
}