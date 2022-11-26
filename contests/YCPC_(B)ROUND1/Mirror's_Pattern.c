#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    
    for (int row = 1; row <= n; row++){
        for (int col = 1; col <= n; col++){
            if (col == 1) printf("%d", row);
            else if (col == n) printf("%d", ((n-row)+1));
            else if (row ==  1)printf("%d", col);
            else if (row == n) printf("%d", (n - (col-1)));
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}