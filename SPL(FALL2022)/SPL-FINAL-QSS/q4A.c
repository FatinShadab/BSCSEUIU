/**
Write a C program that does the following:
    • Declare an integer variable num and initialize it with any value.
    • Declare a pointer variable and assign the address of num to it.
    • Use the pointer to double the value of num.
    • Print the value of num both before and after the modification.
**/
#include <stdio.h>

int main() {
    int var = 10;
    int* var_pointer = &var;

    printf("Value of var before change : %d\n", var);
    *(var_pointer) *= 2;
    printf("Value of var after change : %d\n", var);

    return 0;
}