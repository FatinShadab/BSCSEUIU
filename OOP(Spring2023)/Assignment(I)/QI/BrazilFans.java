package source;
import source.Fifa;

public class BrazilFans extends Fifa{
    private int havingWorldCups;

    public BrazilFans(int noOfGoals, String venue, int worldCupQ){
        super(noOfGoals, venue);
        this.havingWorldCups = worldCupQ;
    }

    public void incrementWorldCups(){
        this.havingWorldCups++;
    }

    @Override
    public String toString(){
        return "BrazilFans -> [" + super.toString() + "], havingWorldCups : " + this.havingWorldCups;
    }
}