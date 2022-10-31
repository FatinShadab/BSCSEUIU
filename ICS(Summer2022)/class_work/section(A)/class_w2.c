/*
Write a C program that takes integer N and another integer d and prints the
highest power of d that is present in the integer factorization of N
*/
#include <stdio.h>
#include<math.h>

int main(){
    int number;
    int base;
    int power;
    
    scanf("%d %d", &number, &base);

    for (int i=1; i<=number; i++){
        if (number%i == 0){
            double p = log10(i) / log10(base);
            if (p - (int)p == 0){
                power = (int)p;
            }
        }
    }

    printf("%d", power);

    return 0;
}