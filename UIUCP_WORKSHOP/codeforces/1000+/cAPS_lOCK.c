#include<stdio.h>
#include <ctype.h>
#include<string.h>

int main(){

    char string[101];
    gets(string);

    int str_len = strlen(string);
    int upeercase_char = 1;

    if (string[0]>='A'&&string[0]<='Z'){
        for (int i=1; i<str_len; i++){
            if (string[i]>='A'&&string[i]<='Z'){
                upeercase_char++;
            }
        }
        //printf("%d %d", upeercase_char, str_len);
        if (upeercase_char == str_len){
           for (int i=0; i < str_len; i++){
            string[i] = tolower(string[i]);
           }
           printf("%s", string);
        }
        else{
            printf("%s", string);
        }
    }
    else{
        int upeercase_char = 0;

        for (int i=1; i<str_len; i++){
            if (string[i]>='A'&&string[i]<='Z'){
                upeercase_char++;
            }
        }
        if (upeercase_char == (str_len-1)){
            string[0] = toupper(string[0]);
            for (int i=1; i < str_len; i++){
                string[i] = tolower(string[i]);
            }
           printf("%s", string);
        }
        else{
            printf("%s", string);
        }
    }
    return 0;
}