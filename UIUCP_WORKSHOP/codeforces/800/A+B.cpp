#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        string equationStr;
        cin>>equationStr;

        printf("%d\n", ((equationStr[0]-'0')+(equationStr[2]-'0')));
    }

    return 0;
}