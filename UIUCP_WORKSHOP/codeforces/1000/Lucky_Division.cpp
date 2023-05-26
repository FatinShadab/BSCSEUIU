// PB LINK : https://codeforces.com/problemset/problem/122/A

#include <bits/stdc++.h>
using namespace std;

bool is_lucky_number(int num){
    while (num){
        if (num%10 != 4 && num%10 != 7){
            return false;
        }
        num /= 10;
    }

    return true;
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i=n; i>=4; i--){
        if (is_lucky_number(i)){
            if (i == n || n%i == 0){
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}