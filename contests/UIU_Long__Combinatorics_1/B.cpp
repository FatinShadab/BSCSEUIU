// Problem Link : https://vjudge.net/contest/561093?fbclid=IwAR0mAKGKvcRnald64QWvLWCvAs_uIIXeHrMCL04sP0bAiUqIHRefuVVlg_k#problem/B
// help         : https://github.com/lightoj-dev/problem-tutorials/blob/main/1005/en.md

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[30*30][30*30];

ll nCr(int n, int k){
    if (k == 1){
        return n;
    }

    if (n == k || k == 0){
        return 1;
    }

    if (dp[n][k] == 0){
        dp[n][k] = nCr(n-1, k) + nCr(n-1, k-1);
    }

    return dp[n][k];
}

int main(){
    int T, n, k;
    scanf("%d", &T);

   ll fact[20];
   fact[0]=fact[1]=1;
   for(int i=2;i<=20;i++)fact[i]=i*fact[i-1];

    for (int case_no = 1; case_no <= T; case_no++){
        ll result = 0;

        scanf("%d %d", &n, &k);

        if (k <= n){
            result = nCr(n, k);
            result *= result;
            result *= fact[k];
        }

        printf("Case %d: %lld\n", case_no, result);
    }

    return 0;
}