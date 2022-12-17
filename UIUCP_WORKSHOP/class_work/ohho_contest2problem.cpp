#include <bits/stdc++.h>

using namespace std;

int main(){
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    string output = str1 + str2;

    cout<<str1.length()<<" "<<str2.length()<<endl;
    cout<<output<<endl;
    
    char temp = str1[0];
    str1[0] = str2[0];
    str2[0] = temp;

    cout<<str1<<" "<<str2<<endl;

    return 0;
}