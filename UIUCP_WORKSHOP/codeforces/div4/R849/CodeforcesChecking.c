#include <stdio.h>

int main(){
    int T;
    
    scanf("%d", &T);
    getchar();

    char string[11] = "codeforces";

    while (T--){
        char ch;
        scanf("%c", &ch);
        getchar();

        int found = 0;
        for (int i=0; i<10; i++){
            if (ch == string[i]){
                found = 1;
                break;
            }
        }

        printf((found) ? "YES\n":"NO\n");
    }

    return 0;
}