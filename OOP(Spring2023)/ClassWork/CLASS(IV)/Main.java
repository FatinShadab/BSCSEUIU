// Topic : Concrete/Abstract/Interface

interface Vehical{
    void move();
    void permission();
}


interface MotorVehicle extends Vehical{
    void refill_tank();
}


class Rickshaw implements Vehical{
    public void move(){
        System.out.println("Paddling the chain");
    }

    public void permission(){
        System.out.println("Rickshaw can move in narrow streets");
    }
} 


class CNG implements MotorVehicle{
    public void move(){
        System.out.println("Burning engine fuel");
    }

    public void permission(){
        System.out.println("CNG can move in city streets");
    }

    public void refill_tank(){
        System.out.println("Filled with fuel");
    }
}


class Car implements MotorVehicle{
    public void move(){
        System.out.println("Burning engine fuel");
    }

    public void permission(){
        System.out.println("Car can move in highway");
    }

    public void refill_tank(){
        System.out.println("Filled with fuel");
    }
}


class Bus implements MotorVehicle{
    public void move(){
        System.out.println("Burning engine fuel");
    }

    public void permission(){
        System.out.println("Bus can move in expressway");
    }

    public void refill_tank(){
        System.out.println("Filled with fuel");
    }
}


public class Main{
    public static void main(String[] args){
        Vehical rickshaw = new Rickshaw();
        Vehical cng = new CNG();
        Vehical car = new Car();
        Vehical bus = new Bus();

        rickshaw.move();
        cng.move();
        car.move();
        bus.move();

        System.out.println();

        rickshaw.permission();
        cng.permission();
        car.permission();
        bus.permission();

        System.out.println();

        ((MotorVehicle) cng).refill_tank();
        ((MotorVehicle) car).refill_tank();
        ((MotorVehicle) bus).refill_tank();
    }
}