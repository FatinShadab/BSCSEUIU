/*
There is a class Person having member variables id, name, height (meter in double), weight kg (in double):

```
    class Person{
        double id, height, weight;
        String name;
    }

You can assume that the constructor needed for the code is already written in the Person class.

There is another class Test, and the class looks like this:

```
    public class Test{
        public static void main(String args[]){
            Person p = new Person();
            p.id = 1; //error
            p.name = “Steven”; //error
        }
    }
```

When you try to access the id and name of Person p directly, it throws an error (see the Test class
code). 

Tasks:
    i. What is the reason for this error? Modify the Person class without changing the access
        modifier so that we can access the id and name from the Test class.
        [
            The reason for the error is that the id and name instance variables of the Person class 
            are declared with the default access modifier, which means they are only accessible within the same package.

            To access the id and name from the Test class, we need to either change the access modifier of 
            the instance variables to public or provide public getter and setter methods.
        ]

    ii. Suppose you want to measure BMI for a Person “p1” from another class in the same file.
        Formula to calculate BMI is:

            BMI = weight / (height * height)

        Now modify the Person class to measure BMI where height and weight is no way accessible
        from the other classes than the Person class itself.

    iii. Declare an array of length 3 where each index in the array refers to a Person object.
*/

class Person{
    // for this example we are setting the modifiers to private
    private double id, height, weight;
    private String name;

    // id setter
    public void set_id(double id){
        this.id = id;
    }
    // id getter
    public double get_id(){
        return this.id;
    }
    // height setter
    public void set_height(double height){
        this.height = height;
    }
    // height getter
    public double get_height(){
        return this.height;
    }
    // weight setter
    public void set_weight(double weight){
        this.weight = weight;
    }
    // weight getter
    public double get_weight(){
        return this.weight;
    }
    // name setter
    public void set_name(String name){
        this.name = name;
    }
    // name getter
    public String get_name(){
        return this.name;
    }

    public double get_bmi(){
        return this.weight / (this.height * this.height);
    }
}


public class Test{
    public static void main(String args[]){
        Person[] persons = new Person[3];

        persons[0] = new Person();

        persons[0].set_id(1);
        persons[0].set_name("Steven");

        persons[0].set_height(1.6764);
        persons[0].set_weight(90.50);

        System.out.println(persons[0].get_name() + "'s bmi : " + persons[0].get_bmi());
    }
}
