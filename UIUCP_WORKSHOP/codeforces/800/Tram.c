#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int max_carried = 0;
    int carring = 0;

    while (n--){
        int left, arrived;
        scanf("%d %d", &left, &arrived);

        carring -= left;
        carring += arrived;

        if (carring > max_carried){
            max_carried = carring;
        }
    }

    printf("%d\n", max_carried);

    return 0;
}