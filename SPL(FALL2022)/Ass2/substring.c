#include <stdio.h>

int is_subseq(char text[], char key[]);

int main(){
    char string1[100];
    char string2[100];

    scanf("%s", string1);
    getchar();
    scanf("%s", string2);

    is_subseq(string1, string2);

    return 0;
}

int is_subseq(char *text, char *key){

    
    printf("%s %s", text, key);
    return 0;
}