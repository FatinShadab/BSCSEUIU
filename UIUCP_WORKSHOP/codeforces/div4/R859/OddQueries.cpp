/*
    Problem link --> https://codeforces.com/contest/1807/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int prefixSum[N];
int arr[N];

int main(){
    int T; scanf("%d", &T);
    int n, q, li, ri, k;
    long long int sum;

    while (T--){
        scanf("%d %d", &n, &q);

        for (int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            prefixSum[i] = (!i) ? arr[i] : prefixSum[i-1]+arr[i];
        }

        while (q--){
            scanf("%d %d %d", &li, &ri, &k);

            sum = (long long int) (prefixSum[n-1] - prefixSum[ri-1]);
            if (li-1) sum += (long long int) prefixSum[(li-1)-1];

            sum += (long long int) (ri-li+1)*k;

            printf("%s\n", (sum%2) ? "YES":"NO");
        }
    }

    return 0;
}