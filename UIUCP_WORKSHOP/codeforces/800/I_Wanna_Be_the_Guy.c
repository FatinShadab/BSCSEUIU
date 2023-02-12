#include <stdio.h>

int main() {

    int levels[101] = {0};

    int win = 1;
    int n, x, y, temp;

    scanf("%d", &n);
    
    scanf("%d", &x);
    for (int i=0; i<x; i++){
        scanf("%d", &temp);
        levels[temp] = 1;
    }
    
    scanf("%d", &y);
    for (int j=0; j<y; j++){
        scanf("%d", &temp);
        levels[temp] = 1;
    }
    
    for (int i=1; i<=n; i++){
        if (!levels[i]){
            win = 0;
            break;
        }
    }
    
    printf((win) ? "I become the guy.\n":"Oh, my keyboard!\n");

    return 0;
}