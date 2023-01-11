#include <stdio.h>
#include <string.h>

int main(){
    int numOfa = 0;
    char string[51];

    scanf("%s", string);

    int strLen = strlen(string);

    for(int i=0; i<strLen; i++){
        if (string[i] == 'a'){
            numOfa++;
        }
    }

    //printf("\na's - %d", numOfa);
    int remove_char = 0;
    float Pa;
    
    
    while (1){
        Pa = ((float) numOfa / (float) (strLen-remove_char))*100;

        if (Pa > 50.00){
            printf("%d", (strLen-remove_char));
            break;
        }
        else{
            //printf("\nPa-%f  rc-%d len-%d --%d", Pa, remove_char, strLen, (strLen-remove_char));
            remove_char++;
        }
    }
    
    return 0;
}