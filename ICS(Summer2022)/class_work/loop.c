#include <stdio.h>

void task_one(){
    int range, sum = 0;

    scanf("%d", &range);

    printf("The sum of -> ");
    for (int i=1; i<=range; i++){
        sum += i;
        printf("%d", i);
        if (i < range){
            printf(" + ");
        }
    }

    printf(" = %d", sum);
}

void task_two(){
    int n, sum = 1, j = 1;

    scanf("%d", &n);

    while (j!=n){
        printf("%d ", j);
        j = j*2;
        sum += j;
    }
    printf("%d ", j);

    printf(" = %d", sum);
}

void task_three(){
    int n, sum = 0;

    scanf("%d", &n);

    for (int i=1; i<=n; i*=2){
        sum += i;
        printf("%d ", i);
    }

    printf(" sum : %d", sum);
}

void task_four(){
    int nth, sum = 0;

    scanf("%d", &nth);

    for(int i=1, j=1; i <= nth; i++, j *=2){
        sum += j;
        printf("%d ", j);
    }
    printf(" sum: %d", sum);
}

int main(){

    //task_one();
    //task_two();
    //task_three();
    //task_four();

    return 0;
}