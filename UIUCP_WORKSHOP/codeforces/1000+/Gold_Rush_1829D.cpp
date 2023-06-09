// PB Link : https://codeforces.com/problemset/problem/1829/D

#include <bits/stdc++.h>
using namespace std;
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

bool can_make(int n, int m){
    if (n == 0) return false;
    if (m > n) return false;
    if (n == m) return true;
    if (n%3) return false;

    return can_make(n/3, m) || can_make((2*n)/3, m);
}

void solve(){
    int n, m;
    cin >> n >> m;

    (can_make(n, m)) ? cout << "YES\n":cout << "NO\n";

    return;
}

int main(){
    __fastIO__

    int T; cin >> T;
    
    while (T--){
        solve();
    }
    
    return 0;
}