/*
Write a programe that will take as input the number
of rows and columns of a chessboard and rint the 
color of the squre on the lower right corner of the
board.

The board --

⬜⬛⬜⬛⬜⬛⬜⬛⬜
⬛⬜⬛⬜⬛⬜⬛⬜⬛
⬜⬛⬜⬛⬜⬛⬜⬛⬜
⬛⬜⬛⬜⬛⬜⬛⬜⬛
⬜⬛⬜⬛⬜⬛⬜⬛⬜
⬛⬜⬛⬜⬛⬜⬛⬜⬛

Input
==========================
row number      (int)
colum number    (int)

Output
==========================
square color    (str)

Case: 1
==========================
Input               Output
6                     ⬛
9

Case: 2
==========================
Input               Output
8                     ⬜
8

Case: 3
==========================
Input               Output
5                     ⬜
91
*/

#include <stdio.h>

int main(){

    int row, col;
    scanf("%d %d", &row, &col);

    if ((row+col)%2 == 0){
        printf("WHITE");
    }
    else{
        printf("BLACK");
    }

    return 0;
}