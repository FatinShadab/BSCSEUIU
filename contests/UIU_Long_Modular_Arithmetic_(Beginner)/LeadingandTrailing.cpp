#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bigMod(ll base, ll pow, ll mod){
    if (pow == 0) return 1;
    if (pow == 1) return base;

    ll res = bigMod(base, pow/2, mod);

    res = (res * res) % mod;

    if (pow & 1) res = (res * base%mod) % mod;

    return res;

}

void solve(){
    ll base, power;
    scanf("%lld %lld", &base, &power);
    
    long double logTransPower = (double) power * log10(base);
    int first_3_digit = (pow(10, (logTransPower - floor(logTransPower))) * 100.0);

    printf("%d...", first_3_digit);

    int last_3_digit = bigMod(base, power, 1000);

    if (last_3_digit < 100){
        if (last_3_digit < 10){
            printf("00%d\n", last_3_digit);
        }else{
            printf("0%d\n", last_3_digit);
        }
    }else{
        printf("%d\n", last_3_digit);
    }

    return;
}

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        solve();
    }

    return 0;
}