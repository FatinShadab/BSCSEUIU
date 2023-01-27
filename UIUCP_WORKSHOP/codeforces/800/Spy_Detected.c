#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        int type1Idx = 0, type2Idx = 0;
        int type1 = 0, type2 = 0;
        
        scanf("%d", &n);
        int arr[n];
        int freq[101] = {0};
        for (int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            freq[arr[i]] += 1;
        }

        for (int i=0; i<n; i++){
            if (type1 != 0 && type2 != 0){
                break;
            }
            else if (type1 == 0 && type2 == 0){
                type1 = arr[i];
                type1Idx = i;
            }
            else if(arr[i] != type1){
                type2 = arr[i];
                type2Idx = i;
            }
        }

        if (freq[type1] == 1){
            printf("%d\n", type1Idx+1);
        }
        else{
            printf("%d\n", type2Idx+1);
        }
    }

    return 0;
}