#include <stdio.h>

int main(){

    int x;
    scanf("%d", &x);

    int steps = 0;

    steps = (x/5) + (x%5)/4 + ((x%5)%4)/3 + (((x%5)%4)%3)/2 + ((((x%5)%4)%3)%2)/1;

    printf("%d", steps);

    return 0;
}