package bin;


public class Zookeeper extends Person{
    public Zone inChargeOfZone;

    Zookeeper (String name, int age, Zone zone) {
        super(name, age);
        this.inChargeOfZone = zone;
    }

    public void attendAnimalsOfZone() {
        for (Animal animal : inChargeOfZone.animals) {

            System.out.println("\n-------->\nAttending ["+ animal.species + "] "+ animal.toString());
            System.out.print("["+ animal.name + "] :");
            animal.makeSound();

            if (!animal.healthStatus.equals("Healthy")) {
                System.out.println("Applying Medicine ...");
                System.out.print("["+ animal.name + "] :");
                animal.makeSound();
                animal.healthStatus = "Healthy";
            }

            System.out.println("Completed Checkup ["+ animal.species + "] "+ animal.toString());
            System.out.print("["+ animal.name + "] :");
            animal.makeSound();
        }
    }

    @Override
    public String toString() {
        return "Name: " + name + ", in charge of zone : " + inChargeOfZone.name;
    }
}
