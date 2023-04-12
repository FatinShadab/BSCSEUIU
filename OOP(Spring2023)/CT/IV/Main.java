/*
* Given,
*   class C{
*       int a, b, c;
*   }
*
* You are given an arraylist of type C.
*
*   1/ Now sort the arraylist,
*       with respect to the value of “a” in ascending order
*       If a’s values are equal, then sort w.r.t the value of “b” in descending order
*       If b’s values are equal, then sort w.r.t the value of “c” in ascending order
*
*   2/ Solve the same question using at most one “if”, one “else if” and one “else” statement in
*      the compareTo() function.
*/

import java.util.ArrayList;
import java.util.Collections;
import java.lang.Comparable;
import java.util.Scanner;

class C implements Comparable<C>{
    int a, b, c;

    public C(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public int compareTo(C other){
//        Way : 1

//        if (this.a != other.a){
//            return this.a - other.a;
//        }
//        else if (this.b != other.b){
//            return -1 * (this.b - other.b);
//        }
//        else{
//            return this.c - other.c;
//        }

//        Way : 2

//        if (this.b == other.b){
//            return (this.a == other.a) ? this.c - other.c:this.a - other.a;
//        }
//
//        return -1 * (this.b - other.b);

//      Way : 3
        if (this.a > other.a || this.a < other.a){
            return this.a - other.a;
        }
        else if (this.b > other.b || this.b < other.b){
            return -1 * (this.b - other.b);
        }
        else{
            return (this.c - other.c);
        }
    }

    @Override
    public String toString(){
        return "{" + this.a + ", " + this.b + ", " + this.c + "}";
    }
}

public class Main {

    public static void main(String[] args) {
        int Size, a, b, c;

        Scanner input = new Scanner(System.in);
	    ArrayList<C> list = new ArrayList<C>();

        System.out.print("Enter the Element size : ");
        Size = input.nextInt();

        while (Size != 0){
            System.out.print("Enter the value of a, b, c for object : " + (Size-Size+1) + " : ");

            a = input.nextInt();
            b = input.nextInt();
            c = input.nextInt();

            list.add(new C(a, b, c));

            Size--;
        }

        System.out.println("\nBefore Sorting : ");
        System.out.println(list);

        Collections.sort(list);

        System.out.println("After Sorting : ");
        System.out.println(list);
    }
}
