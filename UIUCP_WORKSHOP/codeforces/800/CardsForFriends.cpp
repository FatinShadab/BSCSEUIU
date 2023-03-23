#include <bits/stdc++.h>
using namespace std;

int canMake(int h, int w, int count){
    // for debug
    //printf("\th:%d , w:%d, c:%d\n", h, w, count);

    if (w%2 != 0 && h%2 != 0) return count;


    if (w%2 == 0) return canMake(h, w/2, 2*count);
    else if (h%2 == 0) return canMake(h/2, w, 2*count);
}

int main(){
    int T; scanf("%d", &T);
    int h, w, n, cardQ;

    while (T--){
        scanf("%d %d %d", &h, &w, &n);

        cardQ = canMake(h, w, 1);
        
        printf("%s\n", (cardQ >= n) ? "YES":"NO");
    }

    return 0;
}