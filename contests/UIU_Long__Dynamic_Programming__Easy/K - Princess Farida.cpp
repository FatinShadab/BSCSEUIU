// Problem Link : https://vjudge.net/contest/564816#problem/K

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e4 + 1;
ll CACHE[MAX_N];

ll get_max_coins(int monser_no, int coins[], int coin_arr_max_idx){
    if (monser_no > coin_arr_max_idx){
        return 0;
    }

    if (CACHE[monser_no] != -1){
        return CACHE[monser_no];
    }

    ll if_take_coin_from_current_monster = get_max_coins(monser_no+2, coins, coin_arr_max_idx) + coins[monser_no];
    ll if_don_not_take_coin_from_current_monster = get_max_coins(monser_no+1, coins, coin_arr_max_idx);
    
    return CACHE[monser_no] = max(if_take_coin_from_current_monster, if_don_not_take_coin_from_current_monster);
}

void solve(int test_case){
    int number_of_monsters;
    scanf("%d", &number_of_monsters);

    int monster_coins[number_of_monsters+1];
    for (int monster_no = 1; monster_no <= number_of_monsters; scanf("%d", &monster_coins[monster_no++]));

    printf("Case %d: %lld\n", test_case, get_max_coins(1, monster_coins, number_of_monsters));
}

int main(){
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++){
        for (int i = 0; i <= MAX_N; CACHE[i++] = -1);
        solve(test_case);
    }

    return 0;
}