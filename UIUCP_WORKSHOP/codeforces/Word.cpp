#include <bits/stdc++.h>

using namespace std;

int main(){
    string word;
    getline(cin, word);

    int word_len = word.length();

    int upper_case_alphabets = 0;
    int lower_case_alphabets = 0;

    for (int i=0; i < word_len; i++){
        int ascii_code = (int)word[i];

        if (ascii_code >= 65 && ascii_code <= 90)
            upper_case_alphabets++;
        else
            lower_case_alphabets++;

    }

    for (int i=0; i < word_len; i++){
        if (upper_case_alphabets > lower_case_alphabets)
            word[i] = toupper(word[i]);
        else
            word[i] = tolower(word[i]);
    }

    cout<<word<<endl;

    return 0;
}