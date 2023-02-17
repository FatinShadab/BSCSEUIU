#include <bits/stdc++.h>

using namespace std;

bool check(string str, int l, int r){

    if (l > r){
        return true;
    }

    if (str[l] != str[r]){
        return false;
    }

    return check(str, l+1, r-1);
}

int main(){
    string str;
    cin>>str;

    if (check(str, 0, str.length()-1)){
        cout<< str << " is Palindrome"<<endl;
    }else{
        cout<< str << " is not Palindrome"<<endl;
    }
}