#include <stdio.h>


void rhombus_area(int d1, int d2, char name){
    if (d1*d2 == 0) printf("\nOutput: %c rhombus has only one diagonal.", name);

    float rhombus_area = 0.5*(d1 * d2);

    printf("\nreturn = ");
    (rhombus_area != 0.0) ? printf("%.1lf", rhombus_area) : printf("%d", 0);

    return;
}

int main(){
    printf("Input : ");
    int d1, d2; scanf("%d %d", &d1, &d2);
    getchar();
    char name; scanf("%c", &name);

    rhombus_area(d1, d2, name);

    return 0;
}