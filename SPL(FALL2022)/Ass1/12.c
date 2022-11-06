/*
Program that will construct a menu for performing 
arithmetic operations. The user will give two real 
numbers (a, b) on which the arithmetic operations 
will be performed and an integer number 
(1 <= Choice <= 4) as a choice. Choice-1, 2, 3, 4 are
for performing addition, subtraction, multiplication, 
division (quotient) respectively.
*/
#include <stdio.h>

int main(){
    int ch;
    double a, b;
    scanf("%lf %lf", &a, &b);
    fflush(stdin);
    fflush(stdout);

    // Menu
    printf("================================\n");
    printf("|C: 1|                Addition |\n");
    printf("|C: 2|             Subtraction |\n");
    printf("|C: 3|          Multiplication |\n");
    printf("|C: 4|                Division |\n");
    printf("================================\n");

    printf("Enter a choice (1/2/3/4) : ");
    scanf("%d", &ch);


    if (ch == 1){
        printf("\nAddition: %.2lf", a + b);
    }
    else if (ch == 2){
        printf("\nSubtraction: %.2lf", a - b);
    }
    else if (ch == 3){
        printf("\nMultiplication: %.2lf", a * b);
    }
    else if (ch == 4){
        printf("\nDivision: %.2lf", a / b);
    }
    else{
        printf("\nInvalid choice !!!");
    }

    return 0;
}