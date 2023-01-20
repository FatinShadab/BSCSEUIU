/*
input : 5
output : 1 2 3 4 5 4 3 2 1
*/
#include <bits/stdc++.h>

using namespace std;

void customPrint(int start, int n){
    static int count = 0;
    
    if (count++ >= (n*2)-1) return;

    printf("%d ", start);

    customPrint((count < n) ? start+1:start-1, n);
}

int main(){
    int n;
    scanf("%d", &n);

    customPrint(1, n);
}