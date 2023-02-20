#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int decent = 1;
    int prev = 0;
    int temp;

    for (int i=0; i<n; i++){
        scanf("%d", &temp);

        if (temp < prev){
            decent = 0;
        }else{
            prev = temp;
        }
    }

    printf((decent) ? "Yes\n":"No\n");

    return 0;
}