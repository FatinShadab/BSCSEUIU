// PB LINK : https://www.hackerrank.com/contests/ycpc-by-phitron-a-2nd-round-contest-1-a-2023/challenges/marbels
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long marbles[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &marbles[i]);
    }

    int Q;
    scanf("%d", &Q);

    long long diff[N];
    for (int i = 0; i < N; i++) {
        diff[i] = 0;
    }

    for (int q = 0; q < Q; q++) {
        int A, B;
        long long X;
        scanf("%d %d %lld", &A, &B, &X);
        
        diff[A] += X;
        if (B + 1 < N) {
            diff[B + 1] -= X;
        }
    }

    for (int i = 1; i < N; i++) {
        diff[i] += diff[i - 1];
    }

    for (int i = 0; i < N; i++) {
        marbles[i] += diff[i];
    }

    for (int i = 0; i < N; i++) {
        printf("%lld ", marbles[i]);
    }
    printf("\n");

    return 0;
}