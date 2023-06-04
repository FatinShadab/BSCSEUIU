// PB Link : https://vjudge.net/contest/561667#problem/C

#include <bits/stdc++.h>
using namespace std;
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    __fastIO__
    int T; cin >> T;
    string ab_string;

    while (T--){
        bool can_build = true;

        cin >> ab_string;

        for (int idx = 0; idx < ab_string.length(); idx++){
            bool valid = false;
            int prev_idx = idx - 1;
            int next_idx = idx + 1;

            if (prev_idx >= 0){
                if (ab_string[prev_idx] == ab_string[idx]){
                    valid = true;
                }
            }

            if (next_idx <= ab_string.length()-1){
                if (ab_string[next_idx] == ab_string[idx]){
                    valid = true;
                }
            }

            can_build = valid;

            if (!can_build){
                break;
            }
        }
    
        (can_build) ? cout<<"YES\n":cout<<"NO\n";
    }

    return 0;
}