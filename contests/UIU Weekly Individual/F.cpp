// PB Link : https://vjudge.net/contest/561667#problem/F

#include <bits/stdc++.h>
using namespace std;
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

int get_minimum_op(int arr[], const int arr_size){
    int op_count = 0;

    for (int idx = arr_size - 2; idx >= 0; idx--){
        int selected_ele = arr[idx];
        int next_ele = arr[idx+1];
        
        while (selected_ele >= next_ele){
            if (selected_ele == 0) return -1;
            selected_ele /= 2;
            op_count++;
        }

        arr[idx] = selected_ele;
    }

    return op_count;
}

int main(){
    int T; cin >> T;

    while (T--){
        int n; cin >> n;
        int arr[n]; for (int i=0; i<n; cin >> arr[i++]);

        cout << get_minimum_op(arr, n) << "\n";
    }
    
    return 0;
}
