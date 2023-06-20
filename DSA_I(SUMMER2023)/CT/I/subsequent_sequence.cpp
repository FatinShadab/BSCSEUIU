#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

/*
    Find the 1st longest sequence of subsequent numbers
    in an unsorted list after sorting the array.

    Example :
        input  : [6, 8, 7, 2, 5, 1]
        output : [5, 6, 7, 8]
*/

void mergeSort(int *arr, int lb, int ub)
{
    if (lb >= ub)
        return;

    int mid = (lb + ub) / 2;

    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, ub);

    int left_sorted_sub_arr[(mid - lb + 1) + 1];
    int right_sorted_sub_arr[(ub - mid) + 1];

    left_sorted_sub_arr[mid - lb + 1] = INF;
    right_sorted_sub_arr[ub - mid] = INF;

    for (int idx = lb, __idx = 0; idx <= mid; idx++, __idx++)
    {
        left_sorted_sub_arr[__idx] = *(arr + idx);
    }

    for (int idx = mid + 1, __idx = 0; idx <= ub; idx++, __idx++)
    {
        right_sorted_sub_arr[__idx] = *(arr + idx);
    }

    int li = 0, ri = 0;
    for (int idx = lb; idx <= ub; idx++)
    {
        if (left_sorted_sub_arr[li] <= right_sorted_sub_arr[ri])
        {
            arr[idx] = left_sorted_sub_arr[li++];
        }
        else
        {
            arr[idx] = right_sorted_sub_arr[ri++];
        }
    }

    return;
}

int main(int argc, const char **argv)
{
    int arr[] = {5, 4, 3, 2, 1, 12, 11, 10, 9, 8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    int seq_start_idx[arr_size];
    int seq_end_idx[arr_size];

    for (int i = 0, idx = 0; i < arr_size; i++, idx++)
    {
        seq_start_idx[idx] = i;
        seq_end_idx[idx] = i;

        for (int j = i + 1, prev = i; j < arr_size; j++, prev++)
        {
            if (arr[j] - arr[prev] != 1)
            {
                seq_end_idx[idx] = prev;
                break;
            }
            if (j == arr_size - 1)
            {
                seq_end_idx[idx] = j;
            }
        }
    }

    int max_seq_idx = 0;
    for (int i=0; i<arr_size; i++){
        int current_max = seq_end_idx[max_seq_idx]-seq_start_idx[max_seq_idx];
        int possible_max = seq_end_idx[i]-seq_start_idx[i];
        
        if (possible_max > current_max){
            max_seq_idx = i;
        }
    }

    for (int idx=seq_start_idx[max_seq_idx]; idx<=seq_end_idx[max_seq_idx]; idx++){
        printf("%d ", arr[idx]);
    }
    printf("\n");

    return 0;
}