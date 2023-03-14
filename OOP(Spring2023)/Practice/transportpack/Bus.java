package publicTransport;

// Task (III) : 
    // Make sure the 'Bus extends Vehicle' line does not throw any error.
// Task (IV) :
    // Resolve any error that might be thrown by the constructor of 
    // class 'Bus'.
// Task (V) :
    // Enable read and write access to 'licenseNo' of the class 'Bus'
    // without changing the given access modifier.

// Task (III)
import transport.Vehicle;


public class Bus extends Vehicle{
    private int licenseNo;

    public Bus(int licenseNo){
        // Task (IV)
        super(4);
        this.licenseNo = licenseNo;
    }

    // Task (V)
    public void set_licenseNo(int licenseNo){
        this.licenseNo = licenseNo;
    }

    // Task (V)
    public int get_licenseNo(){
        return this.licenseNo;
    }

}