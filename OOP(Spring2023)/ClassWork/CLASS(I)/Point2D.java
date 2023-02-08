/**
 * Auto Generated Java Class.
 */
import java.io.IOException;
  
public class Point2D {
  protected static int maxInstance = 0;
  protected int instanceId;
  public int x, y;
  
   public void MaxlimitError() throws IOException{
    if (maxInstance >= 1){
      throw new IOException("Max Instance Limit Reached !"); 
    }
  }
  
  Point2D() throws IOException{
    this.MaxlimitError();
  }
  
  Point2D(int x, int y) throws IOException{
    this.MaxlimitError();
    this.instanceId = maxInstance++;
    this.x = x;
    this.y = y;
  }
  
}
