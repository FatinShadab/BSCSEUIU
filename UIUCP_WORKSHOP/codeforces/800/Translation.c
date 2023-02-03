#include <stdio.h>
#include <string.h>

int main(){
    char stringOne[101];
    char stringTwo[101];

    scanf("%s %s", stringOne, stringTwo);

    int sOneLen = strlen(stringOne);
    int sTwoLen = strlen(stringTwo);

    if (sOneLen != sTwoLen){
        printf("NO\n");
        return 0;
    }

    int valid = 1;
    for (int i=0; i<sOneLen; i++){
        if (stringOne[i] != stringTwo[sTwoLen-1-i]){
            valid = 0;
            break;
        }
    }

    printf((valid) ? "YES\n":"NO\n"); 

    return 0;
}