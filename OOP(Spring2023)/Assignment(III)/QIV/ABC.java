/*
Suggest changes to the provided three classes for the following tasks:
    
    i. Make the variable “m” both accessible from “method2” of class A and read-only once
        initialized
    ii. If any class inherits class “B”, prevent the “method1” from being overridden. But it should be
        allowed to override if any class inherits from class “A” or “C”
    iii. Make sure class “C” cannot be inherited

N.B. Just write only the modified lines
*/


class A{
    // i
    static final int m = 10;

    void method1(int t){
        System.out.println(t);
    }

    static void method2(){
        System.out.println("m : " + m);
    } 
}


class B extends A{
    final void method1(int t){
        System.out.println(t);
    }
}


final class C extends A{
    void method1(int t){
        System.out.println(t);
    }
}


public class ABC{
    public static void main(String[] args){

        A a = new A();
        B b = new B();
        C c = new C();

        a.method2();
        a.method1(1);

        return;
    }
}