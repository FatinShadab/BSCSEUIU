/**
 * Auto Generated Java Class.
 */
import java.lang.Math;

public class Point {
  
  private int X, Y;

  public Point(){
    this.X = 0;
    this.Y = 0;
  }
  
  public Point(int x, int y){
    this.X = x;
    this.Y = y;
  }
  
  public void setTo(int newX, int newY){
    this.X = newX;
    this.Y = newY;
  }
  
  public int[] getCoordinates(){
    int[] coordinates = new int[2];
    
    coordinates[0] = this.X;
    coordinates[1] = this.Y;
    
    return coordinates;
  }
  
  public double getDistance(Point p){
    int[] pCoords = p.getCoordinates();
    return Math.pow((Math.pow((this.X - pCoords[0]), 2) + Math.pow((this.Y - pCoords[1]), 2)), 1/2);
  }
}
