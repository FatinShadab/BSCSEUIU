#include <bits/stdc++.h>
using namespace std;

/*
    Find the target number inside an array, if the number
    is not found return the immediate larger one.
*/

int binary_search_extened(int target, int lb, int ub, int arr[]){
    if (lb > ub) return lb;

    int mid = (lb + ub)/2;

    if (target < arr[mid]) return binary_search_extened(target, lb, mid-1, arr);
    if (target > arr[mid]) return binary_search_extened(target, mid+1, ub, arr);

    return mid;
}

int main(){
    int arr_size;
    cout << "Enter the array size : ";
    cin >> arr_size;

    int arr[arr_size];
    cout << "Enter the array elements : ";
    for(int idx = 0; idx < arr_size; cin >> arr[idx++]);

    int target;
    cout << "Enter the target value : ";
    cin >> target;

    int target_element_idx = binary_search_extened(target, 0, arr_size-1, arr);
    
    if (target_element_idx >= arr_size){
        cout << target <<" not found and next large doesn't exist!\n";
    }
    else if (arr[target_element_idx] == target){
        cout << target << " found at index " << target_element_idx << "\n";
    }
    else if (arr[target_element_idx] != target){
        cout << target << " not found next large element " << arr[target_element_idx] << " at index " << target_element_idx << "\n";
    }

    return 0;
}