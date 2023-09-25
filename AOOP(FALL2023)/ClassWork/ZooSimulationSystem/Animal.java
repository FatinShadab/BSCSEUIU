package bin;


public abstract class Animal {
    public String name;
    public int age;
    public String species;
    public String healthStatus;
    public Boolean isDangerous;

    Animal(String name, int age, String species, Boolean isDangerous, String healthStatus) {
        this.name = name;
        this.age = age;
        this.species = species;
        this.isDangerous = isDangerous;
        this.healthStatus = healthStatus;
    }

    public abstract void makeSound();

    @Override
    public String toString() {
        return "Name : " + this.name + ", Health Status: " + this.healthStatus;
    }
}
