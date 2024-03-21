// Problem Link : https://vjudge.net/contest/616828#problem/F
#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

int COUNT = 0;

ull rev_num(ull N) {
    ull R = 0;

    do {
        R = (R * 10) + (N % 10);
        N /= 10;
    } while(N != 0);

    return R;
}

ull rev_and_add(ull N) {
    ull rev_N = rev_num(N);

    if (rev_N == N) {
        return N;
    }

    COUNT++;
    return rev_and_add(N + rev_N);
}

int main() {
    int T;
    ull N, ANS;
    scanf("%d", &T);

    while (T--) {
        cin >> N;
        ANS = rev_and_add(N);
        cout << COUNT << " " << ANS << "\n";
        COUNT = 0;
    }

    return 0;
}