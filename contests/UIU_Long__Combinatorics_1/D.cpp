// PB Link : https://vjudge.net/contest/561093?fbclid=IwAR0mAKGKvcRnald64QWvLWCvAs_uIIXeHrMCL04sP0bAiUqIHRefuVVlg_k#problem/D

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define ll unsigned long long int
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

ll cache[MAX_N][MAX_N];

ll nCr(int n, int r){
    if (r > n){
        return 0;
    }
    if (n == r || r == 0){
        return 1;
    }

    if (cache[n][r] == 0){
        cache[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
    }

    return cache[n][r];
}

int main(){
    __fastIO__

    int inputs[2];
    string line, chunk;

    while(1){
        int idx = 0;

        getline(cin, line);
        stringstream line_chunks(line);

        while(getline(line_chunks, chunk, ' ')){
            if (chunk.length()){
                inputs[idx++] = stoi(chunk);
            }
        }

        if (inputs[0] == 0 && inputs[1] == 0){
            break;
        }

        cout << inputs[0] << " things taken " << inputs[1] << " at a time is " <<  nCr(inputs[0], inputs[1]) << " exactly.\n";

    }

    return 0;
}