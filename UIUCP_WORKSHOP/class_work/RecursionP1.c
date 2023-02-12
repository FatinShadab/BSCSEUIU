/*
    You will be given an array of integers, 
    write a recursive solution to print it in 
    reverse order.

    Input:
        5
        69 87 45 21 47
    Output:
        47 21 45 87 69
*/
#include <stdio.h>

void reversePrint(int n, int arr[]){
    if (n == 0){
        return;
    }

    printf("%d ", arr[n-1]);

    reversePrint(n-1, arr);
}

int main(){
    int N;
    scanf("%d", &N);

    int ARR[N];
    for (int idx=0; idx<N; scanf("%d", &ARR[idx++]));

    reversePrint(N, ARR);

    return 0;
}