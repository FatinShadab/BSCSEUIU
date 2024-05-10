#include <stdio.h>
#include <string.h>

int main(){
    char str1[50]="CSE-1111 SPL";
    char str2[50]="I am a UIUian";

    int i=strlen(str1) * 0.5 - 2;

    printf("init -> i: %d\ninit -> str1: %s\ninit -> str2: %s\n", i, str1, str2);
    printf("--------------------------------------------------------\n");

    for(int m=0; i+m<strlen(str1); m+=3){
        str1[i+m]=str2[m];
        printf("# i:%d, m:%d | i+m: %d | str1: %s  | str2: %s \n", i, m, i+m, str1, str2);
    }
    printf("--------------------------------------------------------\n");

    strcat(str1, str2);
    printf("After strcat:\nstr1 -> %s\nstr2 -> %s\n", str1, str2);
    printf("--------------------------------------------------------\n");

    if(strcmp(str2, str1)>0){
        strncat(str1, "CSE is awesome.",6);
    }
    else{
        strncat(str2, "CSE is awesome.",6);
    }

    printf("strcmp result -> %d\nstr1 -> %s\nstr2 -> %s\n", strcmp(str2, str1), str1, str2);
    printf("--------------------------------------------------------\n");

    return 0;
}