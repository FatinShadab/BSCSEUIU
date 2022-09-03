#include <stdio.h>
#include <math.h>

int main(){
    int n, sum=0;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        int temp = i*i;
        sum += temp;
        printf("%d", temp);
        if (i < n){
            printf(" + ");
        }
    }

    printf(" sum: %d", sum);

    return 0;
}