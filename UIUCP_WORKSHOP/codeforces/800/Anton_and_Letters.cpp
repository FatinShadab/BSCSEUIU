#include <bits/stdc++.h>

using namespace std;

int main(){
    string setStr = "";
    string str;
    getline(cin, str);

    for (int idx=0; idx<str.length(); idx++){
        if ((int) str[idx] >= 97 && (int) str[idx] <= 122){
            int flag = 1;
            for (int _idx=0; _idx<setStr.length(); _idx++){
                if (setStr[_idx] == str[idx]){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                setStr += str[idx];
            }
        }
    }

    cout<<setStr.length()<<endl;

    return 0;
}