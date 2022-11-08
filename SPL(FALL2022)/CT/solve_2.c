/*
You have to init an array with some elements.

The output will be the same length array where
each element will have the product of all the elements of
the given array except the element at that index. 

For example:
input:           output:
1, 2, 3, 4       24, 12, 8, 6
*/
#include <stdio.h>

int main(){
    int arr[] = {100, 0, 200, 300};
    int n = 4;
    int output[n];

    printf("INPUT : ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    for(int i=0; i<n; i++){
        int product = 1;
        for (int j=0; j<4; j++){
            if (j != i){
                product *= arr[j];
            }
        }
        output[i] = product;
    }

    printf("\nOUTPUT : ");
    for (int i=0; i<n; i++){
        printf("%d ", output[i]);
    }

    return 0;
}