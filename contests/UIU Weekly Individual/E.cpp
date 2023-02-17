/*
Problem Link : https://vjudge.net/contest/543519#problem/E
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+1;
int RANKS[N];

int main(){
    int n;
    int temp;
    scanf("%d", &n);

    for (int i=1; i<n; i++){
        scanf("%d", &temp);
        RANKS[i] = temp + RANKS[i-1];
    }

    //for (int i=0; i<n; i++){
    //    printf("%d ", RANKS[i]);
    //}
    //puts("");
    
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", RANKS[b-1] - RANKS[a-1]);

    return 0;
}