import java.util.Scanner;

/*
    - Create a Banking Application, where a user can,
        i| create new account
       ii| deposit money
      iii| withdraw money
       iv| check balance
*/

class Account{
    public static final double init_balance = 1000.0;
    public static final double max_withdraw_limit = 1000.0;

    public String owner_name;
    public double balance;

    public Account(String owner_name){
        this.owner_name = owner_name;
        this.balance = Account.init_balance;
    }

    public void deposit_money(double amount){
        this.balance += amount;
    }

    public boolean withdraw_money(double amount){
        if (amount <= Account.max_withdraw_limit && amount <= this.balance){
            this.balance -= amount;
            return true;
        }
        return false;
    }

    public void check_balance(){
        System.out.println("Current Balance : " + this.balance);
    }

    public String toString(){
        return "Account Details :\n\tOwner Name : " + this.owner_name +
                    "\n\tCurrent Balance : " + this.balance + 
                        "\n\tMax withdraw limit per day : " +
                             Account.max_withdraw_limit;
    }
}


public class APP{
    public static void main(String args[]){
        Scanner scanf = new Scanner(System.in);

        System.out.print("Enter you name : ");
        String user_name = scanf.nextLine();

        Account user_account = new Account(user_name);

        System.out.println("\n*** Account Created Successfully (:\n");
        System.out.println(user_account);

        int selected_option = 0;

        do{
            System.out.println("\nop (1) : Deposite Money");
            System.out.println("op (2) : Withdraw Money");
            System.out.println("op (3) : Show balance");
            System.out.println("op (0) : Exit\n");

            System.out.print("Select a option : ");
            selected_option = scanf.nextInt();

            if (selected_option == 1){
                double amount = 0;

                System.out.print("Enter the amount to deposit : ");
                amount = scanf.nextDouble();

                user_account.deposit_money(amount);
            }
            if (selected_option == 2){
                double amount = 0;

                System.out.print("Enter the amount to withdraw : ");
                amount = scanf.nextDouble();

                boolean success = user_account.withdraw_money(amount);

                if (success){
                    System.out.println("Withdraw Successfull !");
                    user_account.check_balance();
                }
                else{
                    System.out.println("Withdraw Unsuccessfull !");
                    user_account.check_balance();
                }
            }
            if (selected_option == 3){
                user_account.check_balance();
            }

        }while(selected_option != 0);
    }
}