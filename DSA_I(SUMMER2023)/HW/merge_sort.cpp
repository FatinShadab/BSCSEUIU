#include <bits/stdc++.h>
using namespace std;
#define lineBreak printf("\n");
#define lineBreak2 printf("\n\n");
#define INF 1000000000

void mergeSort(int* arr, int lb, int ub){
    // Un Comment to debug
    // Devide Part 

    // debug block : 1
    // shows the devided sub array
    // printf("Devide: lb->%d, ub->%d\n", lb, ub);
    // printf("\tArray : ");
    // for(int idx=lb; idx <= ub; idx++){
    //     printf("%d ", *(arr+idx));
    // }
    // lineBreak

    if (lb >= ub) return;

    int mid = (lb + ub) / 2;

    mergeSort(arr, lb, mid);
    mergeSort(arr, mid+1, ub);

    // Conquer Part
    int left_sorted_sub_arr[(mid-lb+1)+1];
    int right_sorted_sub_arr[(ub-mid)+1];

    left_sorted_sub_arr[mid-lb+1] = INF;
    right_sorted_sub_arr[ub-mid] = INF;
    
    // create and shows the left sub array
    //printf("Unsorted Left Sub Array : ");
    for (int idx=lb, __idx=0; idx <= mid; idx++, __idx++){
        left_sorted_sub_arr[__idx] = *(arr+idx);
        //printf("%d ", left_sorted_sub_arr[__idx]);
    }
    //lineBreak
    
    // create and shows the right sub array
    //printf("Unsorted Right Sub Array : ");
    for (int idx=mid+1, __idx=0; idx <= ub; idx++, __idx++){
        right_sorted_sub_arr[__idx] = *(arr+idx);
        //printf("%d ", right_sorted_sub_arr[__idx]);
    }
    //lineBreak
    
    int li = 0, ri = 0;
    for (int idx=lb; idx <= ub; idx++){
        if (left_sorted_sub_arr[li] <= right_sorted_sub_arr[ri]){
            arr[idx] = left_sorted_sub_arr[li++];
        }
        else{
            arr[idx] = right_sorted_sub_arr[ri++];
        }
    } 
    
    // debug block : 2
    // shows the sorted sub array
    //printf("Conquer: lb->%d, ub->%d, mid->%d\n", lb, ub, mid);
    //printf("Sorted & Merged SUB Array : ");
    //for(int idx=lb; idx <= ub; idx++){
    //    printf("%d ", *(arr+idx));
    //}
    //lineBreak2

    return;
}

int main(){
    int arr[] = {10, 4, 1, 2, 5, 3, 7, 8, 6, 9, 0, 0, 1, 2, 1};
    //int arr[] = {1, 0 , 1, 2, 1};
    //int arr[] = {0, 0, 0};
    //int arr[] = {1};
    //int arr[] = {2, 1, 4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Before Sorting : ");
    for (int ele : arr){
        printf("%d ", ele);
    }

    lineBreak2

    mergeSort(arr, 0, arr_size-1);

    printf("After Sorting : ");
    for (int ele : arr){
        printf("%d ", ele);
    }

    return 0;
}