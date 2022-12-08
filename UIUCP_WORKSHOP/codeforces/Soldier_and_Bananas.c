#include <stdio.h>

int main(){

    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);

    int doller_needed = 0;
    for (int i=1; i <= w; i++){
        doller_needed += i*k;
    }

    printf("%d", (doller_needed >= n) ? doller_needed-n:0);

    return 0;
}