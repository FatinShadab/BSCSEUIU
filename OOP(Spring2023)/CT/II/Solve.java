/*
    Define a Rectangle class with a constructor that takes two parameters for the width and height,
    and methods for calculating the area and perimeter of the rectangle. Then, define a Square
    class that extends Rectangle and has a constructor that takes a single parameter for the side
    length. Implement the Square class such that it reuses the Rectangle constructor and inherits
    the getArea() and getPerimeter() methods from Rectangle. Finally, create instances of both
    Rectangle and Square in a Main class, and call the getArea() and getPerimeter() methods on
    each object.

    Also, define a Circle class that extends Square class and has a constructor that takes a single
    parameter for the radius. Implement the Circle class such that it reuses the Square constructor
    and uses the getArea() and getPerimeter() methods from Square.
*/
interface GeometricObj{
    double getArea();
    double getPerimeter();
}

class Rectangle implements GeometricObj{
    double width, height;

    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }

    public double getArea(){
        return this.width * this.height;
    }

    public double getPerimeter(){
        return 2 * (this.width + this.height);
    }
}


class Square extends Rectangle{
    public Square(double side_len){
        super(side_len, side_len);
    }
}


class Circle extends Square{
    static final double PI = 3.1416;

    public Circle(double rad){
        super(rad);
    }

    @Override
    public double getArea(){
        return PI * super.getArea();
    }

    @Override
    public double getPerimeter(){
        return PI * (super.getPerimeter()/2);
    }
}


public class Solve{
    public static void main(String[] args){
        GeometricObj rect = new Rectangle(4, 5);
        GeometricObj sqr = new Square(5);
        GeometricObj cle = new Circle(5);

        System.out.println("Rectangle Area : " + rect.getArea() + ", Perimeter : " + rect.getPerimeter());
        System.out.println("Square Area : " + sqr.getArea() + ", Perimeter : " + sqr.getPerimeter());
        System.out.println("Circle Area : " + cle.getArea() + ", Perimeter : " + cle.getPerimeter());
    }
}