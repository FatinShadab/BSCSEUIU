#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        int POS[] = {0, 0};

        int n;
        scanf("%d", &n);
        getchar();

        char directionChangeOrder[n + 1];
        scanf("%s", directionChangeOrder);

        int candyFound = 0;

        for (int idx = 0; idx < n; idx++){
            switch (directionChangeOrder[idx]){
                case 'U':
                    POS[1] += 1;
                    break;
                case 'D':
                    POS[1] -= 1;
                    break;
                case 'L':
                    POS[0] -= 1;
                    break;
                case 'R':
                    POS[0] += 1;
                    break;
            }

            if (POS[0] == 1 && POS[1] == 1){
                candyFound = 1;
                break;
            }
        }

        printf("%s\n", (candyFound) ? "YES":"NO");
    }
    
    return 0;
}
