// Problem Link : https://vjudge.net/contest/544590?fbclid=IwAR1stOHEIoWUKzwkBHaxzxjQUNmRNjGF-4tujotFQcGsQpvfIfeh9WXP2IY#problem/C

// gives TLE
#include <bits/stdc++.h>
using namespace std;
#define __fastIO__  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e5;
int arr[N];
long long int prefixArr[N];

int goodSubArrayQuantity(const int n){
    int quantity = 0;
    
    int len = 1;

    while (len <= n){
        int l = 0;
        while (l <= n-len){
            //printf("%lld - %lld + %d\n", prefixArr[l+(len-1)], prefixArr[l], arr[l]);
            if ((prefixArr[l+(len-1)] - prefixArr[l] + arr[l]) == len){
                quantity++;
            }

            l ++;
        }

        //printf("\t%d good subarray found when len : %d\n", quantity, len);
        len++;
    }

    
    return quantity;
}

int main(){
    __fastIO__

    int T, n;
    string temp;

    cin >> T;

    while (T--){
        cin >> n;
        cin>>temp;
        for (int i=0; i< n; i++){
            arr[i] = (int) temp[i] - '0';
            if (!i){
                prefixArr[i] = arr[i];
            } else {
                prefixArr[i] = arr[i] + prefixArr[i-1];
            }
        }
        printf("%d\n", goodSubArrayQuantity(n));
    }

    return 0;
}