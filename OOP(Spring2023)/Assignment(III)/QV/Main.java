/*
Write codes to complete the following the two tasks for the provided codes:
    
    i. Find whether any student object with name "Peter" exists in the list using the contains method
    of the "list" object. Add required methods into the "Student" class to use the contains method
    
    ii. Now sort the "list" in descending order of CGPA using Comparator
*/
import java.util.*;


class Student{
    String name;
    int id;
    double cgpa;

    public Student(String name, int id, double cgpa){
        this.name = name;
        this.id = id;
        this.cgpa = cgpa;
    }

    public Student(String name){
        this.name = name;
        this.id = -1;
        this.cgpa = -1;
    }

    public boolean equals(Object other){
        if (other instanceof Student) {
            Student otherStudent = (Student) other;
            return this.name.equals(otherStudent.name) &&
                this.id == otherStudent.id &&
                this.cgpa == otherStudent.cgpa;
        }
        return false;
    }

    public String toString(){
        return name + " --> " + cgpa;
    }
}


public class Main{
    public static void main(String[] args){
        ArrayList<Student> list = new ArrayList();

        list.add(new Student("Wizard", 3, 3.88));
        list.add(new Student("Peter", 2, 3.5));
        list.add(new Student("Wanda", 1, 3.88));
        list.add(new Student("Thanos", 41, 3.9));
        list.add(new Student("Yelena", 7, 3.75));
        list.add(new Student("Thor", 15, 3.89));
        //list.add(new Student("Peter"));

        Student query = new Student("Peter");

        System.out.println(list.contains(query));

        Collections.sort(list, new Comparator<Student>(){
            public int compare(Student s0, Student s1){
                if (s0.cgpa > s1.cgpa){
                    return -1;
                }
                else if (s0.cgpa < s1.cgpa){
                    return 1;
                }
                
                return 0;
            }
        });

        for (Student s : list){
            System.out.println(s);
        }
    }
}