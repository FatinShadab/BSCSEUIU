#include <stdio.h>

int main(){
    int array_size = 4;
    int arr[] = {1, 3, 2, 0};

    printf("The input array : ");
    for (int i=0; i < array_size; i++){
        printf("%d ", arr[i]);
    }

    int idx = 0;
    while (idx < array_size){
        if (idx != arr[idx]){
            int temp_val = arr[idx];
            arr[idx] = idx;
            arr[temp_val] = temp_val;
        }
        idx++;
    }

    printf("\nThe output array : ");
    for (int i=0; i < array_size; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}