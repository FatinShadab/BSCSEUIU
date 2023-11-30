/*
    Solve of Coin Change problem : Brute Force Approach [Always get's the correct answer].

    Coin Change problem : you are given an array of coins with varying denominations and an
    integer sum representing the total amount of money. You must return the fewest coins
    required to make up that sum; if that sum cannot be constructed, return -1.
*/
#include <bits/stdc++.h>
#define NOT_SET -1

using namespace std;

int coinChangeNaive(const vector<int> coins, int amount) {
    if (amount == 0) return amount;

    int minCoinsToCompleteAmount = NOT_SET;

    for (int coin : coins) {
        if (coin > amount) continue;

        int remainingAmount = amount - coin;
        int coinsNeededForRemainingAmount = coinChangeNaive(coins, remainingAmount);
        int coinsNeededForAmount = coinsNeededForRemainingAmount + 1;

        if (minCoinsToCompleteAmount == NOT_SET) minCoinsToCompleteAmount = coinsNeededForAmount;
        else minCoinsToCompleteAmount = (minCoinsToCompleteAmount > coinsNeededForAmount) ? coinsNeededForAmount:minCoinsToCompleteAmount; 
    }

    return minCoinsToCompleteAmount;
}


int main() {

    vector <int> coins{25, 10, 1};
    int amount = 30;

    cout << "Total Number of Coins: " << coinChangeNaive(coins, amount) << endl;

    return 0;
}