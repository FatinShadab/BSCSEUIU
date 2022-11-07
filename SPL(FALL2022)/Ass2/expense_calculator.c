#include <stdio.h>
#include <string.h>

int main(){
    int expense[] = {50, 30, 40, 90, 50, 30, 40, 20, 10, 22, 33, 44};
    char months[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"}; 
    
    while (1){
        fflush(stdin);
        char lb[4];
        char ub[4];

        scanf("%[^\n]s", lb);
        fflush(stdin);
        if (strcmp("exit", lb) == 0){
            break;
        }
        scanf("%[^\n]s", ub);

        int ub_idx = 0;
        int lb_idx = 0;

        for (int i=0; i<12; i++){
            if (strcmp(months[i], ub) == 0){
                ub_idx = i;
            }
            if (strcmp(months[i], lb) == 0){
                lb_idx = i;
            }
        }
        printf("lb: %d, ub: %d\n", lb_idx, ub_idx);
        int total_expense = 0;
        for (int i=lb_idx; i<=ub_idx; i++){
            total_expense += expense[i];
        }

        printf("\n%d\n", total_expense);
    }

    return 0;
}

/*
Take 5 strings from user and print them
*/