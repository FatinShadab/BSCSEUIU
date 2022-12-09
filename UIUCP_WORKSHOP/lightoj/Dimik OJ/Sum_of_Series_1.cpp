#include <bits/stdc++.h>

using namespace std;

int pow(int x, int e){
    if (!e) return 1;
    int power = x;

    for (int i=0; i<e-1; i++){
        power *= x;
    }

    return power;
}

int main(){

    int T;
    scanf("%d", &T);

    while (T--){
        int x, k;
        scanf("%d %d", &x, &k);

        int sum = 0;
        for (int e=0; e<=k; e++){
            int p = pow(x, e);
            //printf("x: %d, e: %d, pow = %d\n", x, e, p);
            sum += p;
        }

        printf("Result = %d\n", sum);
    }

    return 0;
}