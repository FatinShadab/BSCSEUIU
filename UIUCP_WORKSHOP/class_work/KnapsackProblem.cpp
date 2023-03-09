/*
    The famous knapsack problem. You are packing for a vacation on the sea side and you are going 
    to carry only one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items 
    that you might want to take with you to the sea side. Unfortunately you can not fit all of them
    in the knapsack so you will have to choose. For each item you are given its size and its value.
    You want to maximize the total value of all the items you are going to bring. What is this
    maximum total value?

    Input
    On the first line you are given S and N. N lines follow with two integers on each line describing
    one of your items. The first number is the size of the item and the next is the value of the item.

    Output
    You should output a single integer on one like - the total maximum value from the best choice of 
    items for your trip.

    Example
        Input:     Output:
        4 5         13
        1 8
        2 4
        3 0
        2 5
        2 3
*/
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2e3 + 10;
int CACHE[SIZE][SIZE];
vector <pair<int, int>> items;
int S, N;

bool cmpLogic(pair<int, int> itemOne, pair<int, int> itemTwo){
    // item.second = item value
    // item.first = item size

    return itemOne.second * itemTwo.first > itemTwo.second * itemOne.first;
}

// Will not get AC for all test case
int knapsackGreedySolve(){
    // item.second = item value
    // item.first = item size
    sort(items.begin(), items.end(), cmpLogic);

    int maxValueGained = 0;
    int capacity = S; // S : size

    for (pair<int, int> item : items){
        //printf("s: %d, v: %d\n", item.first, item.second);
        if (item.first <= capacity){
            maxValueGained += item.second;
            capacity -= item.first;
        }
    }

    return maxValueGained;
}

// Will get AC for all test case but will get TLE
int knapsackBruteForceSolve(int capacity, int itemIdx){
    // item.second = item value
    // item.first = item size

    if (capacity == 0 || itemIdx >= N){
        return 0;
    }

    if (items[itemIdx].first <= capacity){
        int ifTake = items[itemIdx].second + knapsackBruteForceSolve(capacity-items[itemIdx].first, itemIdx+1);
        int ifIgnore = knapsackBruteForceSolve(capacity, itemIdx+1);

        return max(ifTake, ifIgnore);
    }

    else{
        return knapsackBruteForceSolve(capacity, itemIdx+1);
    }
}

// Will get AC and won't get TLE
int knapsackDpSolve(int capacity, int itemIdx){
    if (capacity == 0){ // Base case 1
        return 0;
    }

    if (itemIdx >= N){ // Base case 2
        return 0;
    }

    if (!itemIdx){ // will set the CACHE to -1
        memset(CACHE, -1, sizeof(CACHE));
    }

    int itemValue = items[itemIdx].second;
    int itemSize  = items[itemIdx].first; 

    if (CACHE[itemSize][itemIdx] != -1){ // checks if we already calculated the value
        return CACHE[itemSize][itemIdx];
    }

    if (itemSize <= capacity){
        int ifTake = itemValue + knapsackDpSolve(capacity-itemSize, itemIdx+1);
        int ifIgnore = knapsackDpSolve(capacity, itemIdx+1);

        return CACHE[itemSize][itemIdx] = max(ifTake, ifIgnore);
    }

    else{
        return CACHE[itemSize][itemIdx] = knapsackDpSolve(capacity, itemIdx+1);
    }
}

int main(){
    int temp_s, temp_v;
    scanf("%d %d", &S, &N);

    for (int i=0; i<N; i++){
        scanf("%d %d", &temp_s, &temp_v);
        items.push_back(make_pair(temp_s, temp_v));
    }

    printf("Greedy solve : %d\n", knapsackGreedySolve());
    printf("Brute Force solve : %d\n", knapsackBruteForceSolve(S, 0));
    printf("DP solve : %d\n", knapsackDpSolve(S, 0));

    return 0;
}