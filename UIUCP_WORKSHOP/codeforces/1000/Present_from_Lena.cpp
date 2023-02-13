#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    scanf("%d", &n);
 
 
    for (int row=0; row<=(n*2); row++){
        for (int col=0; col<=(n*2); col++){
            // handles upper part including mid row
            if (row <= n){
                if (col < n-row)
                    printf("  ");
                else{
                    if (col == n && row == 0){
                        printf("0");
                    }
                    else if (col == n && row != 0){
                        printf("%d ", row);
                    }
                    else if (col >= n-row && col < n){
                        printf("%d ", ((n-row)-col)*-1);
                    }
                    else if (col <= (n-row)+(row*2) && col > n){
                        if (col != (n-row)+(row*2)){
                            printf("%d ", (n+row)-col);
                        }
                        else{
                            printf("%d", (n+row)-col);
                        }
                    }
                }
            }
            // handles lower part excluding mid row
            else{
                if (col < row-n || col > (n*2)-(row-n)){
                    if (col < row-n){
                        printf("  ");
                    }
                }
                else{
                    if (col == n && row == 2*n){
                        printf("0");
                    }
                    else if (col == n && row != 2*n){
                        printf("%d ", n-(row-n));
                    }
                    else if (col >= row-n && col < n){
                        printf("%d ", ((row-n)-col)*-1);
                    }
                    else if (col <= (row-n)+(row*2) && col > n){
                        int ele = (3*n)-(col+row);
                        if (ele){
                            printf("%d ", ele);
                        }
                        else{
                            printf("%d", ele);
                        }
                    }
                }
            }
        }
        printf("\n");
    }
 
 
 
    return 0;
}