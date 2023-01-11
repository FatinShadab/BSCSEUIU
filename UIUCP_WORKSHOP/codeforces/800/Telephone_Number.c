#include <stdio.h>

int main () {

    int testcases;
    scanf("%d", &testcases);

    for (int tcase=0; tcase<testcases; tcase++){
        int size;
        scanf("%d", &size);

        int pos = size;

        char phoneNumber[size+1];
        scanf("%s", phoneNumber);

        for (int i=0; i<size; i++){
            if (phoneNumber[i] == '8'){
                pos = i;
                break;
            }
        }


        if (size-pos>=11)    printf("YES\n");
        else                 printf("NO\n");
        
    }

    return 0;
}