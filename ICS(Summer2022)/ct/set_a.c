/*
You have to take as input three floating point 
numbers A, B and C and do the following :

    # Verify if it possible to make a triangle with
them. [ HINT: Sum of any 2 sides lengths is greater 
than the 3rd one ]

    # If it possible to make a triangle with these 
sides, calculate and print the perimeter of the 
triangle.

    # If it is not possible to make a triangle,
consider a trapezium whose lengths of the paralle
sides are A and B and whose height is C . Calculate
its area. The formula is as follow:

        Area = 1/2 * (a+b) * c
*/

#include <stdio.h>

int main(){
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    if ((a+b)>c && (b+c)>a && (a+c)>b){
        printf("Triangle possible\nPerimeter of triangle = %.2f", a+b+c);
    }
    else{
        printf("Triangle not possible\nArea of trapezium = %.2f", (0.5*(a+b)*c));
    }

    return 0;
}