/*
    Write a recursive program to remove all odd integers from an array. 
    You must not use any extra array or print anything in the function. 
    Just read input, call the recursive function, then print the array in main().

    Input:
        6
        1 54 88 6 55 7
    Output:
        54 88 6
*/
#include <stdio.h>

int N;

void removeOdds(int i, int j, int arr[]){
    if (i == N){
        N = j;
        return;
    }

    if (arr[i]%2 == 0){
        arr[j] = arr[i];
        j += 1;
    }
    
    removeOdds(i+1, j, arr);
}

int main(){
    scanf("%d", &N);

    int arr[N];
    for (int i=0; i<N; scanf("%d", &arr[i++]));

    removeOdds(0, 0, arr);

    for (int i=0; i<N; printf("%d ", arr[i++]));

    return 0;
}