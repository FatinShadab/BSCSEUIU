/*
Find the min and max value from a given array.
*/
#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4, 7, 6, 8, 0, 9, -1};

    int min = arr[0];
    int max = arr[0];

    for (int i=0; i < 10; i++){
        if (min > arr[i]){
            min = arr[i];
        }
        if (max < arr[i]){
            max = arr[i];
        }
    }

    printf("MIN : %d, MAX : %d", min, max);

    return 0;
}