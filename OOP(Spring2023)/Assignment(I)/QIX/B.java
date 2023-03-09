package pack2;
// java pack2/B [to run the file]
// java <package>/<class name>

import pack1.A;

public class B{
    public static void main(String[] args){
        A a = new A();
        a.x = 10;
        System.out.println("A.x = " + a.x);
    }
}