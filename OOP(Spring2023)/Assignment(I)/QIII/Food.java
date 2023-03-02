package eatable;

public class Food{
    double calories, fat, carb;

    Food(double calories, double fat, double carb){
        this.calories = calories;
        this.fat = fat;
        this.carb = carb;
    }

    public void description(){
        System.out.println("Inside Food class");
    }
}