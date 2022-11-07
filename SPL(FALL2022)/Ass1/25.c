/*
Write a program (WAP) that will give the sum of first Nth terms for the following series.
1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, …….
*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;

    for (int i = 1; i <= n; i++){
        if (i%2 == 0){
            sum += (i*-1);
        }
        else{
            sum += i;
        }
    }

    printf("%d", sum);

    return 0;
}