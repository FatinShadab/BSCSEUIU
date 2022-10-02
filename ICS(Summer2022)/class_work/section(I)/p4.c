#include <stdio.h>

int main(){

    /*
        n = 5;

        1^2 + 2^2 + 3^2 + 4^2 + 5^2
    */

    int n;
    int sum = 0;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        //printf("%d ", i*i);
        sum = sum + (i*i);
    }

    printf("%d", sum);

    return 0;
}