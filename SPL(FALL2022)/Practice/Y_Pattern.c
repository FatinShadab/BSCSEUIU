#include <stdio.h>

int main() {

    // The pattern is valid for all odd values of n !!!
    int n; scanf("%d", &n);

    for (int row=1; row<=n; row++){
        for (int col=1; col<=n; col++){
            if (col == ((n/2)+1)){
                if (row > (n/2)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            else if (col < ((n/2)+1)){
                if (col == row){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            else if (col > ((n/2)+1)){
                if (col == (n-row)+1){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}