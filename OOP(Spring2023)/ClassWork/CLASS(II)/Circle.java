/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circlemath;
import circlemath.Point;
/**
 *
 * @author student
 */
public class Circle {
    private Point center;
    private double radius;
    
    public Circle(){
        this.center = new Point();
        this.radius = 0.00;
    }
    
    public Circle(Point center, double radius){
        this.center = center;
        this.radius = radius;
    }
    
    public void setCenter(Point center){
        this.center = center;
    }
    
    public void setRadius(double radius){
        this.radius = radius;
    }
    
    public Point getCenter(){
        return this.center;
    }
    
    public double getRadius(){
        return this.radius;
    }
    
    public boolean inside(Point p){
        return this.center.getDistance(p) <= this.radius;
    }
}
