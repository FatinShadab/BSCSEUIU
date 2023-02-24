/*
    Problem Link : https://vjudge.net/contest/544590?fbclid=IwAR1stOHEIoWUKzwkBHaxzxjQUNmRNjGF-4tujotFQcGsQpvfIfeh9WXP2IY#problem/E
*/
#include <bits/stdc++.h>

using namespace std;
#define  __fastIO__  ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 1e5;
int arr[N];
long long int prefixSum[N];

int main(){
    __fastIO__

    int n, q, l, r;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);

        if (i == 0){
            prefixSum[i] = arr[i];
        } else {
            prefixSum[i] = arr[i] + prefixSum[i-1];
        }
    }

    scanf("%d", &q);

    while (q--){
        scanf("%d %d", &l, &r);
        printf("%lld\n", prefixSum[r] - prefixSum[l] + arr[l]);
    }

    return 0;
}