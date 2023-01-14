/*
Suppose, you have two structures called "Point" and "Circle". In the Point structure,
there are two integer types of variables, "x_coord" and "y_coord". In the Circle structure,
there are also two variables: one is "radius," which is of the float type, and another is "center,"
which is of the point type. There are three methods. measureDistance(Point p1, Point p2) :
It calculate the distance between two points and return that distance.
move(Point *p, int dirX, int dirY): It moves the point according to the value of dirX and dirY.
isInsideCircle(Circle c, Point p): It calculates if point p is inside the circle or not.
Write a program that will give you the following output: Enter the coordinate of 1st Point:
2 3 Enter the coordinate of 2nd Point: 4 -1 Enter Circle radius: 5 Point(x=2,y=3) Point(x=4,y=-1)
Circle(raius=5.000000,Point(x=4,y=-1)) Distance between p1 and p2 is:4.472136 After moving p1:Point(x=1,y=4)
Is p1 inside circle C? No 
*/

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