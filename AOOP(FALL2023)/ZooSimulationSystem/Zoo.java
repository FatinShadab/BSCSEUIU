package bin;

import java.util.Scanner; 
import java.util.ArrayList;
import java.util.Random;


public class Zoo {

    private static Boolean simulationActiveStatus = true;
    private static Scanner input = new Scanner(System.in);
    private static String msg = null;
    private static Random rand = new Random();
    private static Boolean hasAnimal = false;

    private static ArrayList<Zone> zones = new ArrayList<Zone>();
    private static ArrayList<Zookeeper> zookeepers = new ArrayList<Zookeeper>();
    private static ArrayList<Visitor> visitors = new ArrayList<Visitor>();

    public static void clearScreen() {  
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    }

    public static void showHeader() {
        if (msg != null) {
            System.out.println(" *** Notification : " + msg);
        }
        System.out.println("+----------------------------------------+");
        System.out.println("|         Virtual Zoo Simulation         |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 0 | Quit                               |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 1 | Add Zone                           |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 2 | Add Animal                         |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 3 | Add Zookeeper                      |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 4 | Add Visitor                        |");
        System.out.println("+----------------------------------------+");
        System.out.println("| 5 | Random Zoo day simulation          |");
        System.out.println("+----------------------------------------+");
    }

    public static void addZone() {
        clearScreen();
        int zoneQuantity;
        String zoneName;

        System.out.print("Enter the number of how many zones you wnat to add : ");
        zoneQuantity = input.nextInt();
        input.nextLine();

        while (zoneQuantity != 0) {
            
            System.out.print("Enter the name of the zone : ");
            zoneName = input.nextLine();
    
            zones.add(new Zone(zoneName));

            zoneQuantity -= 1;

            System.out.println("\n----------\n'" + zoneName + "' is added.\n----------\n");
        }

        msg = "Zones added successfully.";
    }

    public static void addAnimal() {
        clearScreen();
        int numberOfAnimals;
        String animalName;
        int animalAge;
        String animalSpecies = "";
        String animalHealthStatus;
        String zoneName;
        Boolean validZoneName = false;
        Boolean validSpecies = false;

        if (zones.size() == 0) {
            msg = "Please add a 'Zone' before adding Animals";
            return;
        }

        System.out.print("Enter the number of how many animals you wnat to add : ");
        numberOfAnimals = input.nextInt();
        input.nextLine();

        while (numberOfAnimals != 0) {

            System.out.println("Supported species in the zoo : ");
            for (String spEmoji : Species.supportedSpecies) {
                System.out.print(spEmoji + " ");
            }

            while (!validSpecies) {
                System.out.print("\nEnter the species emoji of the animal from above : ");
                animalSpecies = input.nextLine();

                for (String spEmoji : Species.supportedSpecies) {
                    if (spEmoji.equals(animalSpecies)) {
                        validSpecies = true;
                        break;
                    }
                }
            }

            System.out.print("Enter the name of the animal : ");
            animalName = input.nextLine();

            System.out.print("Enter the age of the animal : ");
            animalAge = input.nextInt();
            input.nextLine();

            System.out.print("Enter the health status of the animal : ");
            animalHealthStatus = input.nextLine();

            Animal animal = Species.getAnimalObject(
                animalSpecies,
                animalName,
                animalAge,
                animalHealthStatus
            );

            System.out.print("\n----------\n[" + animalSpecies + "] " + animalName + ": ");
            animal.makeSound();
            System.out.print("----------\n");
            

            System.out.println("Available Zones : ");
            for (Zone zone : zones) {
                System.out.println("\t* zone name : " + zone.name + ", animals : " + zone.animals.size());
            }

            while (!validZoneName) {
                System.out.print("Enter the zone name to keep the animal : ");
                zoneName = input.nextLine();

                for (Zone zone : zones) {
                    if (zone.name.equals(zoneName)) {
                        validZoneName = true;

                        zone.addAnimal(animal);

                        break;
                    }
                }
            }

            validSpecies = false;
            validZoneName = false;

            numberOfAnimals -= 1;

            System.out.println("\n----------\n" + animalName + "' is added.\n----------\n");
        }

        hasAnimal = true;
        msg = "Animals added successfully.";
    }

    public static void addZookeeper() {
        clearScreen();

        int numberOfZookeepers;
        String keeperName;
        int keeperAge;
        String zoneName;
        Boolean validZoneName = false;

        if (zones.size() == 0) {
            msg = "Please add a 'Zone' before adding Zoo-keepers";
            return;
        }

        System.out.print("Enter the number of how many zoo-keepers you wnat to add : ");
        numberOfZookeepers = input.nextInt();
        input.nextLine();

        while (numberOfZookeepers != 0) {
            System.out.print("Enter the name of the zoo-keeper : ");
            keeperName = input.nextLine();

            System.out.print("Enter the age of the zoo-keeper : ");
            keeperAge = input.nextInt();
            input.nextLine();

            System.out.println("Available Zones : ");
            for (Zone zone : zones) {
                System.out.println("\t* zone name : " + zone.name + ", animals : " + zone.animals.size());
            }

            while (!validZoneName) {
                System.out.print("Enter the zone name to assign the zoo-keeper : ");
                zoneName = input.nextLine();

                for (Zone zone : zones) {
                    if (zone.name.equals(zoneName)) {
                        validZoneName = true;

                        zookeepers.add(new Zookeeper(
                            keeperName,
                            keeperAge,
                            zone
                        ));

                        break;
                    }
                }
            }

            System.out.println("\n----------\n'" + keeperName + "' is added.\n----------\n");

            validZoneName = false;
            
            numberOfZookeepers -= 1;
        }

        msg = "Zoo-keepers added successfully.";
    }

    public static void addVisitor() {
        clearScreen();

        int numberOfVisitors;
        String visitorName;
        int visitorAge;

        System.out.print("Enter the number of how many visitors you wnat to add : ");
        numberOfVisitors = input.nextInt();
        input.nextLine();

        while (numberOfVisitors != 0) {

            System.out.print("Enter the name of the visitor : ");
            visitorName = input.nextLine();

            System.out.print("Enter the age of the visitor : ");
            visitorAge = input.nextInt();
            input.nextLine();

            visitors.add(new Visitor(
                visitorName,
                visitorAge
            ));

            System.out.println("\n----------\n'" + visitorName + "' is added.\n----------\n");

            numberOfVisitors -= 1;
        }

        msg = "Visitors added successfully.";
    }

    public static void randomSimulation() {
        if ((zones.size() * zookeepers.size() * visitors.size() == 0) || !hasAnimal) {
            msg = "Please Setup the Zoo before Simulation !!!";
            return;
        }
        
        System.out.println("<#####################################>\n\n");

        System.out.println("Zones :");
        for (Zone zone : zones) {
            System.out.println("=====================================>");
            for (Animal animal : zone.animals) {
                System.out.print(animal.species + " ");
            }
            System.out.println("\n=====================================>");
            System.out.println(zone);
            System.out.println("=====================================>");
        }

        System.out.println("\n\n <#####################################>\n\n");

        System.out.println("Zookeepers checking the animals : ");
        for (Zookeeper zookeeper : zookeepers) {
            System.out.println("=====================================>");
            System.out.println(zookeeper);
            zookeeper.attendAnimalsOfZone();
        }

        System.out.println("\n\n <#####################################>\n\n");

        System.out.println("\n\nVisitor's activity :");
        for (Visitor visitor : visitors) {
            System.out.println("=====================================>");
            Zone zone = zones.get(rand.nextInt(1000)%zones.size());

            System.out.println(visitor.name + "is going to Zone : " + zone.name);

            visitor.viewZone(zone);
        }

        System.out.println("\n\n <#####################################>\n\n");

        System.out.println("Enter to 'q' to stop 'c' to continue [q/c] : ");
        String choice = input.next();

        switch (choice) {
            case "c":
                clearScreen();
                randomSimulation();
            default:
                return;
        }

    }

    public static void main(String args[]) {
        int userSelection;

        while (simulationActiveStatus) {
            clearScreen();
            showHeader();
            
            System.out.print("Select a valid option from above : ");
            userSelection = input.nextInt();

            msg = null;

            switch (userSelection) {
                case 0:
                    clearScreen();
                    simulationActiveStatus = false;
                    break;

                case 1:
                    addZone();
                    break;

                case 2:
                    addAnimal();
                    break;

                case 3:
                    addZookeeper();
                    break;

                case 4:
                    addVisitor();
                    break;

                case 5:
                    randomSimulation();
                    break;
            }
        }
        
    }
}
