#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    while (T--){
        int n, k;
        scanf("%d %d", &n, &k);

        int arr[n];
        for(int idx=0; idx < n; scanf("%d", &arr[idx++]));

        int rotated_arr[n];
        for (int idx=0; idx < n; idx++){
            int rotated_idx = idx+k;

            if (rotated_idx >= n) rotated_idx %= n;
            rotated_arr[rotated_idx] = arr[idx];
        }

        for(int idx=0; idx < n; printf("%d ",rotated_arr[idx++]));
        puts("");

    }

    return 0;
}