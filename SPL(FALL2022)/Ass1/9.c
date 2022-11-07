/*
Program that will categorize a single character that is entered at the terminal,
whether it is an alphabet, a digit or a special character.

(Restriction: Without math.h)
*/
#include <stdio.h>

int main(){
    char chr;
    scanf("%c", &chr);

    int ascii_code = (int) chr;

    if (ascii_code <= 57 && ascii_code >= 48)
        printf("Digit");
    else if (ascii_code <= 90 && ascii_code >= 65)
        printf("Alphabet");
    else if (ascii_code <= 122 && ascii_code >= 97)
        printf("Alphabet");
    else
        printf("Special");

    return 0;
}