/*
    Problem Link : https://lightoj.com/problem/discovering-permutations
*/
#include <bits/stdc++.h>
using namespace std;

const char ABCD__XYZ[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char mainStr[28];

void printKpermutation(char str[], int n, int k){

    if (!k){
        return;
    }

    puts(str);

    next_permutation(str, str+n);

    if (!strcmp(mainStr, str)){
        return;
    }

    printKpermutation(str, n, k-1);
}

int main (){
    int T;
    int n, k;
    scanf("%d", &T);

    for (int t=1; t<=T; t++){
        printf("Case %d:\n", t);

        scanf("%d %d", &n, &k);

        char str[n+1];
        strncpy(str, ABCD__XYZ, n);
        str[n] = '\0';

        strcpy(mainStr, str);

        printKpermutation(str, n, k);
    }

    return 0;
}