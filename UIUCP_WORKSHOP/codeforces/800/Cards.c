#include<stdio.h>
#include<string.h>

int main(){

    int size;
    scanf("%d", &size);

    char string[size];
    scanf("%s", string);
    
    int ones = 0;
    int zeros = 0;

    for (int i=0; i<size; i++){
        if (string[i] == 'n'){
            ones += 1;
        }
        if (string[i] == 'z'){
            zeros += 1;
        }
    }

    for (int i=0; i<ones; i++){
        printf("%d ", 1);
    }
    for (int i=0; i<zeros; i++){
        printf("%d ", 0);
    }

    return 0;
}