/********
 * iii. Invoke the UserCheck() method using proper try-catch block. You catch block should print
 *      a message “Caught the exception” and print the correct message from (ii).
 *******/
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        ExceptionDemo obj = new ExceptionDemo();
        Scanner input = new Scanner(System.in);
        
        int age = input.nextInt();
        int work_experience = input.nextInt();

        try{
            obj.UserCheck(age, work_experience);
        }
        catch (InvalidUserException e){
            System.out.println("Caught the exception :\n\t" + e);
        }
    }
}