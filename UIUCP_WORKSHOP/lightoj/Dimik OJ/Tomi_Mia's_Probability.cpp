#include <bits/stdc++.h>

using namespace std;

int fact(int n){
    int fact = 1;

    for(int i=1; i <= n; fact*=i++);

    return fact;
}

int main(){
    int T; cin >> T;

    getchar();
    while (T--){
        string str;
        getline(cin, str);
        stringstream sstr(str);

        map <string, int> freqCount;

        string temp;
        int totalWorlds = 0;

        while(sstr >> temp){
            freqCount[temp]++;
            totalWorlds++;
        }

        int allPossibleCombo = fact(totalWorlds);

        for (pair<string, int> x: freqCount){
            if (x.second>1) allPossibleCombo /= fact(x.second);
        }

        cout<<"1/"<<allPossibleCombo<<endl;
    }
}