/*
Write a C program which will take as input the height of an object in inches, and
represent it in feet-inch format.

Sample input            Sample output
    57                  4 feet 9 inch
    79                  6 feet 7 inch
*/

#include <stdio.h>

int main(){

    int height;

    scanf("%d", &height);

    printf("%d feet %d inch", height/12, height%12);

    return 0;
}