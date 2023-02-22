#include <stdio.h>
#include <string.h>

int main(){
    int shift;
    char data[101];

    scanf("%d", &shift); getchar();
    fgets(data, 100, stdin);

    int idx = 0;
    while(data[idx] != '\0'){
        if ((int) data[idx] >= (int) 'a' && (int) data[idx] <= (int) 'z'){
            int ascii = (int) data[idx] - shift;

            if (ascii < 97){
                ascii = 122 - (97 - ascii) + 1;
            }

            printf("%c", ascii);
            idx++;
            continue;
        }

        printf("%c", data[idx]);
        idx++;
    }

    printf("\n");

    return 0;
}