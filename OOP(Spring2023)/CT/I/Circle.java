/**
 * Auto Generated Java Class.
 */
public class Circle {
  public Point centerPoint;
  public double radius;
  
  public Circle(){
    this.centerPoint = new Point();
    this.radius = 0.0;
  }
  
  public Circle(Point cP, double radius){
    this.centerPoint = cP;
    this.radius = radius;
  }
  
  public void resetCircle(Point newCP, double newRadius){
    this.centerPoint = newCP;
    this.radius = newRadius;
  }
  
  public double getArea(){
    return 3.1416*(this.radius*this.radius);
  }
  
  public double getPerimeter(){
    return 2 * 3.1416*this.radius;
  }
  
  public boolean InsideCircle(Circle c){
    return (c.centerPoint.getDistance(this.centerPoint) + this.radius) < c.radius;
  }
  
  public boolean circleInside(Circle c){
    return (this.centerPoint.getDistance(c.centerPoint) + c.radius) < this.radius;
  }
}
