#include <stdio.h>

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    if(a>b){
        printf("a: %d is grater than b: %d", a, b);
    }
    else{
        printf("b: %d is grater than a: %d", b, a);
    }

    return 0;
}