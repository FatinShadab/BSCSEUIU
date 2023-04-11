import java.util.ArrayList;
import java.util.Collections;

public class OrderChain{
    public static void main(String[] args){

        String[] pName = {
            "Head Of HR",
            "CO Head Of HR",
            "Executive Member",
            "Member"
        }; 

        Integer[] pLevel =  {
            0, // Head Of HR
            1, // CO Head Of HR
            2, // Executive Member
            3  // Member
        };

        ArrayList <Employee> employee_list = new ArrayList <Employee>();
        
        for (int idx=3; idx >= 0; idx--){
            employee_list.add(new Employee(pName[idx], pLevel[idx]));
        }

        for (Employee emp : employee_list){
            System.out.println(emp);
        }
        
        Collections.sort(employee_list);
        
        for (Employee emp : employee_list){
            System.out.println(emp);
        }
    }
}
