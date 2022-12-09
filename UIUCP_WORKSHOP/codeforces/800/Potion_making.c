#include <stdio.h>

int main(){
    int T, k, w;
    scanf("%d", &T);

    while (T--){
        scanf("%d", &k); 
        int el = 1, pl = 1; 
        float ratio;

        while (1){
            ratio = (el/(float)pl)*100;
            //printf("%f\n", ratio);
            if (ratio == (float) k){
                break;
            }
            else if (ratio > (float) k){
                pl++;
            }
            else{
                el++;
            }
        }

        printf("%d\n", pl);

    }

    return 0;
}