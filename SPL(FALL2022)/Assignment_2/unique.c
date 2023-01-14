#include <stdio.h>

int is_unique(int arr[], int n, int v);

int main(){
    int size;
    scanf("%d", &size);

    int array[size];
    for(int idx=0; idx < size; scanf("%d", &array[idx++]));
        
    for (int idx=0; idx<size; (is_unique(array, size, array[idx])) ? printf("%d ", array[idx++]):idx++);

    return 0;
}

int is_unique(int arr[], int n, int v){
    int freq = 0;

    for (int idx=0; idx<n; idx++){
        if (arr[idx] == v)
            freq++;
    }

    return freq == 1;
}