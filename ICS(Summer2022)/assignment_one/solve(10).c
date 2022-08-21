#include <stdio.h>

/*
Suppose that in a country, there are notes of 1, 5, 10, 50, 100 and 500 units of currencies.
Write a C program which will take as input the amount of money to give, and find out the
number of each note to provide this amount of money so that a minimal number of notes
are given in total.

============================================================
Sample input                                Sample output
============================================================
1627                                        3 note(s) of 500
                                            1 note(s) of 100
                                            0 note(s) of 50
                                            2 note(s) of 10
                                            1 note(s) of 5
                                            2 note(s) of 1
_____________________________________________________________
789                                         1 note(s) of 500            
                                            2 note(s) of 100
                                            1 note(s) of 50
                                            3 note(s) of 10
                                            1 note(s) of 5
                                            4 note(s) of 1
______________________________________________________________
*/


int main(){

    int need_note_1 = 0;
    int need_note_5 = 0;
    int need_note_10 = 0;
    int need_note_50 = 0;
    int need_note_100 = 0;
    int need_note_500 = 0;

    int amount_of_money;

    scanf("%d", &amount_of_money);

    if (amount_of_money >= 500){
        need_note_500 = amount_of_money / 500;
        amount_of_money = amount_of_money % 500;
        // for debug
        //printf("amount of money remaining after given 500 notes = %d\n", amount_of_money);
    }
    if (amount_of_money >= 100){
        need_note_100 = amount_of_money / 100;
        amount_of_money = amount_of_money % 100;
        // for debug
        //printf("amount of money remaining after given 100 notes = %d\n", amount_of_money);
    }
    if (amount_of_money >= 50){
        need_note_50 = amount_of_money / 50;
        amount_of_money = amount_of_money % 50;
        // for debug
        //printf("amount of money remaining after given 50 notes = %d\n", amount_of_money);
    }
    if (amount_of_money >= 10){
        need_note_10 = amount_of_money / 10;
        amount_of_money = amount_of_money % 10;
        // for debug
        //printf("amount of money remaining after given 10 notes = %d\n", amount_of_money);    
    }
    if (amount_of_money >= 5){
        need_note_5 = amount_of_money / 5;
        amount_of_money = amount_of_money % 5;
        // for debug
        //printf("amount of money remaining after given 5 notes = %d\n", amount_of_money); 
    }
    if (amount_of_money >= 1){
        need_note_1 = amount_of_money / 1;
        // for debug
        //printf("amount of money remaining after given 1 notes = %d\n", amount_of_money);
    }



    printf("%d note(s) of 500\n", need_note_500);
    printf("%d note(s) of 100\n", need_note_100);
    printf("%d note(s) of 50\n", need_note_50);
    printf("%d note(s) of 10\n", need_note_10);
    printf("%d note(s) of 5\n", need_note_5);
    printf("%d note(s) of 1\n", need_note_1);

    return 0;
}