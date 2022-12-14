#include <bits/stdc++.h>

using namespace std;

int sub_set_sum(int arr[], int lb, int ub);

int main(){

    int number_of_coins;
    scanf("%d", &number_of_coins);

    int coins[number_of_coins];
    for(int idx=0; idx<number_of_coins; scanf("%d", &coins[idx++]));

    sort(coins, coins+number_of_coins);

    int idx = number_of_coins-1;

    int twin1 = 0;
    int twin2 = INT_MAX;

    int coin_took = 0;

    while (twin1 <= twin2){
        twin1 += coins[idx];
        twin2 = sub_set_sum(coins, 0, idx--);

        coin_took++;
    }

    printf("%d\n", coin_took);

    return 0;
}

int sub_set_sum(int arr[], int lb, int ub){
    int sum = 0;

    for (int idx=lb; idx<ub; sum+=arr[idx++]);

    return sum;
}