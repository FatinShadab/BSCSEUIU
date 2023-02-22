// Topic : Inheritance 

class Point2D{
    int x, y;
    
    public Point2D(){
        this.x = this.y = 1;
    }
    
    public Point2D(int a){
        this.x = this.y = a;
    }
    
    public Point2D(int x, int y){
        this.x = x;
        this.y = y;
    }
}


class Point3D extends Point2D{
    int z;
    
    public Point3D (){
        super();
        this.z = 1; 
    }
    
    public Point3D (int a){
        super(a);
        this.z = a;
    }
    
    public Point3D (int x, int y, int z){
        super(x, y);
        this.z = z;
    }
}


public class Test{
    public static void main(String[] args){
        Point3D point = new Point3D(1, 2, 3);
        System.out.println(point.x + " " + point.y + " " + point.z);
        
        // Sub Topic : class down casting
        Point2D p;
        Point3D p2;
        p = new Point3D(0, 1, 0);
        p2 =(Point3D)p;
        //p2 = (Point3D)p;
        
        
        System.out.println(p2.z);
    }
}
