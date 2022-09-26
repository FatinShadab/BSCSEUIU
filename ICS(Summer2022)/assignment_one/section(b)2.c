#include <stdio.h>

int main(){

    int number, temp, reversed_number;
    int number_len = 0, right_digit = 0, sep = 1, num_gen = 1;

    scanf("%d", &number);

    temp = number;

    while (temp != 0){
        number_len ++;
        temp /= 10;
    }

    if (number_len % 2 != 0){
        for (int i=0; i<((number_len-1)/2); i++){
            right_digit ++;
            sep *= 10;
        }
    }
    else{
        for (int i=0; i<((number_len+1)/2); i++){
            right_digit ++;
            sep *= 10;
        }    
    }

    for (int i=0; i<(number_len-right_digit); i++){
        num_gen *= 10;
    }

    reversed_number = ((number % sep) * num_gen) + (number / sep);

    printf("%d", reversed_number);


    return 0;
}