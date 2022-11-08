/*
Init an array of size 10 where each element is an int having the value
10. Then put 20 in the even indices and 30 in the odd indices.
*/
#include <stdio.h>

int main(){
    int arr[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    printf("Array before the task : ");
    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }

    for (int i=0; i<10; i++){
        if (i%2 == 0) arr[i] = 20;
        else arr[i] = 30;
    }

    printf("\nArray After the task : ");
    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}