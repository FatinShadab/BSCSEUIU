/*
        For 2C1 the call stack will be looking something like below,

            (if don't take)

                       /-----> 1C1  (base case 1: n == r)
                (1+1) / <----- 1
            2C1 ------
                      \ <----- 1
                       \-----> 1C0  (base case 2: r == 0)

             (if take)

        
        So, we can say, 2C1 = 1C1 + 1C0
                    or, nCr = (n-1)Cr  +  (n-1)C(r-1)


        For 4C2 the call stack will be looking something like below,



            (if don't take)
                                                   /--------> 2C2
                                                  /<-------(1)
                           /--------> 3C2 --------
                          /<--------------(1 + 2) \<-------------(1 + 1)  /--------> 1C1
                         /                         \--------> 2C1 --------
                (3 + 3) /                                                 \--------> 1C0
            4C2 --------
                        \                                                 /--------> 1C1
                         \                         /--------> 2C1 --------
                          \ <-------------(1 + 2) /<-------------(1 + 1)  \--------> 1C0
                           \--------> 3C1 --------
                                                  \<-------(1)
                                                   \--------> 2C0

               (if take)

        Again, nCr = (n-1)Cr  +  (n-1)C(r-1)

            4C2 = 3C2 + 3C1
                = (2C2 + 2C1) + (2C1 + 2C0)
                = (1 + (1C1 + 1C0)) + ((1C1 + 1C0) + 1) [if n==r || r==0, nCr = 1]
                = (1 + (1 + 1)) + ((1 + 1) + 1)   [if n==r || r==0, nCr = 1]
                = (1 + 2) + (2 + 1)
                = 3 + 3
                = 6


        *** Optimization : USE DP
*/

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_N 10000
#define ll long long

ll CACHE[MAX_N][MAX_N];

ll nCr(ll n, ll r){

    // base case
    if (n == r || r == 0){
        return 1;
    }

    // check if the answer was previously calculated
    if (CACHE[n][r]){
        // if so, then return the previous answer
        return CACHE[n][r];
    }

    // otherwise, calculate the answer and store it
    CACHE[n][r] = nCr(n-1, r-1) + nCr(n-1, r);

    // return the calulated answer
    return CACHE[n][r];
}

int main(){

    __fastIO__    // <-- For fast input/output

    ll n, r;

    cin >> n >> r;

    cout<<nCr(n, r)<<"\n";

    return 0;
}