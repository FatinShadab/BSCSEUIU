// PB LINK : https://codeforces.com/problemset/problem/1760/A

#include <stdio.h>
#define INF 100

void mergeSort(int* arr, int lb, int ub) {

    if (lb >= ub) return;

    int mid = (lb + ub) / 2;

    mergeSort(arr, lb, mid);
    mergeSort(arr, mid+1, ub);

    int left_sorted_sub_arr[(mid-lb+1)+1];
    int right_sorted_sub_arr[(ub-mid)+1];

    left_sorted_sub_arr[mid-lb+1] = INF;
    right_sorted_sub_arr[ub-mid] = INF;
    
    for (int idx=lb, __idx=0; idx <= mid; idx++, __idx++){
        left_sorted_sub_arr[__idx] = *(arr+idx);
    }
    
    for (int idx=mid+1, __idx=0; idx <= ub; idx++, __idx++){
        right_sorted_sub_arr[__idx] = *(arr+idx);
    }
    
    int li = 0, ri = 0;
    for (int idx=lb; idx <= ub; idx++){
        if (left_sorted_sub_arr[li] <= right_sorted_sub_arr[ri]){
            arr[idx] = left_sorted_sub_arr[li++];
        }
        else{
            arr[idx] = right_sorted_sub_arr[ri++];
        }
    } 

    return;
}

int main(){
    int T; scanf("%d", &T);
    int arr[3];

    while (T--){
        
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

        mergeSort(arr, 0, 2);

        printf("%d\n", arr[1]);
    }

    return 0;
}