#include <stdio.h>

int main(){

    int arr_size = 6;
    int arr[] = {6, 8, 4, 3, 5, 7};
    int output[arr_size];

    int current_even_idx = 0;
    int current_odd_idx = 1;
    int idx = 0;

    printf("The input array : ");
    for (int idx = 0; idx < arr_size; idx++){
        printf("%d", arr[idx]);
        if (idx < arr_size-1){
            printf(", ");
        }
    }
    printf("\n");

    while (idx < arr_size){
        if (arr[idx] % 2 == 0){
            output[current_even_idx] = arr[idx];
            current_even_idx += 2;
        }
        else{
            output[current_odd_idx] = arr[idx];
            current_odd_idx += 2;
        }

        idx++;
    }

    printf("The output array : ");
    for (int idx = 0; idx < arr_size; idx++){
        printf("%d", output[idx]);
        if (idx < arr_size-1){
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}