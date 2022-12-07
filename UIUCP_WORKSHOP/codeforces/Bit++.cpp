#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    getchar();

    int x = 0;

    while (n){
        string str;
        getline(cin, str);

        for (int i=0; i<str.length(); i++){
            if (str[i] == '+'){
                x++;
                break;
            }
            else if (str[i] == '-'){
                x--;
                break;
            }
        }

        n--;
    }

    cout << x <<endl;

    return 0;
}