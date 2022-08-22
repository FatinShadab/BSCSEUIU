/*
Question: Write a C program which will calculate the terminal velocity of a moving body by using 
the following equation: 

                                        V = u + at
You have to take it as input , and in order. Can you figure out the data types for all the 
variables?

Sample input                                      Sample output           
    5 6 12                                            v = 77
*/

#include <stdio.h>

int main(){
    int u, a, t;

    scanf("%d %d %d", &u, &a, &t);

    int v = u + (a*t);

    printf("v = %d", v);
    
    return 0;
}