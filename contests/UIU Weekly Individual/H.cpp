// PB Link : https://vjudge.net/contest/561667#problem/H

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main(){
    int n, m; cin >> n >> m;
    
    vector <ll> dormitory;

    for (int i=0; i<n; i++){
        ll rooms; cin >> rooms;
        dormitory.push_back((i) ? rooms + dormitory[i-1] : rooms);
    }

    //for (auto ele : dormitory){
    //    cout << ele << " ";
    //}

    while (m--){
        ll room_number; cin >> room_number;

        ll dormitory_number = lower_bound(dormitory.begin(), dormitory.end(), room_number) - dormitory.begin() + 1;
        ll dormitory_room_number = (dormitory_number == 1) ? room_number : room_number - dormitory[dormitory_number-2];
        
        cout << dormitory_number << " " << dormitory_room_number << "\n";
    }

    return 0;
}