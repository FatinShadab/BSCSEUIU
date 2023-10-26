/*
    Find the minimum and maximum element from an array 
    using one recursive function.
*/

#include <bits/stdc++.h>

using namespace std;

void min_max(int *arr, int i, int n, int *min, int *max) {
    if (i >= n) return;

    if (*(min) > arr[i]) *(min) = arr[i];
    if (*(max) < arr[i]) *(max) = arr[i];

    min_max(arr, i+1, n, min, max);
}

int main() {
    int arr[] = {0, 1, 3, 2, 6, 5};

    int min = INT_MAX, max = INT_MIN;

    min_max(arr, 0, sizeof(arr)/sizeof(arr[0]), &min, &max);

    cout << "Min : " << min << ", Max : " << max << "\n";

    return 0;
}