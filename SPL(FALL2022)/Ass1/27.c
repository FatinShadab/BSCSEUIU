/*
Write a program (WAP) that will print Fibonacci series upto Nth terms.
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, …….
*/
#include <stdio.h>

int main(){
    int n;
    int t1 = 1, t2 = 1;
    int next = t1 + t2;
    scanf("%d", &n);

    if (n >= 1){
        printf("1");
        if (n != 1) printf(", ");
    }
    
    if (n >= 2){
        printf("1");
        if (n != 2) printf(", ");
    }
    

    for (int i=3; i<=n; i++){
        
        printf("%d", next);
        t1 = t2;
        t2 = next;
        next = t1 + t2;
        if (i != n){
            printf(", ");
        }
    }

    return 0;
}