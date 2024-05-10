/*
Suppose you're developing a program for the United International University (UIU) Bookshop to
manage customer purchases. Your task is to create a C program that can store, manage and
manipulate the bookshop's last 12 months’ customer data. As it is the end of the year, the
bookshop is giving a “best customer award” to the customers who purchased the most in the past
year. 
Write a C program that will:                                                               [8]

1. Store the following information of a customer in a structure.
        (i) Name 
        (ii) ID 
        (iii) Number of times shopped, and 
        (iv) An array of spent money in each of the shoppings.
    *** Use appropriate data types and variable names for all the features.

2. Take input for 100 customers from the user.

3. Calculate the average purchase for each customer (total money spent divided by the total
number of shopping).

4. To find the best customer, only consider the customers who have shopped more than 10
times. Among these selected customers, the customer having the best average purchase
(calculated from (3)) will win the award. Print the customer's name who has won the award.
*/
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 5
#define MAX_SHOPPING 100

typedef struct {
    char name[100];
    char id[10];
    int shopping_freq;
    float shopping_cost_db[MAX_SHOPPING];
    float average_purchase;
} customer;

int main() {
    customer customers[MAX_CUSTOMERS];

    // Input data for each customer
    printf("Enter details for each customer:\n");
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        printf("\nCustomer %d:\n", i + 1);
        
        printf("Name: "); fgets(customers[i].name, sizeof(customers[i].name), stdin);
        printf("ID: "); fgets(customers[i].id, sizeof(customers[i].id), stdin);
        printf("Number of times shopped: "); scanf("%d", &customers[i].shopping_freq);
        
        printf("Enter amount spent for each shopping:\n");
        for (int j = 0; j < customers[i].shopping_freq; j++) {
            printf("Shopping %d: ", j + 1);
            scanf("%f", &customers[i].shopping_cost_db[j]);
        }

        getchar(); // Consume newline character
    }

    // Calculate average purchase for each customer
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        float total_purchase = 0;
        for (int j = 0; j < customers[i].shopping_freq; j++) {
            total_purchase += customers[i].shopping_cost_db[j];
        }
        customers[i].average_purchase = total_purchase / customers[i].shopping_freq;
    }

    // Find the best customer
    int best_customer_index = -1;
    float highest_average_purchase = 0;
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].shopping_freq > 10 && customers[i].average_purchase > highest_average_purchase) {
            highest_average_purchase = customers[i].average_purchase;
            best_customer_index = i;
        }
    }

    // Print the winner
    if (best_customer_index != -1) {
        printf("\nWinner of the best customer award: %s\n", customers[best_customer_index].name);
    } else {
        printf("\nNo eligible customer found.\n");
    }

    return 0;
}
