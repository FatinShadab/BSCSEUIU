#include <stdio.h>

int main(){

    int total_sum = 0;

    int col_sums[4] = {0};
    int array_2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3}
    };

    for (int row=0; row < 3; row++){
        int row_sum = 0;
        for (int col=0; col < 4; col++){
            int ele = array_2d[row][col];

            printf("%d  ", ele);

            row_sum += ele;
            col_sums[col] += ele;
        }
        total_sum += row_sum;
        printf("%d\n", row_sum);
    }

    for (int idx=0; idx < 4; idx++){
        printf("%d ", col_sums[idx]);
    }

    printf(" %d", total_sum);

    return 0;
}