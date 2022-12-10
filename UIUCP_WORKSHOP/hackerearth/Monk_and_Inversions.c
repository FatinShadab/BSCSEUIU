#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        scanf("%d", &n);

        int matrix[n][n];
        for (int r=0; r < n; r++){
            for (int c=0; c < n; c++){
                scanf("%d", &matrix[r][c]);
            }
        }
        
        int inversions = 0;
        for (int r=0; r < n; r++){
            for (int c=0; c < n; c++){
                for (int x1=r; x1 >= 0; x1--){
                    for (int y1=c; y1 >= 0; y1--){
                        inversions += (matrix[r][c] < matrix[x1][y1]) ? 1:0;
                    }
                }
            }
        }
        
        printf("%d\n", inversions);
    }

    return 0;
}