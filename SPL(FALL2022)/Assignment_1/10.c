/*
Program that will evaluate simple expressions of the form-  

<number1>   <operator>   <number2> 

; where operators are (+, - , *, /) 

And if the operator is “/”, then check if <number2> nonzero or not.
*/
#include <stdio.h>

int main(){
    int lopd, ropd;
    char op;

    scanf("%d", &lopd);
    getchar();
    scanf("%c", &op);
    scanf("%d", &ropd);

    if (op == '*') printf("Multiplication: %d", lopd * ropd);
    else if (op == '+') printf("Addition: %d", lopd + ropd);
    else if (op == '-') printf("Subtraction: %d", lopd - ropd);
    else if (op == '/'){
        if (ropd != 0) printf("Division: %d", lopd / ropd);
        else printf("Division: Zero as divisor is not valid!");
    }

    return 0;
}