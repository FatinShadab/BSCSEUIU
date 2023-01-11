#include <stdio.h>
#include <ctype.h>

int main(){

    int len;
    int matched = 0;
    char alphabets[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    scanf("%d", &len);
    char uInput[len];

    scanf("%s", uInput);

    for (int i=0; i < 26; i++){
        for (int j=0; j < len; j++){
            if (alphabets[i] == toupper(uInput[j])){
                matched++;
                break;
            }
        }
    }
    if (matched == 26){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}