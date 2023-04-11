import java.util.Scanner;

public class Demo{
    public static void main(String[] args){
        try {
            Scanner sc = new Scanner(System.in);

            int a = 5;
            int b = sc.nextInt();

            System.out.println(a / b);
        }
        catch (ArithmeticException e) {
            e.printStackTrace();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        finally {
            System.out.println("After exception");
        }
        System.out.println("outside finally block");
    }
}