/*
WAP that will take (m x n) positive integer inputs
into a matrix of dimension m x n. Now replace all 
the duplicate integers by -1 in that matrix.Finally 
display it.
*/
#include <stdio.h>

int main(){
    int m, n; scanf("%d %d", &m, &n);

    int matrix[m][n]; 

    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            scanf("%d", &matrix[row][col]);
        }
    }

    int max = 0;
    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            if (matrix[row][col] > max){
                max = matrix[row][col];
            }
        }
    }

    int freqArr[max+1]; for(int i=0; i<=max; i++) freqArr[i] = 0;
    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            freqArr[matrix[row][col]]++;
        }
    }

    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            if (freqArr[matrix[row][col]] != -1){
                freqArr[matrix[row][col]] = -1;
            }else{
                matrix[row][col] = freqArr[matrix[row][col]];
            }
        }
    }

    puts("After replacing all duplicates by -1 :");
    for (int row=0; row < m; row++){
        for (int col=0; col < n; col++){
            printf("%d ", matrix[row][col]);
        }
        puts("");
    }

    return 0;
}