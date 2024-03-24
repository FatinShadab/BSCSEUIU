//Problem Link : https://vjudge.net/contest/616828#problem/G
#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> REVMAP = {
    {'A', 'A'}, {'E', '3'}, {'H', 'H'}, 
    {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
    {'M', 'M'}, {'O', 'O'}, {'S', '2'},
    {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, 
    {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, 
    {'Z', '5'}, {'1', '1'}, {'2', 'S'},
    {'3', 'E'}, {'5', 'Z'}, {'8', '8'}
};

bool is_palindrome(string str, int l, int r) {
    if (l > r) return true;
    if (str[l] != str[r]) return false;
    return str[l] == str[r] && is_palindrome(str, l+1, r-1);
}

bool is_mirror(string str, int l, int r) {
    if (l > r) return true;
    if (REVMAP.find(str[l]) == REVMAP.end()) return false;
    if (REVMAP[str[l]] != str[r]) return false;

    return REVMAP[str[l]] == str[r] && is_mirror(str, l+1, r-1);
}

int main() {
    string str;

    while (cin >> str) {
        bool palindrome, mirror;

        palindrome = is_palindrome(str, 0, str.length() - 1);
        mirror = is_mirror(str, 0, str.length() - 1);

        if (palindrome && mirror) cout << str << " -- is a mirrored palindrome.\n\n";
        else if (palindrome && !mirror) cout << str << " -- is a regular palindrome.\n\n";
        else if (!palindrome && mirror) cout << str << " -- is a mirrored string.\n\n";
        else if (!palindrome && !mirror) cout << str << " -- is not a palindrome.\n\n";
    }

    return 0;
}