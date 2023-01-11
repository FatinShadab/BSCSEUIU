#include <stdio.h>

int main(){
    int count = 0;
    int len;
    scanf("%d", &len);
    char seq[len];
    scanf("%s", seq);

    for (int i=0; i < len; i++){
    
        if (seq[i+1] != '\0'){
            if (seq[i] == seq[i+1]){
                count++;
            }
        }

    }

    printf("%d", count);

    return 0;
}