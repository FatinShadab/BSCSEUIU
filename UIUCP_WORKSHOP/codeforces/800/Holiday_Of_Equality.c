#include <stdio.h>

int main(){

    int len;
    int ans = 0;

    scanf("%d", &len);

    int array[len];

    for (int i=0; i<len; i++){
        scanf("%d", &array[i]);
    }

    int largest = array[0];
    for (int i=0; i<len; i++){
        if (largest < array[i])
        largest = array[i];
    }

    for (int i=0; i<len; i++){
        ans += (largest - array[i]);
    }

    printf("%d", ans);

    return 0;
}