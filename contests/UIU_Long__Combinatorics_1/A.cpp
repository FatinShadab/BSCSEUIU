// Problem Link : https://vjudge.net/contest/561093?fbclid=IwAR0mAKGKvcRnald64QWvLWCvAs_uIIXeHrMCL04sP0bAiUqIHRefuVVlg_k#problem/A

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll unsigned long long
#define MOD 1000003
#define MAX_N 1000000

ll fact[MAX_N + 1];

/*

// without dp --> TLE
// with dp --> memory problem

int dp[10000][10000];

int nCr(int n, int r){
    if (n == r || r == 0){
        return 1;
    }

    if (n >= 10000|| r >= 10000){
        return (nCr(n-1, r)%MOD + nCr(n-1, r-1)%MOD)%MOD;
    }

    if (dp[n][r] == 0){
        dp[n][r] = (nCr(n-1, r)%MOD + nCr(n-1, r-1)%MOD)%MOD;
    }

    return dp[n][r];
}
*/

ll bigMod(int B, int P, int M){
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

ll modInverse(int b, int m){
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

    return (fact[n] * (modInverse(fact[r], MOD) % MOD) * (modInverse(fact[n - r], MOD) % MOD)) % MOD;
}

int main(){
    __fastIO__

    fact[0] = 1;
    for (int i=1; i<=MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int T, n, r;

    cin >> T;

    for(int _case=1; _case <= T; _case++){
        cin >> n >> r;

        cout << "Case " << _case << ": " << nCr(n, r) << "\n";
    }

    return 0;
}