#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int i=1;
    while (i <= N){
        if (N%i == 0){
            printf("%d", i);

            if (i != N){
                printf("\n");
            }
        }

        i++;
    }

    return 0;
}