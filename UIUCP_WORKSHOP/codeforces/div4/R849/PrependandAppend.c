#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        scanf("%d", &n);
        getchar();

        char bs[n+1];
        scanf("%s", bs);

        if (n == 1) {
            printf("1\n");
            continue;
        }

        int op = 0;
        int s = 0;
        int e = n-1;

        while (s < e){
            if (bs[s] == bs[e]){
                break;
            }
            //printf("\t%c %c\t\n", bs[s], bs[e]);
            op++;
            //printf("s:%d e:%d op:%d\n", s, e, op);
            s++;
            e--;
        }

        printf("%d\n", n-(op*2));
    }

    return 0;
}