/*
    Find out the maximum and minimum element of a given array using Divide and Conquer.
*/

#include <bits/stdc++.h>

using namespace std;

struct MinMax {
    int minimum;
    int maximum;
};

MinMax find_min_max(int arr[], int lb, int ub) {
    MinMax result;

    if (lb == ub) { // the array has only one element
        result.maximum = result.minimum = arr[lb];
        return result;
    }

    int mid = lb + ((ub - lb) >> 1);

    MinMax minMaxOfLeftSubTree = find_min_max(arr, lb, mid);
    MinMax minMaxOfRightSubTree = find_min_max(arr, mid+1, ub);

    result.minimum = (minMaxOfLeftSubTree.minimum < minMaxOfRightSubTree.minimum) ? minMaxOfLeftSubTree.minimum : minMaxOfRightSubTree.minimum;
    result.maximum = (minMaxOfLeftSubTree.maximum > minMaxOfRightSubTree.maximum) ? minMaxOfLeftSubTree.maximum : minMaxOfRightSubTree.maximum;

    return result;
}

int main() {

    int arr[] = {2, 5, 7, 8, 12, 15, 9, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax minMax = find_min_max(arr, 0, n-1);

    cout << "Max : " << minMax.maximum << ", Min : " << minMax.minimum << "\n";

    return 0;
}