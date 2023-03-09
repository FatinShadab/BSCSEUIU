abstract class Item{
    String name;
    double unit_price;

    Item(String name, double unit_price){
        this.name = name;
        this.unit_price = unit_price;
    }

    void printItemDetails(){
        System.out.println("Itemname: " + name + " Unit-price: " + unit_price);
    }

    abstract double calculatePrice();
}


// solve of task : a
class WeightedItem extends Item{
    public double weight;

    public WeightedItem(String name, double weight, double unit_price){
        super(name, unit_price);
        this.weight = weight;
    }

    @Override
    public double calculatePrice(){
        return this.weight * this.unit_price;
    }
}


// solve of task : b
class CountableItem extends Item{
    public int quantity;

    public CountableItem(String name, int quantity, double unit_price){
        super(name, unit_price);
        this.quantity = quantity;
    }

    @Override
    public double calculatePrice(){
        return this.quantity * this.unit_price;
    }
}


public class Mid{
    // solve of task : c
    public static double calculateTotalPrice(Item[] items){
        double total = 0.0;
        
        for (Item item : items){
            // For debug
            item.printItemDetails();
            System.out.println(item.calculatePrice() + "\n");

            total += item.calculatePrice();
        }
        
        return total;
    }

    public static void main(String[] args){
        Item[] items = new Item[3];

        items[0] = new WeightedItem("Rice", 10.0, 70.0);
        //weight: 10.0 kg & unit price: 70 per kg

        items[1] = new CountableItem("Egg", 12, 11.0);
        // quantity: 12 pieces & unit price: 11 per pice

        items[2] = new WeightedItem("Chiken", 0.7, 250.0);
        // weight: 0.7 kg & unit price: 250 per kg

        System.out.println("Total Price: " + calculateTotalPrice(items));
        // should print 1007.0
    }
}