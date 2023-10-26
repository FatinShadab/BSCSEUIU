/*
    Find out the maximum sum subarray using Divide and Conquer.
*/

#include <bits/stdc++.h>

using namespace std;


class SubArrayMaxSum {
    public:
        int sum;
        int lb, ub;

    public:
        SubArrayMaxSum() {}

        SubArrayMaxSum(int sum, int lb, int ub) {
            this->set(sum, lb, ub);
        }

        void set(SubArrayMaxSum obj) {
            this->sum = obj.sum;
            this->lb = obj.lb;
            this->ub = obj.ub;
        }

        void set(int sum, int lb, int ub) {
            this->sum = sum;
            this->lb = lb;
            this->ub = ub;
        }
};


SubArrayMaxSum find_crossing_sum(int arr[], int lb, int mid, int ub){
    SubArrayMaxSum crossingMaxSum = SubArrayMaxSum(-1, -1, -1);

    int maxFromLeftSide = arr[mid];
    int lastTakenIdxOfLeftSide = mid;

    for (int idx = mid - 1; idx >= lb; idx--) {
        int checkSum = maxFromLeftSide + arr[idx];

        if (checkSum > maxFromLeftSide) {
            maxFromLeftSide = checkSum;
            lastTakenIdxOfLeftSide = idx;
        }
    }

    int maxFromRightSide = arr[mid + 1];
    int lastTakenIdxOfRightSide = mid + 1;

    for (int idx = mid + 2; idx <= ub; idx++) {
        int checkSum = maxFromRightSide + arr[idx];

        if (checkSum > maxFromRightSide) {
            maxFromRightSide = checkSum;
            lastTakenIdxOfRightSide = idx;
        }
    }

    crossingMaxSum.set(maxFromLeftSide + maxFromRightSide, lastTakenIdxOfLeftSide, lastTakenIdxOfRightSide);
    
    return crossingMaxSum;
}

SubArrayMaxSum find_max_sub_array_sum(int arr[], int lb, int ub) {
    SubArrayMaxSum subArrayMaxSum = SubArrayMaxSum(-1, -1, -1);

    if (lb == ub) {
        subArrayMaxSum.set(arr[lb], lb, ub);
        return subArrayMaxSum;
    }

    int mid = lb + ((ub - lb) >> 1);

    SubArrayMaxSum subArrayMaxSumOfLeftSubTree = find_max_sub_array_sum(arr, lb, mid);
    SubArrayMaxSum subArrayMaxSumOfRightSubTree = find_max_sub_array_sum(arr, mid + 1, ub);
    SubArrayMaxSum crossingMaxSumOfTreeLevel = find_crossing_sum(arr, lb, mid, ub);

    if (subArrayMaxSumOfLeftSubTree.sum > subArrayMaxSumOfRightSubTree.sum) {
        subArrayMaxSum.set(subArrayMaxSumOfLeftSubTree);
    }
    else {
        subArrayMaxSum.set(subArrayMaxSumOfRightSubTree);
    }

    if (crossingMaxSumOfTreeLevel.sum > subArrayMaxSum.sum) {
        subArrayMaxSum.set(crossingMaxSumOfTreeLevel);
    }

    return subArrayMaxSum;
}


int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "The Given Array : Arr[0, " <<arrSize-1 << "] -> ";
    for (int idx = 0; idx < arrSize; cout << arr[idx++] << " ");

    SubArrayMaxSum subArrayMaxSum = find_max_sub_array_sum(arr, 0, arrSize - 1);

    cout << "\nMax Sub-Array Sum : Arr["<<subArrayMaxSum.lb <<", "<< subArrayMaxSum.ub << "] -> ";
    for (int idx = subArrayMaxSum.lb; idx <= subArrayMaxSum.ub; idx++) {
        cout << "(" << arr[idx] << ")";

        if (idx < subArrayMaxSum.ub) {
            cout << " + ";
        }
        else {
            cout << " = ";
        }
    }
    cout << subArrayMaxSum.sum << "\n";

    return 0;
}