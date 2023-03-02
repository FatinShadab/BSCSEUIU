package eatable;

public class Homemade extends Food{
    double protein;

    public Homemade(double calories, double fat,
                        double carb, double protein){
        super(calories, fat, carb);
        this.protein = protein;
    }

    public void Homemadereview(){
        System.out.println("Inside the review method of Homemade class.");
    }

    @Override
    public void description(){
        System.out.println("Override from Homemade class.");
    }
}