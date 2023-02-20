#include <stdio.h>

int nthFibNum(int N){
    if (N <= 1){
        return N;
    }

    return nthFibNum(N-1) + nthFibNum(N-2);
}

int main(){
    int N;
    scanf("%d", &N);

    printf("%d\n", nthFibNum(N));

    return 0;
}