#include <stdio.h>
int CACHE[100];

int fibb(int n){
    if (CACHE[n] != -1){
        return CACHE[n];
    }

    CACHE[n] = fibb(n-1) + fibb(n-2);
    
    return CACHE[n];
}

int main(){
    CACHE[0] = 0;
    CACHE[1] = 1;

    for (int i=2; i<100; i++){
        CACHE[i] = -1;
    }

    int n;
    scanf("%d", &n);

    printf("%d", fibb(n));

    return 0;
}