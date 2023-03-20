/*
    problem link --> https://codeforces.com/contest/1807/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d", &T);
    int a, b, c;

    while (T--){
        scanf("%d %d %d", &a, &b, &c);
        printf("%c\n", (a+b == c) ? '+':'-');
    }

    return 0;
}