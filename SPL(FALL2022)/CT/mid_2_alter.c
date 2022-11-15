#include <stdio.h>


void r_area(int d1, int d2, char name){
    if (d1 == 0 || d2 == 0){
        printf("Output: %c rhombus has only one diagonal.\n", name);
    }

    float rhombus_a = (1/2.0)*(d1 * d2);

    printf("return = ");
    if (rhombus_area != 0.0)
         printf("%.1lf\n", rhombus_a)
    else
        printf("%d\n", 0);

    return;
}