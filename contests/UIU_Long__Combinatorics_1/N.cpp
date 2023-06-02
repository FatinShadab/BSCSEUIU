// Problem Link : https://vjudge.net/contest/561093?fbclid=IwAR0mAKGKvcRnald64QWvLWCvAs_uIIXeHrMCL04sP0bAiUqIHRefuVVlg_k#problem/A

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define MAX_N 2000000

const ll MOD = 1e9 + 7;

ll fact[MAX_N + 1];

ll bigMod(ll B, ll P, ll M){
    if (P == 0){
        return 1;
    }
    if (P == 1){
        return B%M;
    }

    ll res = bigMod(B, P/2, M);

    res = (res * res) % M;

    if (P & 1) res = (res * B%M) % M;

    return res;
}

ll modInverse(ll b, ll m){
    return bigMod(b, m-2, m);
}

// Using Fermat’s little theorem and modular inverse
ll nCr(int n, int r){
    if (r > n){
        return 0;
    }
    if (n == r || r == 0){
        return 1;
    }

    ll numerator = fact[n] % MOD;
    ll denominator = (fact[n-r] % MOD * fact[r] % MOD) % MOD;
    ll modular_inverse = modInverse(denominator, MOD);

    return (numerator * modular_inverse) % MOD;
}

int main(){
    __fastIO__

    fact[0] = fact[1] = 1;
    for (int i=2; i<=MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int T, n, r;

    cin >> T;

    for(int _case=1; _case <= T; _case++){
        cin >> n >> r;

        cout << "Case " << _case << ": " << nCr(n+r-1, r-1) << "\n";
    }

    return 0;
}