#include <bits/stdc++.h>

using namespace std;

int main(){

    int testcase;
    cin>>testcase;

    getchar();
    while (testcase){
        string str;
        getline(cin, str);

        if (str.length() >10 ){
            cout<<str[0]<<str.length()-2<<str[str.length()-1];
        }
        else{
            cout<<str;
        }

        if (testcase > 1) cout<<endl;

        testcase--;
    }
    
    return 0;
}