#include <bits/stdc++.h>

using namespace std;

int main(){
    int run = 0;
    int tcase; cin >> tcase;

    while(tcase--){
        if (!run){
            getchar();
            run = 1;
        }
        map < char, int> char_map;
        map < char, int> is_printed;
        string str;

        getline(cin, str);

        for (int idx=0; idx < str.length(); idx++){
            char_map[str[idx]]++;
        }

        for (int idx=0; idx < str.length(); idx++){
            if (!is_printed[str[idx]]){
                cout<<str[idx]<<" = "<<char_map[str[idx]]<<endl;
                is_printed[str[idx]] = 1;
            }
        }

        if (tcase-1 > -1){
            cout<<endl;
        }else{
            continue;
        }

    }

    return 0;
}