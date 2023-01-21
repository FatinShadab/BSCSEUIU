/*
    // To be a sub string a 3 condition must be satisfied.

        1| must be a string of same or less length compairing to the main string
        2| all char's must be present in main string
        3| the sequence of the char's must match.

    mainStr   = Hello
    checkstr  = lle
*/
#include <stdio.h>
#include <string.h>

char mainStr[100], checkStr[100];

int is_substr(){
    int mainStrLen = strlen(mainStr);
    int checkStrLen = strlen(checkStr);

    if (checkStrLen > mainStrLen) return 0;

    int start_idx = 0;
    while (start_idx != mainStrLen){
        int subStr = 1; 
        for (int main_idx=start_idx, check_idx = 0; check_idx<checkStrLen; main_idx++,check_idx++){
            if (mainStr[main_idx] != checkStr[check_idx]){
                subStr = 0;
                break;
            }
        }

        if (subStr)
            return subStr;

        start_idx++;
    }

    return 0;
}

int main(){
    gets(mainStr);
    gets(checkStr);


    if (is_substr())
        printf("'%s' is sub string of '%s'\n", checkStr, mainStr);
    else
        printf("'%s' is not sub string of '%s'\n", checkStr, mainStr);

    return 0;
}