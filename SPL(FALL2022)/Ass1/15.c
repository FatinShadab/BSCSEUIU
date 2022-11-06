/*
Program for “Guessing Game”:
Player-1 picks a number X and Player-2 has to guess that number within N = 3 tries.
For each wrong guess by Player-2, the program prints “Wrong, N-1 Chance(s) Left!”
If Player-2 successfully guesses the number, the program prints “Right, Player-2 wins!”
and stops allowing further tries (if any left). Otherwise after the completion of N = 3 
wrong tries, the program prints “Player-1 wins!” and halts.

[ Restriction: Without using loop/break/continue
 Hint: Use flag ]
 
Sample input        Sample output
(X, n1, n2, n3) 
--------------------------------------------	
Case:1
--------------------------------------------
5                   Wrong, 2 Chance(s) Left!
12    8    5	    Wrong, 1 Chance(s) Left!
                    Right, Player-2 wins!
--------------------------------------------
Case:2
--------------------------------------------
100                 Wrong, 2 Chance(s) Left!
50    100	        Right, Player-2 wins!
--------------------------------------------
Case:3
--------------------------------------------
20                  Wrong, 2 Chance(s) Left!
12    8    5	    Wrong, 1 Chance(s) Left!
                    Wrong, 0 Chance(s) Left!
                    Player-1 wins!
--------------------------------------------
*/
#include <stdio.h>

int main(){
    int number;
    int guess;
    int chances = 3;

    printf("Player 1: Enter the number to guess : ");
    scanf("%d", &number);

    if (chances <= 3 && chances >= 0)
        goto Task;

Task:
    printf("\nPlayer 2: Guess the number : ");
    scanf("%d", &guess);
    chances--;

    if (guess == number){
        printf("Right, Player-2 wins!");
        return 0;
    }
    else if (chances > 0){
        printf("Wrong, %d Chance(s) Left!", chances);
        goto Task;
    }
    else{
        printf("Wrong, %d Chance(s) Left!", chances);
        printf("\nPlayer-1 wins!");
    }
}