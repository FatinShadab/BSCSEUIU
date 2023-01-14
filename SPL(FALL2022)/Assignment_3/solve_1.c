#include <stdio.h>
#include <math.h>

struct Point{
    int x_cord;
    int y_cord;
};

struct Circle{
    struct Point center_point;
    float radius;
};

long long int power(long long int x, long long int p);

double measureDistance(struct Point p1, struct Point p2);

void move(struct Point *p, int dirX, int dirY);

int isInsideCircle(struct Circle c, struct Point p);


int main(){

    struct Point firstPoint;
    struct Point secondPoint;
    struct Circle myCircle;

    double circle_radius;

    printf("\nEnter the p1 point x, y cord : ");
    scanf("%d %d", &firstPoint.x_cord, &firstPoint.y_cord);

    printf("\nEnter the p2 point x, y cord : ");
    scanf("%d %d", &secondPoint.x_cord, &secondPoint.y_cord);

    printf("\nEnter the Circle radius : ");
    scanf("%lf", &circle_radius);

    myCircle.center_point = secondPoint;
    myCircle.radius = circle_radius;

    printf("\nDistance between p1 & p2 is : %lf", measureDistance(firstPoint, secondPoint));

    printf("\nEnter the x & y cords to move the p1 : ");
    int dX, dY;
    scanf("%d %d", &dX, &dY);

    move(&firstPoint, dX, dY);

    printf("\nThe P1 with x: %d & y: %d is in the circle ? ", firstPoint.x_cord, firstPoint.y_cord);
    printf((isInsideCircle(myCircle, firstPoint)) ? "YES":"NO");

    return 0;
}

long long int power(long long int x, long long int p){
    long long int result = x;

    for (int itr=0; itr<p-1; itr++){
        result *= x;
    }

    return result;
}

double measureDistance(struct Point p1, struct Point p2){
    double D;

    int sub_x= (p2.x_cord - p1.x_cord);
    int sub_y = (p2.y_cord - p1.y_cord);

    int sum_x_y_sqr = power(sub_x, 2) + power(sub_y, 2);

    D = sqrt(sum_x_y_sqr);

    return D;
}

void move(struct Point *p, int dirX, int dirY){
    p->x_cord = dirX;
    p->y_cord = dirY;

    return;
}

int isInsideCircle(struct Circle c, struct Point p){

    double DOF_centerP_p1 = measureDistance(c.center_point, p);

    return (c.radius >= DOF_centerP_p1) ? 1:0;
}