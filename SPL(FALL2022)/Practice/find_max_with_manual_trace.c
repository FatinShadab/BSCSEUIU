#include <stdio.h>

int main(){
    printf("\n---------------- Input --------------------- ");
    int size; printf("\nEnter the array size : "); scanf("%d", &size);
    int arr[size];

    printf("\nEnter the all %d elements : ", size);
    for (int i=0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int max_idx = 0;
    printf("\n--------------Manual Tracing-----------------");
    printf("\n|-------------------------------------------|\n");
    printf("|  i  |  a[i]  |  arr[max_idx]  |  max_idx  |\n");
    printf("|-------------------------------------------|\n");
    for (int i=0; i < size; i++){
        printf("|  %d  |   %d    |        %d       |      %d    |\n", i, arr[i], arr[max_idx], (arr[i] > arr[max_idx]) ? i:max_idx);
        if (arr[i] > arr[max_idx]){
            max_idx = i;
        }
    }
    printf("|-------------------------------------------|\n");

    printf("\n--------------- Output ------------------- ");
    printf("\nThe max index is : %d and element is : %d\n", max_idx, arr[max_idx]);

    return 0;
}