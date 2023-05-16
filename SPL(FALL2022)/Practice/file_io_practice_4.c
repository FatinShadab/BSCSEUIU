/*****
 * You have been given the task of writing a program in C that reads a list of customer names,
 * orders, and payment methods from a text file. Write a function that calculates the total number of
 * orders for each customer. The function should take in an array of structure and the size of the
 * array as inputs and return an integer that is the total number of orders for a specific customer.
 * The program should then write the customer names,and total number of orders to a new text file
 * 
 * ----------------------------------------------------------------------------------------
 *                    input.txt               |                 output.txt
 * ----------------------------------------------------------------------------------------
 * John Product1 Visa                         | John 2
 * Mary Product2 Mastercard                   | Mary 2
 * James Product3 Paypal                      | James 1
 * Sue Product4 Cash                          | Sue 1
 * John Product5 Visa                         |
 * Mary Product6 Mastercard                   |
 * ----------------------------------------------------------------------------------------
 * ******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char customer[100];
    char product[100];
}Order;

int main(){
    int n;
    scanf("%d", &n);
    
    char $[100];
    Order orders[n];
    char order_added[n][100];

    FILE *srcFptr = fopen("input5.txt", "r");

    int idx = 0;
    while(!feof(srcFptr)){
        fscanf(srcFptr, "%s %s %s", orders[idx].customer, $, orders[idx].product);
        idx++;
    }
    fclose(srcFptr);

    FILE *dstFptr = fopen("output5.txt", "w");

    int ___idx = 0;
    for(int idx=0; idx<n; idx++){
        int added = 0;
        int order_count = 1;

        for (int _idx = 0; _idx < n; _idx++){
            if (strcmp(orders[idx].customer, orders[_idx].customer) == 0 && idx != _idx){
                order_count++;
            }
        }

        for(int i = 0; i < ___idx; i++){
            if (strcmp(orders[idx].customer, order_added[i]) == 0){
                added = 1;
                break;
            }
        }

        if (!added){
            fprintf(dstFptr, "%s %d\n", orders[idx].customer, order_count);
            strcpy(order_added[___idx++], orders[idx].customer);
        }
    }
    
    fclose(dstFptr);

    return 0;
}