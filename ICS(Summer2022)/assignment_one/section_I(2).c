#include <stdio.h>

int main(){
    int f1, f2, f3;

    scanf("%d %d %d", &f1, &f2, &f3);

    /*
        Approach One. considering the employee numbers on floors
    */

    // calculate the times for each floor
    int time_on_f1 = 0*f1+ 2*f2 + 4*f3;
    int time_on_f2 = 2*f1 + 0*f2 + 2*f3;
    int time_on_f3 = 4*f1 + 2*f2 + 0*f3;

    printf("\n==========================================================");
    int min_time;

    if (f1 >= f2 && f1 >= f3){
        printf("\nThe lowest time is = %d m and floor will be floor 1 and there are %d employees", time_on_f1, f1);
        min_time = time_on_f1;
    }
    else if (f2 >= f1 && f2 >= f3){
        printf("\nThe lowest time is = %d m and floor will be floor 2 and there are %d employees", time_on_f2, f2);
        min_time = time_on_f2;
    }
    else{
        printf("\nThe lowest time is = %d m and floor will be floor 3 and there are %d employees", time_on_f3, f3);
        min_time = time_on_f3;
    }

    /*
        Approach Two. considering middle floor and ignoring the employee numbers
    */

    //As the numbers of the floors are fixed, which is 3. So the middle floor will be f2.

    printf("\n==========================================================");

    if (time_on_f2 == min_time){
        printf("\nThe solution for this case is same and it doesn't matter what we consider to solve it, the numbers of employee or the middle floor can be considered to solve the problem.");
        printf("\nThe time will take for middle floor(which is floor 2) is = %d m and the calculated min_time is = %d m", time_on_f2, min_time);
    }
    else if(time_on_f2 < min_time){
        printf("\nThe solution will be wrong if we consider the employee numbers in a floor, because the time for middle floor is less");
        printf("\n(time for middle floor) %d < %d (solve considering the numbers of employees)", time_on_f2, min_time);
    }
    else{
        printf("\nRare case !!!");
        printf("\n(time for middle floor) %d > %d (solve considering the numbers of employees)", time_on_f2, min_time);
    }

    printf("\n==========================================================");


    return 0;
}