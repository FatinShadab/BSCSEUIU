/*
    problem link : https://codeforces.com/contest/1807/problem/B
*/
#include <stdio.h>
 
int main(){
    int T; scanf("%d", &T);
    int n, bag, mihai, bianca;
    while (T--){
        mihai = 0; bianca = 0;
        scanf("%d", &n);
 
        for (int i=0; i<n; i++){
            scanf("%d", &bag);
            if (bag % 2){
                bianca += bag;
                continue;
            }
 
            mihai += bag;
        }
 
        printf("%s\n", (mihai>bianca) ? "YES":"NO");
    }
 
    return 0;
}