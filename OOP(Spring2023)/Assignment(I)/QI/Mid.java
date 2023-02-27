package source;
import source.*;

public class Mid{
    public static void main(String[] args){
        ArgentinaFans argFanGroup = new ArgentinaFans(10, "Qatar", 2);
        System.out.println("Argentina will win.");
        BrazilFans brzFanGroup = new BrazilFans(7, "Qatar", 5);
        System.out.println("Brazil will win.");

        if (argFanGroup.getNoOfGoals() > brzFanGroup.getNoOfGoals()){
            argFanGroup.incrementWorldCups();
        } else {
            brzFanGroup.incrementWorldCups();
        }

        System.out.println(argFanGroup);
        System.out.println(brzFanGroup);
    }
}