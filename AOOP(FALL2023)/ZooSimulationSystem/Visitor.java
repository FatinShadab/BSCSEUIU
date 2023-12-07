package bin;

public class Visitor extends Person{
    Visitor (String name, int age) {
        super(name, age);
    }

    public void viewZone(Zone zoneToview) {
        if (zoneToview.isDangerous && this.age <= 12) {
            System.out.println("[Zoo authority Miking] The zone is dangerous for you to explore alone !");
        }

        System.out.println(zoneToview);

        for (Animal animal : zoneToview.animals) {
            System.out.print("Infront of [" + animal.species +"] " + animal.name + " : ");
            animal.makeSound();
        }
    }
}
