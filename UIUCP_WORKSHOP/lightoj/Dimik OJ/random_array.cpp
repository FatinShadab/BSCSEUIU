#include <bits/stdc++.h>

using namespace std;

int main(){
    int tcases;
    cin>>tcases;

    while(tcases--){
        int array_size;
        cin>>array_size;

        int arr[array_size];

        for (int idx=0; idx < array_size; idx++){
            cin>>arr[idx];
        }

        if (is_sorted(arr, arr+array_size) || is_sorted(arr, arr+array_size, greater<int>())){
            cout <<"YES" <<endl;
        }
        else{
            cout <<"NO" <<endl;
        }

    }

    return 0;
}