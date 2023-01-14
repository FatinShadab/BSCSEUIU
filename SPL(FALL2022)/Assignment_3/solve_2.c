/*
Redesign the above structure such that, it handles for n-dimensional points. No need for circles here.
You just need to implement measureDistance.

	N will be given as input for every structure.

	Example:
	Point p1 N = 4: 100, 200, 0 ,300
	Point p2 N = 4:  30, 50, 60, 70
	measureDistance = sqrt( (100-30)^2 + (200-50)^2 + (0-60)^2 + (300-70)^2 )

	Point p1 N = 3: 100, 200, 0 
	Point p2 N = 4:  30, 50, 60, 70
	measureDistance = Mismatched dimension
*/

#include <stdio.h>
#include <math.h>

int n1, n2;

typedef struct{
    int *cords;
}Point;

double measureDistance(Point p1, Point p2);

int main(){
    Point p1;
    Point p2;

    printf("\nEnter the value of N for p1: ");
    scanf("%d", &n1);

    printf("Enter the %d dimension values for p1 : ", n1);
    int p1_cords[n1];
    for (int itr=0; itr<n1; itr++){
        scanf("%d", &p1_cords[itr]);
    }

    p1.cords = p1_cords;

    printf("\nEnter the value of N for p2: ");
    scanf("%d", &n2);

    printf("Enter the %d dimension values for p2 : ", n2);
    int p2_cords[n2];
    for (int itr=0; itr<n2; itr++){
        scanf("%d", &p2_cords[itr]);
    }

    p2.cords = p2_cords;

    if (n1 != n2){
        printf("\nMismatched dimension (Invalid !)");
        return 0;
    }

    printf("\nDistance between p1 & p2 : %lf", measureDistance(p1, p2));

    return 0;
}

double measureDistance(Point p1, Point p2){

    int without_sqrt = 0;

    int itr = 0;

    while (itr < n1){
        without_sqrt += ((*(p1.cords + itr) - *(p2.cords + itr))*(*(p1.cords + itr) - *(p2.cords + itr)));
        itr++;
    }

    return sqrt(without_sqrt);
}