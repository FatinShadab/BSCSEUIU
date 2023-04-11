import java.lang.Comparable;

public class Employee implements Comparable<Employee>{
    String position_name;
    int position_level;

    public Employee(String pName, int pLevel){
        this.position_name = pName;
        this.position_level = pLevel;
    }
    
    public int compareTo(Employee other){
      // the sort function asks if self is greater then other ?
      // returns -1  : if self is < other
      // returns 1 : if self is > other
      // returns 0 : if self is == other
      
      if (this.position_level < other.position_level){
        return -1;
      }
      
      else if (this.position_level > other.position_level){
        return 1;
      }
      
      else{
        return 0;
      }
    }

    public String toString(){
        return "Position Name : " + this.position_name
                + "\nPosition Level : " + this.position_level + "\n";
    }
}
