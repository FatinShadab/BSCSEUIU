// problem link : https://vjudge.net/contest/616828#problem/J
#include <bits/stdc++.h>

using namespace std;

int gcdSum(int i, int j, int G, int N) {
    // printf("i:%d, j:%d\n", i, j);

    if (i > N) {
        return G;
    }
    if (j > N && i <= N) {
        return gcdSum(i+1, i+2, G, N);
    }

    G += __gcd(i, j);

    return gcdSum(i, j+1, G, N);
}

int main() {
    int N;

    do {
        scanf("%d", &N);
        if (N != 0) printf("%d\n", gcdSum(1, 2, 0, N));
    }
    while (N != 0);

    return 0;
}