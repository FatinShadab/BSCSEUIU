#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int bills_needed;
    bills_needed = (n/100)+((n%100)/20)+(((n%100)%20)/10)+((((n%100)%20)%10)/5)+((((n%100)%20)%10)%5);

    printf("%d\n", bills_needed);

    return 0;
}