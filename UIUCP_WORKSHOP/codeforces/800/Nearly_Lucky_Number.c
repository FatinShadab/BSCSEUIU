#include <stdio.h>
#include <string.h>

int main(){
    int count = 0;
    char num[1000000];
    char goodnums[] = "47";

    scanf("%s", num);

    for (int i=0; i<strlen(num); i++){
        if (num[i] == goodnums[0] || num[i] == goodnums[1]){
            count++;
            //printf("%d %d\n", num[i], count);
        }
    }
    
    if (count == 4 || count == 7){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}