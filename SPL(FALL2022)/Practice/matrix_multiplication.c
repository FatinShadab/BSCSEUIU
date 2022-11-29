#include <stdio.h>

int main(){

    int A[2][3] = {
        {1, -2, 1},
        {2, 1, 3}
    };

    int B[3][2] = {
        {2, 1},
        {3, 2},
        {1, 1}
    };

    int AB[2][2];

    for (int row = 0; row < 2; row++){
        for (int col = 0; col < 2; col++){
            AB[row][col] = 0;
            for(int idx=0; idx < 3; idx++){
                AB[row][col] += A[row][idx] * B[idx][col];
                printf("\tab = %d row_val = %d col_val = %d, idx=%d, col=%d\n", AB[row][col], A[row][idx], B[idx][col], idx, col);
            }
            printf("AB[%d][%d] = %d\n\n", row, col, AB[row][col]);
        }
    }

    for (int row=0; row < 2; row++){
        for (int col=0; col < 2; col++){
            printf("%d ", AB[row][col]);
        }
        printf("\n");
    }

    return 0;
}