// PB LINK : https://codeforces.com/problemset/problem/118/A

#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char chr){
    switch (tolower(chr)){
        case 'a':
            case 'o':
                case 'y':
                    case 'e':
                        case 'u':
                            case 'i':
                                return true;
        default:
            return false;
    }
}

int main(){
    int _idx = 0;
    char str[100];
    char new_str[200];

    scanf("%s", str);

    for (int idx=0; idx<strlen(str); idx++){
        if (!is_vowel(str[idx])){
            new_str[_idx++] = '.';
            new_str[_idx++] = tolower(str[idx]);
        }
    }

    new_str[_idx] = '\0';

    printf("%s\n", new_str);

    return 0;
}