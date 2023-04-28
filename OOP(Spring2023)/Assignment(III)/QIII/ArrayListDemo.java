/**
 * Consider the following codes and complete the three tasks below:
 * 
 *  i.  Override the equals method in the Student class so that two students are considered equal if
 *      their name is matched.
 * 
 *  ii. Call the contains method of the alist object in Line No 26 to check whether the Student
 *      object: query exists in it or not.
 * 
 *  iii.Sort the alist in descending order of age of the Students must using an anonymous inner
 *      class of the Comparator (You must use the sort method of the Collections class)
 */
import java.util.*;


class Student{
    public String name;
    public int age;
    public double cgpa;

    public Student(String name, int age, double cgpa){
        this.name = name;
        this.age = age;
        this.cgpa = cgpa;
    }

    // i
    @Override
    public boolean equals(Object other){
        if (!(other instanceof Student)) {
            return false;
        }
        Student otherStudent = (Student) other;
        return this.name.equals(otherStudent.name);
    }

    public String toString(){
        return "{Student Name: " + name +", Student Age: " + age + ", Student cgpa: " + cgpa + "}";
    }
}


public class ArrayListDemo{
    public static void main(String args[]){
        ArrayList <Student> alist = new ArrayList<>();

        alist.add(new Student("Sonet", 15, 3.8));
        alist.add(new Student("Zhang", 17, 3.9));
        alist.add(new Student("Buffon", 20, 3.6));

        Student query = new Student("Zhang", 0, 0);

        // ii
        System.out.println("alist contains query ? => " + ((alist.contains(query)) ? "True":"False"));

        // iii
        Collections.sort(alist, new Comparator<Student>(){
            public int compare(Student s1, Student s2){
                return -1 * (s1.age - s2.age);
            }
        });

        for (Student s : alist){
            System.out.println(s);
        }
    }
}