// Problem Link : https://vjudge.net/contest/616828#problem/D
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cache;

int fn(int n) {
    if (cache.find(n) != cache.end())
        return cache[n];

    return cache[n] = (fn(n-1) % 10000007 + fn(n-2) % 10000007 + fn(n-3) % 10000007 + fn(n-4) % 10000007 + fn(n-5) % 10000007 + fn(n-6) % 10000007) % 10000007;
}

int main() {
    int n, cases;
    scanf("%d", &cases);

    for (int caseno = 1; caseno <= cases; ++caseno) {
        int a, b, c, d, e, f;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        cache.clear();
        cache[0] = a % 10000007;
        cache[1] = b % 10000007;
        cache[2] = c % 10000007;
        cache[3] = d % 10000007;
        cache[4] = e % 10000007;
        cache[5] = f % 10000007;
        printf("Case %d: %d\n", caseno, fn(n));
    }

    return 0;
}
