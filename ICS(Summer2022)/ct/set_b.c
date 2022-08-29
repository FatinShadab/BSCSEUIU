/*
You have to take as input a floating point number, 
and find out if the number belongs to any of these
intervals, 

    (10, 50]
    (50, 80)
    [80, 100]

if the number belongs to any of these intervals,
then print the interval. Otherwise, print 
"out of range".See the sample inputs and outputs 
for details.

*** Note: in these intervals, the symbol '(' or ')'
represents that the corresponding number itself is 
excluded from the interval, while the symbol '[' or
']' means that the corresponding number is included
in the interval. For example,

    (10, 50] means 10 < x <= 50

10 is excluded from the range while 50 is included. 

===================================================
Input type (float)                Output type (str)
==================                =================
Case: 1
---------------------------------------------------
15.6                            In interval (10, 50]
---------------------------------------------------
Case: 2
---------------------------------------------------
79.0                            In interval (50, 80)
---------------------------------------------------
Case: 3
---------------------------------------------------
100.1                           out of range
===================================================
*/

#include <stdio.h>

int main(){

    float number;

    scanf("%f", &number);

    if (number>10.0 && number <= 50.0){
        printf("In interval (10, 50]");
    }
    else if(number>50.0 && number<80.0){
        printf("In interval (50, 80)");
    }
    else if(number>=80.0 && number<=100.0){
        printf("In interval [80, 100]");
    }
    else{
        printf("Out of range");
    }

    return 0;
}