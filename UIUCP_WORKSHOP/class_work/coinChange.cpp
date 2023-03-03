#include<bits/stdc++.h>
using namespace std;


const int INF = 0x7f7f7f7f;

int cache[10001];

int coinChange(int amount, int coins[], int n)
{
    if(cache[amount]!=-1) return cache[amount];

    int result = INF;

    for(int i=0; i<n; i++)
    {
        if(coins[i]<=amount)
        {
            result = min(result, 1 + coinChange(amount-coins[i], coins, n));
        }
    }
    cache[amount] = result;
    return cache[amount];
}

int coinChangeAllPossibleDP(int amount, int coins[], int i, int n)
{

    if(cache[amount]!=-1) return cache[amount];

    if(amount==0) return 0;
    if(i==n) return INF;

    if(coins[i]<=amount)
    {
        int branch1 = 1 + coinChangeAllPossibleDP(amount-coins[i], coins, i, n);
        int branch2 = coinChangeAllPossibleDP(amount, coins, i+1, n);
        return cache[amount] = min(branch1, branch2);
    }
    else
        return cache[amount] = coinChangeAllPossibleDP(amount, coins, i+1, n);
}



int coinChangeAllPossible(int amount, int coins[], int i, int n)
{
    if(amount==0) return 0;
    if(i==n) return INF;


    if(coins[i]<=amount)
    {
        int branch1 = 1 + coinChangeAllPossible(amount-coins[i], coins, i, n);
        int branch2 = coinChangeAllPossible(amount, coins, i+1, n);
        return min(branch1, branch2);
    }
    else
        return coinChangeAllPossible(amount, coins, i+1, n);
}

int coinChangeGreedy(int amount, int coins[], int n)
{
    sort(coins, coins+n, greater<int>());

    int amountOfCoins = 0;

    for(int i=0; i<n; i++)
    {
        if(coins[i]<=amount)
        {
            int koytaNitePari = amount/coins[i];
            amount -= (koytaNitePari*coins[i]);
            amountOfCoins+=koytaNitePari;
        }
    }
    return amountOfCoins;

}
int main()
{
    int coins[4] = {357,239,73,52};
    int amount = 9832;

    /**cout << coinChangeGreedy(amount, coins, 3) << endl;
    cout << coinChangeAllPossible(amount, coins, 0, 3) << endl;**/


    memset(cache, -1, sizeof(cache));
    cache[0] = 0;
    cout << coinChange(amount, coins, 4) << endl;



    //cout << coinChangeAllPossibleDP(amount, coins, 0, 4) << endl;

    cout << coinChangeAllPossible(amount, coins, 0, 4) << endl;
    return 0;

}
