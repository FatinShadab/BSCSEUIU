#include <stdio.h>

int lowest_value_idx(int size, int arr[]){
    int min_idx = 0;

    for (int i=0; i<size; i++){
        if (arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    return min_idx;
}

int main(){
    int numOftvs;
    int capacity;
    int earning = 0;

    scanf("%d %d", &numOftvs, &capacity);
    int tvs[numOftvs];

    for (int i=0; i<numOftvs; i++){
        scanf("%d", &tvs[i]);
    }

    for (int i=0; i<capacity; i++){
        int idx = lowest_value_idx(numOftvs, tvs);
        if (tvs[idx] < 0){
            earning += (-1*tvs[idx]);
            tvs[idx] = 0;
        }
    }

    printf("%d", earning);
    
    return 0;
}