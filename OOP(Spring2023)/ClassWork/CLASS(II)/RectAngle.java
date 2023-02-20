/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import circlemath.Point;
/**
 *
 * @author student
 */
public class RectAngle {
    private Point[] points = new Point[4];
    
    public RectAngle (){
        for (Point p : this.points){
            p = new Point();
        }
    }
    
    public RectAngle (Point p1, Point p2, Point p3){
        this.points[0] = p1;
        this.points[1] = p2;
        this.points[2] = p3;
        this.points[3] = new Point(p1.gettX(), p3.getY());
    }
    
    public boolean inside (Point p){
        return (p.gettX() >= this.points[0].gettX() && p.gettX() <= this.points[1].gettX()) && (p.getY() >= this.points[0].getY() && p.getY() <= this.points[3].getY());
    }
}
