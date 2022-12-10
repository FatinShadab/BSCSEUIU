#include <stdio.h>

int main(){

    int row, col;
    int right_flag = 1;
    scanf("%d %d", &row, &col);

    for (int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            if (i%2 == 0){
                printf("#");
            }
            else{
                if (j == 0 && !right_flag ){
                    printf("#");
                }
                else if (j == col-1 && right_flag){
                    printf("#");
                }
                else{
                    printf(".");
                }
            }
        }
        if (i%2 == 1){
            right_flag = (right_flag) ? 0:1;
        }
        puts("");
    }

    return 0;
}