#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    getchar();
    while (testcase){
        int is_palindome = 1;
        string str;
        getline(cin, str);

        for (int i=0; i < str.length()/2; i++){
            if (str[i] != str[str.length()-1-i]){
                is_palindome = 0;
                break;
            }
        }

        if (is_palindome){
            cout<<"Yes! It is palindrome!"<<endl;
        }else{
            cout<<"Sorry! It is not palindrome!"<<endl;
        }

        testcase--;
    }

    return 0;
}