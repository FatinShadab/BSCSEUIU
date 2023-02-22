// TOPIC : INHERITANCE

class A{
    int i, j;
    
    public A(){}
    
    public A(int i, int j){
        this.i = i;
        this.j = j;
    }
    
    public void showI(){
        System.out.println(this.i);
    }
    
    public void showJ(){
        System.out.println(this.j);
    }
}


class B extends A{
    int k;
    
    public B(int i, int j, int k){
        super(i, j);
        this.k = k;
    }
    
    public void showK(){
        System.out.println(this.k);
    }
}


public class Inheritance {
    public static void main(String[] args){
        B b = new B(1, 2, 3);
        
        b.showI();
        b.showJ();
        b.showK();
    }
}


