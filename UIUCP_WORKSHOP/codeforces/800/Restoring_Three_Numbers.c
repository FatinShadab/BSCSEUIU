#include <stdio.h>

int main(){

    int sums[4];
    int maxSum = -1;
    
    for(int idx=0; idx<4; idx++){
        scanf("%d", &sums[idx]);
        
        if (sums[idx] > maxSum)
            maxSum = sums[idx];
    }

    for (int itr=0; itr<4; itr++){
        if (sums[itr] != maxSum){
            printf("%d ",  maxSum-sums[itr]);
        }
    }
    puts("");

    return 0;
}