#include <stdio.h>

int main(){
    int row_num;
    int col_num;

    printf("Enter the row and col number : ");
    scanf("%d %d", &row_num, &col_num);

    int matrix[row_num][col_num];
    int matrixT[col_num][row_num];

    // Taking user input
    printf("Enter the matrix[%dx%d] elements : \n", row_num, col_num);
    for(int row=0; row < row_num; row++){
        for(int col=0; col < col_num; col++){
            scanf("%d", &matrix[row][col]);
        }
    }

    // code block responsible for transponse matrix.
    for(int row=0; row < col_num; row++){
        for(int col=0; col < row_num; col++){
            matrixT[row][col] = matrix[col][row];
        }
    }

    printf("The Transponse matrix : \n");
    for(int row=0; row < col_num; row++){
        for(int col=0; col < row_num; col++){
            printf("%d ",matrixT[row][col]);
        }
        printf("\n");
    }

    return 0;
}