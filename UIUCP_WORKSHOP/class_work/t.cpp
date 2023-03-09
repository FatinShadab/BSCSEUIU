#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2007;
int CACHE[SIZE][SIZE];
vector <pair<int, int>> items;
int S, N;

// Will get AC and won't get TLE
int knapsackDpSolve(int capacity, int itemIdx){
    if (capacity <= 0 || itemIdx >= N){ // Base case
        return 0;
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

    memset(CACHE, -1, sizeof(CACHE));

    printf("%d\n", knapsackDpSolve(S, 0));

    return 0;
}