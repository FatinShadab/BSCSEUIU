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
*    *
******

Output:  INput:
--------------------
*****    n = 4
*****
*   *
*****

*/
#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int mid = (n % 2 == 0) ? n / 2 : (n / 2) + 1;

    for (int row = 1; row <= n; row++){
        for (int col = 1; col <= n; col++){
            if (row == 1 || row == n || row == mid) printf("*");
            else{
                if (col == 1 || col == n) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}