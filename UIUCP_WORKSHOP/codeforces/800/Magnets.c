#include <stdio.h>

int main(){
    int N;
    char magnetPos[3];

    scanf("%d", &N);

    // 10 10 10 01 10 10
    int numOfGroups = 1;

    char lastMagnetPol = '.';

    while (N--){
        scanf("%s", magnetPos);

        if (lastMagnetPol != '.'){
            if (lastMagnetPol == magnetPos[0]){
                numOfGroups++;
            }
        }

        lastMagnetPol = magnetPos[1];
    }

    printf("%d\n", numOfGroups);

    return 0;
}