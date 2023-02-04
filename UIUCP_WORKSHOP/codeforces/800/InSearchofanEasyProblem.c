#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    while (n--){
        int review;
        scanf("%d", &review);

        if (review){
            printf("HARD\n");
            return 0;
        }
    }

    printf("EASY\n");

    return 0;
}