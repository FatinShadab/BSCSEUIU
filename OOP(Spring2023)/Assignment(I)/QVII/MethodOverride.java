class Base{
    public int a;
    private double b;

    Base(int a, double b){
        this.a = a;
        this.b = b;
    }

    Base(Base ob){
        this.a = ob.a;
        this.b = ob.b;
    }

    // sovle : 1 (start)
    public void set_b(double b){
        this.b = b;
    }

    public double get_b(){
        return this.b;
    }
    // solve 1 (end)

    void show(){
        System.out.println("Sum of variables " + "In the Base class " + a+b);
    }
}

class Override extends Base{
    int c;

    // solve : 2 (start)
    public Override(int a, double b, int c){
        super(a, b);
        this.c = c;
    }
    // solve : 2 (end)

    // solve : 3 (start)
    public void show(){
        System.out.println("Sum of variables " + "In the Override class " + a+super.get_b()+c);
    }
    // solve : 3 (end)
}

class Override2 extends Base{
    Override2(int a, double b){
        super(a, b);
    }

    // solve : 4 (start)
    Override2(Base obj){
        super(obj);
    }
    // solve : 4 (end)

    // solve : 5 (start)
    public void show(){
        System.out.println("Sum of variables " + "In the Override2 class " + a+super.get_b());
    }
    // solve : 5 (end)
}

class MethodOverride {
    public static void main(String[] args){
        Override obj = new Override(10, 20.5, 12);
        obj.show();
        Override2 obj2 = new Override2(6, 10);
        obj2.show();
        Override2 obj3 = new Override2(obj2);
        obj3.show();
    }
}