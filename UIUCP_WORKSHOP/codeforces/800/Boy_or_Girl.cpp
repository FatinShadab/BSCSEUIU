#include <bits/stdc++.h>

using namespace std;

int main(){

    string str;
    getline(cin, str);

    map <char, int> char_freq;

    for (int i=0; i<str.length(); char_freq[str[i++]]);

    int distinct_chars = 0;

    for(auto i : char_freq){
        distinct_chars++;
    }

    (distinct_chars % 2 == 0) ? printf("CHAT WITH HER!"):printf("IGNORE HIM!");

    return 0;
}