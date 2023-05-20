#include <bits/stdc++.h>
using namespace std;

#define lint long long
const lint mod = 998244353;

lint bigMod(lint base, lint pow){
    if (pow == 0) return 1;
    if (pow == 1) return base;

    lint res = bigMod(base, pow/2);

    res = (res * res) % mod;

    if (pow & 1) res = (res * base%mod) % mod;

    return res;
}

int main(){
    lint w, h, tiles;
    scanf("%lld %lld", &w, &h);

    tiles = (4 * bigMod(2, w-1) * bigMod(2, h-1)) % mod;

    printf("%lld\n", tiles);

    return 0;
}