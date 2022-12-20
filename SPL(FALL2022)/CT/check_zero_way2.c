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

int main(){
    int m = 3, n = 3;

    int matrix[3][3] = {
        {0, 2, 3},
        {4, 0, 6},
        {7, 8, 0},
    };
                                                     //   0   1   2  <- idx
    int rows[m]; for (int i=0; i<m; rows[i++] = -1); // {-1, -1, -1} <- ele
    int cols[n]; for (int i=0; i<n; cols[i++] = -1); // {-1, -1, -1} <- ele
                                                     //   0   1   2  <- idx

    // matrix traversal
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            // checks if  the element is 0
            if (matrix[r][c] == 0){
                // if zero mark's the row to be zero
                rows[r] = 1;
                // if zero mark's the col to be zero
                cols[c] = 1;
            }
        }
    }
    
    // matrix traversal
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            // checks if the element located in the marked row or col
            if (cols[c] == 1 || rows[r] == 1){
                // if so make the value 0
                matrix[r][c] = 0;
            }
        }
    }

    // prints the output
    for (int r=0; r<m; r++){
        for (int c=0; c<n; c++){
            printf("%d ", matrix[r][c]);
        }
        puts("");
    }

    return 0;
}