#include <stdio.h>

int main(){

    int lw, bw;
    scanf("%d %d", &lw, &bw);

    int year = 0;

    while (lw <= bw){
        //printf("lw = %d, bw = %d, y = %d\n", lw, bw, year);
        lw *= 3;
        bw *= 2;
        year++;
    }
    //printf("lw = %d, bw = %d, y = %d\n", lw, bw, year);

    printf("%d", year);

    return 0;
}