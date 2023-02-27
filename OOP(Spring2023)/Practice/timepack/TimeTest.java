public class TimeTest{
  
  public static void timeSwap(Time obj1, Time obj2){
    int tempH = obj1.H;
    int tempM = obj1.M;
    int tempS = obj1.S;
    boolean tempAM = obj1.AM;
    
    obj1.set(obj2);
    obj2.set(tempH, tempM, tempS, tempAM);
    
  }
  
  public static void main(String[] args){
    // Creating OBJ
    Time t1 = new Time();
    Time t2 = new Time(12, 20);
    Time t3 = new Time(23, 11, 12);
    
    // Printing
    System.out.println("Time values After Init :");
    System.out.println(t1);
    System.out.println(t2);
    System.out.println(t3);
    
    // Swap t1 & t3
    timeSwap(t1, t3);
    
    // Printing
    System.out.println("After Swap Time values After Init :");
    System.out.println(t1);
    System.out.println(t2);
    System.out.println(t3);
    
    // Adding OBJ
    t3.add(t1);
    
    // Printing
    System.out.println("Time values After ADD 1 :");
    System.out.println(t3);
    
    // Adding M & S
    t2.add(45, 0);
    
    // Printing
    System.out.println("Time values After ADD 2 :");
    System.out.println(t2);
    
    // Adding H, M & S
    t1.add(1, 10, 0);
    
    // Printing
    System.out.println("Time values After ADD 3 :");
    System.out.println(t1);
  }
  
}  