#include <stdio.h>

int main(){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a == b && a == c){
        printf("All same");
    }
    else if (a>=b && a>=c){
        printf("Max is a: %d", a);
    }
    else if (b>=a && b>=c){
        printf("Max is b: %d", b);
    }
    else{
        printf("Max is c: %d", c);
    }

    return 0;
}