#include <stdio.h>

int main(){

    int min_time;
    int f1, f2, f3;

    scanf("%d %d %d", &f1, &f2, &f3);

    int time_on_f1 = 0*f1+ 2*f2 + 4*f3;
    int time_on_f2 = 2*f1 + 0*f2 + 2*f3;
    int time_on_f3 = 4*f1 + 2*f2 + 0*f3;
    
    if (f1 >= f2 && f1 >= f3){
        min_time = time_on_f1;
    }
    else if (f2 >= f1 && f2 >= f3){
        min_time = time_on_f2;
    }
    else{
        min_time = time_on_f3;
    }

    if (time_on_f2 == min_time){
        printf("%d", min_time);
    }
    else if(time_on_f2 < min_time){
        printf("%d", time_on_f2);
    }
    else{
        printf("%d", min_time);
    }

    return 0;
}