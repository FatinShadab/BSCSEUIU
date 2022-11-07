/*
Program that will check whether a triangle is valid or not, when the three angles (angle value should be such that, 0 < value < 180) of the triangle are entered through the keyboard. 
[Hint: A triangle is valid if the sum of all the three angles is equal to 180 degrees.]
*/
#include <stdio.h>

int main(){
    int angle_1, angle_2, angle_3;

    scanf("%d %d %d", &angle_1, &angle_2, &angle_3);

    if (angle_1*angle_2*angle_3 < 1 || angle_1+angle_2+angle_3 > 180){
        printf("No");
    }
    else{
        printf("Yes");
    }

    return 0;
}