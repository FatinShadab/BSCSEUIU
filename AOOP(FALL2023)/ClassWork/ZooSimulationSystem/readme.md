# Zoo Simulation System Question
---
## Index

* [Background](#background)
* [Requirements](#requirements)
* [Tasks](#tasks)
* [How To Run](#how-to-run)
* [Pictures](#pictures)
---
## Background:
---
  You are tasked with designing and implementing a basic system for managing a zoo. The zoo has different types of animals, different zones where they live, and individuals like zookeepers and visitors who interact with these zones.

## Requirements:
---

### Person Class:
---
 A base class that represents any person in the zoo environment.
 Every person has a name and age.
 This class should be abstract, with common functionalities or attributes that both Zookeeper and Visitor can inherit.

### Animal Class:
---
 Each animal has a name, age, species, and health status (e.g., Healthy, Ill, Recovering).
 Animals can make a sound (each species has its unique sound).
 Implement at least two types of animals (e.g., Lion and Zebra). They should inherit from the Animal class.

### Zone Class:
---
 A zone has a name and an array of animals.
 Zones can provide a summary of all animals living in them.

### Zookeeper Class (inherits from Person):
---
 Each zookeeper has a specific zone they are responsible for.
 Zookeepers can attend to sick animals, which will change the health status of the animal.

### Visitor Class (inherits from Person):
---

 Visitors can view a list of animals in a specific zone.
 Implement a feature where young visitors (e.g., age < 12) are warned if they are viewing zones with potentially dangerous animals.

### Main Zoo Simulation Class:
---
 Implement a class (e.g., Zoo) to manage the overall operations.
 This class should be able to add new animals, zones, zookeepers, and visitors.
 Implement a method to get a summary of the zoo, which includes the number of animals, zones, zookeepers, and visitors.

## Tasks:
 - Design the class structure based on the requirements given above. Ensure that you leverage the Person class appropriately for inheritance.

 - Implement basic operations like adding new animals, assigning them to zones, adding zookeepers, and letting visitors view zones.

 - Implement special features like the health status for animals, attending to animals, and warning for young visitors.
 
 - Demonstrate the working of your Zoo Simulation System with a sample driver class where you create objects, simulate operations, and display results.

## How To Run
---
- compile all the java files using
```
javac -d . '$file_name'.java
```

- After done compiling run the 'Zoo.java' using
```
java bin.Zoo
```

## Pictures

> Home Page : Selection Menu
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/home.png" alt="Home window">

> Adding Zone
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/adding_zone.png" alt="Zone adding window">

> Notification In Selection Menu
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/notification.png" alt="Notification System">

> Adding Animals
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/adding_animals.png" alt="Animal window">

> Adding Zookeepers
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/adding_zookeper.png" alt="Zookeepers Window">

> Adding Visitors
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/adding_visitors.png" alt="Visitors window">

> Simulation
<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/simulation.png" alt="simulation png">

<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/zookeeper_simulation.png" alt="simulation 2">

<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/simulation_visitor_1.png" alt="simulation 3">

<img src="https://github.com/FatinShadab/BSCSEUIU/blob/main/AOOP(FALL2023)/ClassWork/ZooSimulationSystem/images/simulation_visitor_2.png" alt="simulation 4">