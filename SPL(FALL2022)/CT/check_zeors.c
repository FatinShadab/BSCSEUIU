/*
The input matrix is given. If any of its elements is zero (0) the entire column & row will be
filled with zeros in the output matrix.

If you use another temporary 2D array, 5 marks will be deducted.

Hint: You may use other types of storage.

INPUT:

        1 1 0 3
        1 0 4 2
        1 1 0 5

OUTPUT:

        0 0 0 0
        0 0 0 0
        0 0 0 0
*/

#include <stdio.h>

struct Pos{
    int row;
    int col;
};

int main(){

    int m = 3, n = 4;
    int matrix[3][4] = {
        {1, 1, 0, 3},
        {1, 3, 4, 2},
        {1, 0, 1, 5},
    };

    struct Pos postions[m*n];

    int idx = 0;
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            if (matrix[r][c] == 0){
                postions[idx].row = r;
                postions[idx].col = c;
            }
            else{
                postions[idx].row = -1;
                postions[idx].col = -1;
            }
            idx++; 
        }
    }

    for (int idx=0; idx < m*n; idx++){
        if ((postions[idx].row + postions[idx].col) >= 0){
            // Way : 1
            //----------------------------------------
            //for (int col = 0; col < n; col++)
            //    matrix[postions[idx].row][col] = 0;

            //for (int r=0; r < m; r++)
            //    matrix[r][postions[idx].col] = 0;
            //----------------------------------------

            // Way : 2
            //----------------------------------------
            for (int row=0; row<m; row++){
                for (int col=0; col<n; col++){
                    if (row == postions[idx].row || col == postions[idx].col)
                        matrix[row][col] = 0;
                }
            }
            //----------------------------------------
        }
    }

    // Prints the matrix
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}