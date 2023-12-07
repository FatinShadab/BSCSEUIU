package bin;

import java.util.ArrayList;


public class Zone {

    public String name;
    public ArrayList<Animal> animals;
    public Boolean isDangerous = false;

    Zone(String name) {
        this.name = name;
        this.animals = new ArrayList<Animal>();
    }

    Zone(String name, Animal ... animals) {
        this(name);

        for (Animal animal : animals){
            this.addAnimal(animal);
        }
    }

    public void addAnimal(Animal animal) {
        if (animal.isDangerous) {
            this.isDangerous = true;
        }

        animals.add(animal);
    }

    @Override
    public String toString() {
        String returnObj = "Zone Name : " + this.name + "\nZone Animals Status :\n";

        for (Animal animal : this.animals) {
            returnObj += animal.toString();
            returnObj += "\n";
        }

        return returnObj;
    }
}
