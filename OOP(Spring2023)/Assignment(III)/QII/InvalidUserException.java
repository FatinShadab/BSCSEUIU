/******
 * 
 * i. Create a user-defined exception class named InvalidUserException that extends the Exception 
 * class and prints the messages provided below using the super constructor.
 * 
******/
public class InvalidUserException extends Exception{
    public InvalidUserException(String msg){
        super(msg);
    }
}