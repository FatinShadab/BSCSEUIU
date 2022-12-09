#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        scanf("%d", &n);

        for (int i=n; i>-1; i--){
            if (i > 1){
                printf("2^%d", i);
            }
            else{
                printf((i > 0) ? "2":"1");
            }
            
            if (i > 0){
                printf(" + ");
            }
        }
        printf("\n");
    }

    return 0;
}