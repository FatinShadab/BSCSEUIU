package bin;

class Lion extends Animal {

    public static final String Emojis = "🦁";
    
    Lion(String name, int age, String healthStatus) {
        super(name, age, Emojis, true, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("Roar");
    }

}

class Horse extends Animal {
    
    public static final String Emojis = "🐴";
    
    Horse(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("neigh");
    }
}

class Rabbit extends Animal {
    
    public static final String Emojis = "🐇";
    
    Rabbit(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("cluck");
    }
}

class Bear extends Animal {
    
    public static final String Emojis = "🐻";
    
    Bear(String name, int age, String healthStatus) {
        super(name, age, Emojis, true, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("growl");
    }
}

class Giraffe extends Animal {
    
    public static final String Emojis = "🦒";
    
    Giraffe(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("bleat");
    }
}

class Elephant extends Animal {
    
    public static final String Emojis = "🐘";
    
    Elephant(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("Trumpets");
    }
}

class Tiger extends Animal {
    
    public static final String Emojis = "🐯";
    
    Tiger(String name, int age, String healthStatus) {
        super(name, age, Emojis, true, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("Garr");
    }
}

class Panda extends Animal {
    
    public static final String Emojis = "🐼";
    
    Panda(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("huff");
    }
}

class Zebra extends Animal {
    
    public static final String Emojis = "🦓";
    
    Zebra(String name, int age, String healthStatus) {
        super(name, age, Emojis, false, healthStatus);
    }

    @Override
    public void makeSound(){
        System.out.println("bark");
    }
}

public class Species {
    public static String[] supportedSpecies = {"🦁", "🐴", "🐇", "🐻", "🦒", "🐘", "🐯", "🐼", "🦓"};

    public static Animal getAnimalObject(String speciesEmoji, String name, int age, String healthStatus) {
        switch (speciesEmoji) {
            case "🦁":
                return new Lion(name, age, healthStatus);
            case "🐴":
                return new Horse(name, age, healthStatus);
            case "🐇":
                return new Rabbit(name, age, healthStatus);
            case "🐻":
                return new Bear(name, age, healthStatus);
            case "🦒":
                return new Giraffe(name, age, healthStatus);
            case "🐘":
                return new Elephant(name, age, healthStatus);
            case "🐯":
                return new Tiger(name, age, healthStatus);
            case "🐼":
                return new Panda(name, age, healthStatus);
            case "🦓":
                return new Zebra(name, age, healthStatus);
        }

        return new Rabbit(name, age, healthStatus);
    }
}