// Problem Link : https://vjudge.net/contest/564816#problem/L

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
// gives Runtime error (SIGKILL)

const int MAX_SIZE = 2000001;
const int MAX_ELEMENTS = 501;

vector<vector<ll>> CACHE(MAX_SIZE, vector<ll>(MAX_ELEMENTS, -1));
int element_weights[MAX_ELEMENTS];
int element_values[MAX_ELEMENTS];

ll knapsackRecursiveDP(int k, int n) {
    if (k == 0 || n == 0) return 0;

    if (CACHE[k][n] != -1) return CACHE[k][n];

    if (element_weights[n] > k)
        return CACHE[k][n] = knapsackRecursiveDP(k, n - 1);
    else
        return CACHE[k][n] = max(knapsackRecursiveDP(k, n - 1), element_values[n] + knapsackRecursiveDP(k - element_weights[n], n - 1));
}

int main() {
    int k, n; scanf("%d %d", &k, &n);

    for (int i = 1; i <= n; i++) scanf("%d %d", &element_values[i], &element_weights[i]);
    
    printf("%lld\n", knapsackRecursiveDP(k, n));

    return 0;
}
*/

const int MAX_SIZE = 2000001;
const int MAX_ELEMENTS = 501;

ll CACHE[MAX_SIZE];
int element_weights[MAX_ELEMENTS];
int element_values[MAX_ELEMENTS];

ll knapsack(int k, int n) {
    for (int i = 0; i <= k; i++) {
        CACHE[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int element_weight = element_weights[i];
        int element_value = element_values[i];

        for (int j = k; j >= element_weight; j--) {
            CACHE[j] = max(CACHE[j], CACHE[j - element_weight] + element_value);
        }
    }

    return CACHE[k];
}

int main() {
    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= n; i++) {
        cin >> element_values[i] >> element_weights[i];
    }

    cout << knapsack(k, n) << endl;

/*     for (int i=1; i<=k; i++){
        printf("%d %lld\n", i, CACHE[i]);
    } 
*/

    return 0;
}
