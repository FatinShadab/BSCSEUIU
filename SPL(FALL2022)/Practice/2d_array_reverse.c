/*
WAP that will take (mxn) integer inputs into a matrix
of dimension m X n. Now reverse that matrix within itself
and display it. Reversal means swap 1st column with the nth
column, swap 2nd column with the (n-1)th column and so on ...
*/

#include <stdio.h>

int main(){
    int m, n; scanf("%d %d", &m, &n);

    int arr[m][n];
    int reverse_arr[m][n];

    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            scanf("%d", &arr[row][col]);
        }
    }

    for (int row=0; row < m; row++){
        for (int col=n-1; col >= 0; col--){
            reverse_arr[row][col] = arr[row][n-1-col];
        }
    }

    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            printf("%d ", reverse_arr[row][col]);
        }
        printf("\n");
    }

    return 0;
}