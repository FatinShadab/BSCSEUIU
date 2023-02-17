/*
    Problem link : https://cses.fi/problemset/task/1646
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    int inputArr[n];
    long long int prefixArr[n];

    for (int i=0; i<n; i++){
        cin>>inputArr[i];
        if (i == 0){
            prefixArr[i] = inputArr[i];
        }else{
            prefixArr[i] = inputArr[i] + prefixArr[i-1];
        }
    }

    while (q--){
        int l, r;
        cin>>l>>r;
        l -= 1;
        r -= 1;

        cout<<prefixArr[r] - prefixArr[l] + inputArr[l]<<endl;
    }

    return 0;
}