package source;
// javac -d . Fifa.java [this command will create a pakage name source]

public class Fifa{
    private int noOfGoals;
    private String venue;
    
    public Fifa(){
        System.out.println("Who will be winner?");
    }
    
    public Fifa(int noOfGoals, String venue){
        this();
        this.noOfGoals = noOfGoals;
        this.venue = venue;
    }
    
    public int getNoOfGoals(){
        return this.noOfGoals;
    }

    public String toString(){
        return "Fifa -> noOfGoals: " + this.noOfGoals + " venue: " + this.venue;
    }
}