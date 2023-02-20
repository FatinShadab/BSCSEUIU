#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    gets(str);

    int palindrome = 1;

    int l = 0, r = strlen(str)-1;

    while (l <= r){
        if (str[l++] != str[r--]){
            palindrome = 0;
            break;
        }
    } 

    printf((palindrome) ? "Yes\n":"No\n");

    return 0;
}