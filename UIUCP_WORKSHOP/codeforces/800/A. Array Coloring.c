// PB LINK : https://codeforces.com/contest/1857/problem/A

#include <stdio.h>

int main(){
    int T; scanf("%d", &T);
    int n, num, odds, evens;

    while (T--){
        odds = 0;
        evens = 0;

        scanf("%d", &n);

        while (n--){
            scanf("%d", &num);

            if (num%2){
                odds++;
            }else{
                evens++;
            }
        }

        if (odds%2 == 1){
            printf ("NO\n");
            continue;
        }

        printf("YES\n");
    }

    return 0;
}