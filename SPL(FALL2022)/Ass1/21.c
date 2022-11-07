/*
Write a program (WAP) for the described scenario: 
Player-1 picks a number X and Player-2 has to guess that number within N tries. For each wrong guess by Player-2, the program prints “Wrong, N-1 Choice(s) Left!” If Player-2 at any time successfully guesses the number, the program prints “Right, Player-2 wins!” and terminates right away. Otherwise after the completion of N wrong tries, the program prints “Player-1 wins!” and halts.

(Hint: Use break/continue)
*/
#include <stdio.h>

int main(){

    int x, guess, chance;
    scanf("%d", &x);
    scanf("%d", &chance);

    while(1){
        if (chance == 0) {
            printf("\nPlayer-1 wins!");
            break;
        }
        printf("\n");
        scanf("%d", &guess);

        if (guess != x){
            printf("\nWrong %d Choice(s) Left!", --chance);
        }
        else{
            printf("\nRight, Player-2 wins!");
            break;
        }
    }

    return 0;
}