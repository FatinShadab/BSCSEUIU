#include <stdio.h>
/*
p1 -
input - 5

output -  5 4 3 2 1
*/

int main(){
    int n;

    scanf("%d", &n);

    for(int i=n; i!=0; i--){
        printf("%d ", i);
    }

    return 0;
}