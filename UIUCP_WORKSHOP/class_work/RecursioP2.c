/*
    Write a recursive function to print an array
    in the following order,

    [0] [n-1] [1] [n-2] ......... ......... [(n-1)/2] [n/2]

    Input:
        5
        1 5 7 8 9
    Output:
        1 9
        5 8
        7 7
*/
#include <stdio.h>

void pairPrint(int i, int j, int arr[]){
    if (i > j){
        return;
    }

    printf("%d %d\n", arr[i++], arr[j--]);

    pairPrint(i, j, arr);
}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; scanf("%d", &arr[i++]));

    pairPrint(0, n-1, arr);

    return 0;
}