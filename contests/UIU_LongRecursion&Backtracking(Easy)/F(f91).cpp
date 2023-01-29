/*
    Problem Link:
        https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1637
*/
#include <bits/stdc++.h>
using namespace std;

int f91(int N){
    if (N <= 100){
        return f91(f91(N+11));
    }

    return N-10;
}

int main(){
    int run = 1;
    
    while (run){
        int N;
        scanf("%d", &N);

        switch (N){
            case 0:
                run = 0;
                break;
            default:
                printf("f91(%d) = %d\n", N, f91(N));
        }
    }

    return 0;
}