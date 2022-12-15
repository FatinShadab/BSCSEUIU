#include <stdio.h>

int main(){
    long long int n, k;
    scanf("%lld %lld", &n, &k);

    long long int mid = (n%2 == 0) ? n/2 : (n/2)+1;

    if (k <= mid){
        printf("%lld\n", (k*2)-1);
    }
    else{
        printf("%lld\n", (k == mid*2) ? mid*2:(k%mid)*2);
    }

    return 0;
}