#include <stdio.h>

int main(){

    int arr_size = 5;
    int arr[] = {2, 4, 6, 5, 3};
    int output[arr_size];

    int current_even_idx = 0;
    int current_odd_idx = 1;

    for (int idx = 0; idx < arr_size; idx++){
        if (arr[idx] % 2 == 0){
            output[current_even_idx] = arr[idx];
            current_even_idx += 2;
        }
        else{
            output[current_odd_idx] = arr[idx];
            current_odd_idx += 2;
        }
    }

    for (int idx = 0; idx < arr_size; idx++){
        printf("%d", output[idx]);
        if (idx < arr_size-1){
            printf(", ");
        }
    }

    return 0;
}