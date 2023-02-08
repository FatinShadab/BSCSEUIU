import java.io.IOException;

public class Poin2DTest{
    public static void main(String[] args) { 
      
      // Creating a object by init method
      
      try{
        Point2D point = new Point2D(3, 5);
        System.out.println("Point2D Instance : " + point.instanceId + " : [x : " + point.x  + ", y: " + point.y + "]");
      }
      catch (IOException e){
        System.out.println(e);
      }
 
      try{
        Point2D point2 = new Point2D(10, 20);
        System.out.println("Point2D Instance : " + point2.instanceId + " : [x: " + point2.x + ", y: " + point2.y + "]");
      }
      catch (IOException e){
        System.out.println(e);
      }
  }
}