package eatable;

public class Foodmain{
    public static void main(String[] args){
        Food f1 = new Homemade(10.0, 9.0, 8.0, 7.0);
        Food f2 = new Fastfood(11.0, 10.0, 12.0, "Burger", "spicy");

        ((Homemade) f1).Homemadereview();
        ((Fastfood) f2).Fastfoodreview();
    }
}