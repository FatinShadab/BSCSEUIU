#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int incomes_per_day[n];
    for (int day=0; day < n; scanf("%d", &incomes_per_day[day++]));

    int max_strike = 0;
    int start_idx = 0;

    while (start_idx < n){

        int idx;
        int strike_count = 0;
        int min = incomes_per_day[start_idx];

        for (idx=start_idx; idx<n; idx++){
            if (min <= incomes_per_day[idx]){
                min = incomes_per_day[idx];
                strike_count++;
            }
            else{
                break;
            }
        }

        if (strike_count > max_strike){
            max_strike = strike_count;
        }

        start_idx = idx;
    }

    printf("%d\n", max_strike);

    return 0;
}