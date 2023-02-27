package source;
import source.Fifa;

public class ArgentinaFans extends Fifa{
    private int havingWorldCups;

    public ArgentinaFans(int noOfGoals, String venue, int worldCupQ){
        super(noOfGoals, venue);
        this.havingWorldCups = worldCupQ;
    }

    public void incrementWorldCups(){
        this.havingWorldCups++;
    }

    @Override
    public String toString(){
        return "ArgentinaFans -> [" + super.toString() + "], havingWorldCups : " + this.havingWorldCups;
    }
}