/*
            A. Odd Divisor
        time limit per test
            2 seconds
        memory limit per test
            256 megabytes
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    long long int n;

    while (T--){
        scanf("%lld", &n);
    /*
        *** gives tle !

        int flag; = 0;

        if (n%2 != 0){
            printf("YES\n");
            continue;
        }

        for (long long int i = 3; i*i <= n; i += 2){
            if (n % i == 0){
                flag = 1;
                break;
            }
        }

        printf((flag) ? "YES\n":"NO\n");

    */

        printf(((n& (n - 1)) != 0) ? "YES\n":"NO\n");
    }

    return 0;
}
