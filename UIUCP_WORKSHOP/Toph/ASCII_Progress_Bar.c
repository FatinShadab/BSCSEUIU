#include <stdio.h>
#include <math.h>

int main(){
    double P;
    scanf("%lf", &P);
    
    int floorP = floor(P);
    int flag = floorP / 10;
    printf("[");
    for (int i=1; i<=10; i++){
        (i <= flag) ? printf("+") : printf(".");
    }
    printf("] %d%%\n", floorP);

    return 0;
}