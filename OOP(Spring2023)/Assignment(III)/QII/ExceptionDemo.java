/**
 * ii.Provide logical implementation so that if age is below 50 then throw an exception of
 *    InvalidUserException class with the message “Ineligible for Elderly pension because of age”, if
 *    work_experience is below 20 then throw an exception of InvalidUserException class with the
 *    message “Ineligible for Elderly pension because of work experience”.
 */
public class ExceptionDemo{
    void UserCheck(int age, int work_experience) throws InvalidUserException{
        String exception_msg = null;
        boolean throw_exception = false;

        if (age < 50){
            exception_msg = "Ineligible for Elderly pension because of age";
            throw_exception = true; 
        }

        else if (work_experience < 20){
            exception_msg = "Ineligible for Elderly pension because of work experience";
            throw_exception = true; 
        }

        if (throw_exception){
            throw new InvalidUserException(exception_msg);
        }
    }    
}