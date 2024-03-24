#include <bits/stdc++.h>

using namespace std;

int minimum_weight_diff(int stones[], int size, int current_stone, int left_pile, int right_pile) {
    if (current_stone == size) return abs(left_pile - right_pile);

    int ifPutInLeftPile = minimum_weight_diff(stones, size, current_stone+1, left_pile + stones[current_stone], right_pile);
    int ifPutInRightPile = minimum_weight_diff(stones, size, current_stone+1, left_pile, right_pile + stones[current_stone]);

    return min(ifPutInLeftPile, ifPutInRightPile);
}

int main() {
    int n; cin >> n;
    int stones[n]; for (int i=0; i<n; cin >> stones[i++]);

    printf("%d\n", minimum_weight_diff(stones, n, 0, 0, 0));

    return 0;
}