#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;

void solve(long long n, long long m){
    long long num = 1;

    while(m){
        num *= n;

        while (num % 10 == 0){
            num = num/10;
        }

        num %= MOD;
        
        n--; m--;
    }

    printf("%lld\n", num%10);

    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;

    while(cin >> n >> m){
        solve(n, m);
    }

    return 0;
}