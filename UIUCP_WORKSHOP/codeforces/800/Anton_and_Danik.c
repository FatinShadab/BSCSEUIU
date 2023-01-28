#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    
    char str[n+1];
    gets(str);

    int countA = 0;
    int countB = 0;

    int idx = 0;
    while (str[idx] != '\0'){
        if (str[idx] == 'A')
            countA++;
        else
            countB++;

        idx++;
    }

    if (countA > countB)
        puts("Anton");
    else if (countA < countB)
        puts("Danik");
    else
        puts("Friendship");

    return 0;
}