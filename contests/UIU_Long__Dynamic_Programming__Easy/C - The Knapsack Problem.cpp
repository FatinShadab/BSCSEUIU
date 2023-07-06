// Problem Link : https://vjudge.net/contest/564816#problem/C

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (2 * 1e3) + 1;
int max_size_capacity, number_of_items;

int CACHE[MAX_N][MAX_N];
int item_sizes[MAX_N], item_values[MAX_N];

int knapsack_max_value(int item_no, int capacity_left){
    int item_size = item_sizes[item_no];
    int item_value = item_values[item_no];

    if (item_no <= 0 || capacity_left == 0){
        return 0;
    }

    if (item_size > capacity_left){
        return CACHE[item_no][capacity_left] = knapsack_max_value(item_no-1, capacity_left);
    }

    if (CACHE[item_no][capacity_left] != -1){
        return CACHE[item_no][capacity_left];
    }

    int knapsack_max_value_with_current_item = knapsack_max_value(item_no-1, capacity_left-item_size) + item_value;
    int knapsack_max_value_without_current_item = knapsack_max_value(item_no-1, capacity_left);

    return CACHE[item_no][capacity_left] = max(
        knapsack_max_value_with_current_item,
        knapsack_max_value_without_current_item
    );
}

void debug(){
    printf("\n\n\t---- DeBug ----\t\n\n");

    printf("Knapsack Max Capacity: %d, Number of Items: %d\n", max_size_capacity, number_of_items);

    printf("\nThe Item Data : \n");
    for (int item_no = 1; item_no <= number_of_items; item_no++){
        printf("\titem_no: %d, item_size: %d, item_value: %d\n", item_no, item_sizes[item_no], item_values[item_no]);
    }

    printf("\nThe CACHED Data : \n");
    for (int i = 0; i <= number_of_items; i++){
        for (int j = 0; j <= max_size_capacity; j++){
            printf("\titem_no (i): %d, capacity_left (j): %d\n", i, j);
            printf("\t\tCACHE[item_no][capacity_left]: %d\n", CACHE[i][j]);
        }
    }

    printf("\n\n\t-------X-------\t\n\n");
    return;
}

int main(){

    for (int i = 0; i <= MAX_N; i++){
        for (int j = 0; j <= MAX_N; j++){
            CACHE[i][j] = -1;
        }
    }

    scanf("%d %d", &max_size_capacity, &number_of_items);

    for (int item_no = 1; item_no <= number_of_items; item_no++){
        scanf("%d %d", &item_sizes[item_no], &item_values[item_no]);
    }

    printf("%d\n", knapsack_max_value(number_of_items, max_size_capacity));

    //debug();

    return 0;
}