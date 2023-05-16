// Create and assign an object of Vehicle using anonymous inner class for both of Line 6 and 7 to
// produce output “Uses LPG” from line number 9 and "Uses Jet Fuel" from Line number 10:

interface Vehicle{
    void fuelType();
}

public class Spring {
    public static void main(String[] args){
        Vehicle cng;
        Vehicle airplane;

        cng = new Vehicle(){
            public void fuelType(){
                System.out.println("Uses LPG");
            }
        };

        airplane = new Vehicle(){
            public void fuelType(){
                System.out.println("Uses Jet Fuel");
            }
        };

        cng.fuelType();
        airplane.fuelType();
    }
}