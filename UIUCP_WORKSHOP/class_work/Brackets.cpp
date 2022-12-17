#include <bits/stdc++.h>

using namespace std;

int main(){
    map <char, char> validPair;

    validPair[')'] = '(';
    validPair['}'] = '{';
    validPair[']'] = '[';

    int n; cin>>n;

    getchar();
    while (n--){

        string bracketString;
        getline(cin, bracketString);

        vector <char> brackets;

        for (int idx=0; idx<bracketString.length(); idx++){
            if (brackets.empty()){
                brackets.push_back(bracketString[idx]);
            }
            else if (brackets[brackets.size()-1] == validPair[bracketString[idx]]){
                brackets.pop_back();
            }
            else{
                brackets.push_back(bracketString[idx]);
            }
        }

        printf((brackets.empty()) ? "YES\n":"NO\n");
    }

    return 0;
}