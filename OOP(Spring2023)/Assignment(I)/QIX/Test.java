class Electronics{
    void printInfo(){
        System.out.println("A typical electronic device.");
    }
}


class Mobile extends Electronics{
    @Override
    void printInfo(){
        System.out.println("A mobile is a portable telephone.");
    }
}


class Laptop extends Electronics{
    @Override
    void printInfo(){
        System.out.println("A laptop is a small, protable personal computer.");
    }
}


class Smartwatch extends Electronics{
    @Override
    void printInfo(){
        System.out.println("A smartwatch is a wearable computer in the form of a watch");
    }
}


public class Test{
    public static void main(String[] args){
        Electronics elc;
        
        elc = new Electronics();
        elc.printInfo();

        elc = new Mobile();
        elc.printInfo();

        elc = new Laptop();
        elc.printInfo();

        elc = new Smartwatch();
        elc.printInfo();
    }
}