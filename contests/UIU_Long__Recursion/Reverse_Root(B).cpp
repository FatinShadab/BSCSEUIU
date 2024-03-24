// problem link : https://vjudge.net/contest/616828#problem/B
#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

void recursive_solve() {
    ull ai;

    if (!(cin >> ai)) return;

    recursive_solve();
    printf("%.4lf\n", sqrt(ai));
}

int main() {
    recursive_solve();
    return 0;
}