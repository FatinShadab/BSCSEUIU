#include <stdio.h>

int main(){
    int distinctPoints[3];

    for(int i=0; i<3; i++){
        scanf("%d", &distinctPoints[i]);
    }

    for (int i=0; i<3; i++){
        for (int j=i+1; j<3; j++){
            if (distinctPoints[i]>distinctPoints[j]){
                int temp = distinctPoints[i];
                distinctPoints[i] = distinctPoints[j];
                distinctPoints[j] = temp;
            }
        }
    }

    printf("%d\n", (distinctPoints[1]-distinctPoints[0])+(distinctPoints[2]-distinctPoints[1]));

    return 0;
}