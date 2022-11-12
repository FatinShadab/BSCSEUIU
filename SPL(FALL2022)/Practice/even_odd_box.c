/*

Output:  INput:
-------------------
*****    n = 5
*   *
*****
*   *
*****

Output:  INput:
--------------------
******    n = 6
*    *
******
*    *
******
*    *

*/
#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    for (int row = 1; row <= n; row++){
        for (int col = 1; col <= n; col++){
            if (row % 2 == 1) printf("=");
            else{
                if (col == 1 || col == n) printf("=");
                else printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}