/*
Implement a function updateBalance that takes four parameters: an array of floats representing
customer balances, an integer representing the customer's unique identifier (which is the index of
the array), an integer representing the type of transaction (1 for withdrawal, 2 for deposit), and a
float representing the transaction amount. The function should update the customer's balance
based on the transaction type, ensuring that withdrawals do not result in a negative balance.

i) In the main function, initialize an array of floats to store the initial balances of 100
customers. Take the initial balances from user as input.

ii) Take three values: an integer (customer identifier), an integer (transaction type), and a float
(transaction amount) from user.

iii) Call the updateBalance function passing these values. If the transaction is a withdrawal and
the withdrawal amount is exceeding the available balance then print “Not sufficient balance”
and do not activate the withdrawal.

iv) If transaction is successful in step (iii), print the updated balance of the customer.
*/
#include <stdio.h>


int updateBalance( float* customer_balance_data, int customer_uid,
    int trasaction_type, float transaction_amount);


int main() {
    int customer_limit = 5;
    float customer_db[customer_limit];
    int customer_uid, trasaction_type; float transaction_amount;

    for (int uid = 0; uid < customer_limit; uid++) {
        printf("Enter the initial balance of customer with uid : %d\n", uid);
        scanf("%f", &customer_db[uid]);
    }

    printf("Enter the data to perform a transaction :\n");
    printf("Your customer uid [0-%d]: ", customer_limit);
    scanf("%d", &customer_uid);
    printf("Enter the transaction type [1-withdrawal, 2-deposit]: ");
    scanf("%d", &trasaction_type);
    printf("Enter the transaction amount : ");
    scanf("%f", &transaction_amount);

    if (updateBalance(customer_db, customer_uid, trasaction_type, transaction_amount)) {
        printf("Balance of customer with uid:%d -> %f\n", customer_uid, customer_db[customer_uid]);
    } else {
        printf("Not sufficient balance\n");
    }

    return 0;
}

int updateBalance( float* customer_balance_data, int customer_uid,
    int trasaction_type, float transaction_amount) {
    
    float current_balance = *(customer_balance_data + customer_uid);

    switch (trasaction_type) {
        case 1:
            if (current_balance < transaction_amount) return 0;
            *(customer_balance_data + customer_uid) = current_balance - transaction_amount;
            break;
        case 2:
            *(customer_balance_data + customer_uid) = current_balance + transaction_amount;
            break;

        default: return 0;
    }
    
    return 1;
}