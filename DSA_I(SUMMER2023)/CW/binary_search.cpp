#include <bits/stdc++.h>
using namespace std;
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
    Implement the binary search that will return the
    index of the element if found else return -1
*/

int binary_search(int target, int lb, int ub, int arr[]){
    if (lb > ub) return -1;

    int mid = (lb + ub)/2;
    
    if (target < arr[mid]) return binary_search(target, lb, mid-1, arr);
    if (target > arr[mid]) return binary_search(target, mid+1, ub, arr);

    return mid;
}

int main(){
    __fastIO__

    int arr[] = {7, 8, 10, 12, 18, 20};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int target = 11;

    (binary_search(target, 0, arr_size-1, arr) == -1) ? cout << "Not Found\n": cout << "Found\n";

    return 0;
}