#include <stdio.h>

int main(){
    int T; scanf("%d", &T);
    int a, b, c, dif;

    while (T--){
        scanf("%d %d %d", &a, &b, &c);
        printf("%s\n", (a+b == c || b+c == a || a+c == b) ? "YES":"NO");
    }

    return 0;
}