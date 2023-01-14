/*
Program that will decide whether a year is leap year or not.

Yes, if ( Year % 4 == 0 && year % 100 != 0 )   ||  ( Year % 400 ==0 )
*/
#include <stdio.h>

int main(){
    int year;
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}