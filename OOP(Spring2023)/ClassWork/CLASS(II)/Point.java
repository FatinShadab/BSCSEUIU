/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.lang.Math;
/**
 *
 * @author student
 */
public class Point {
    private double x;
    private double y;
    
    public Point(){
        this.x = 0.0;
        this.y = 0.0;
    }
    
    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }
    
    public void setX(double x){
        this.x = x;
    }
    
    public void setY(double y){
        this.y = y;
    }
    
    public double getX(){
        return this.x;
    }
    
    public double getY(){
        return this.y;
    }
    
    public double getDistance(Point p){
        return Math.pow((Math.pow((this.x - p.getX()), 2) + Math.pow((this.y - p.getY()), 2)), 1/2);
    }
}
