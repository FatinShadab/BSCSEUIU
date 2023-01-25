#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int X = 0;
    int Y = 0;
    int Z = 0;

    while (n--){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        X += x;
        Y += y;
        Z += z;
    }

    if (!X && !Y && !Z){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}