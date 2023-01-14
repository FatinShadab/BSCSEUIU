/*
Write a program (WAP) that will take N numbers as inputs and compute their average. 
(Restriction: Without using any array)
*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    double sum = 0;

    for (int i=0; i<n; i++){
        double num;
        scanf("%lf", &num);
        sum += num;
    }

    printf("AVG of %d inputs: %lf", n, sum/n);

    return 0;
}