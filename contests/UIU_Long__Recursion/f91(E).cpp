/*
McCarthy is a famous theorician of computer science. In his work, he defined a recursive function,
called f91, that takes as input a positive integer N and returns a positive integer defined as follows:
• If N ≤ 100, then f91(N) = f91(f91(N + 11));
• If N ≥ 101, then f91(N) = N − 10.

Write a program, that computes McCarthy’s f91.

Input
    The input tests will consist of a series of positive integers, each integer is at most 1,000,000. There will
    be at most 250,000 test cases. Each number is on a line on its own. The end of the input is reached
    when the number ‘0’ is met. The number ‘0’ shall not be considered as part of the test set.
Output
    The program shall output each result on a line by its own, following the format given in the sample
    output.
Sample Input
    500
    91
    0
Sample Output
    f91(500) = 490
    f91(91) = 91
*/

#include <bits/stdc++.h>
using namespace std;

int f91(int N){
    if (N <= 100){
        return f91(f91(N+11));
    }

    return N-10;
}

int main(){
    int run = 1;
    
    while (run){
        int N;
        scanf("%d", &N);

        switch (N){
            case 0:
                run = 0;
                break;
            default:
                printf("f91(%d) = %d\n", N, f91(N));
        }
    }

    return 0;
}