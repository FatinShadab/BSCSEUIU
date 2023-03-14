package transport;

// Task (I)  :
    // Make sure no other classes have direct
    // access to "noOfWeels" in Vehicle.

// Task (II) :
    // Make sure "noOfWheels" in 'Vehicle' is
    // read-only both from inside and outside
    // of the 'transport' package (the value 
    // can be set only within the constructor)

public class Vehicle{
    // Task (I)
    private int noOfWheels; 

    // Task (II)
    public Vehicle(int noOfWheels){
        this.noOfWheels = noOfWheels;
    }

    // Task (II)
    public int getWheelQuantity(){
        return this.noOfWheels;
    }
}