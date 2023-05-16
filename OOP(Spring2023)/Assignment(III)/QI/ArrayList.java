/*
    You need to implement search function in the following code. The search function tries
    to find an element using linear search. If the element is not present in the array, then it
    throws "ElementNotFoundException". Also, you need to throw ArrayNotInitializeException
    if the given array has not been instantiated.
*/
import java.lang.NullPointerException;

public class ArrayList{
    int [] arr;

    public boolean search(int element) throws Exception{
        boolean found = false;

        try{
           for(int i = 0; i < arr.length; i++){
                if (arr[i] == element){
                    found = true;
                    break;
                }
           }
        }
        catch (NullPointerException e){
            throw new Exception("ArrayNotInitializeException");
        }

        if (!found){
            throw new Exception("ElementNotFoundException");
        }

        return found;
    }
}