//### Problem LInk : (https://cses.fi/problemset/task/1753/)

/*
"""
# Python code : gives TLE
    >>> import re
    >>> string = input()
    >>> pattern = input()
    >>> print(len(re.findall(f'(?={pattern})', string)))
"""
*/

//### NEED KMP ALGO ! (https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
//### KMP Algo -> Knuth Morris Pratt Algo

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

// TC : O(M)
vector<int> getPiTable(string pattern){
    int n = pattern.size();
    vector<int> pi(n, 0);

    int lp = 0;
    int rp = 1;

    while (rp < n){
        if (pattern[lp] == pattern[rp]){
            pi[rp++] = 1 + lp++;
        } else {
            if (!lp){
                pi[rp++] = lp;
            } else {
                lp = pi[lp - 1];
            }
        }
    }

    return pi;
}
// TC : O(N+M) : O(N)
int KMP(string text, string pattern){
    int found = 0;

    vector <int> piTable = getPiTable(pattern);

    int pInText = 0;
    int pInPtrn = 0;

    while (pInText < text.size()){
        if (text[pInText] == pattern[pInPtrn]){
            pInText++;
            pInPtrn++;
        } else {
            if (!pInPtrn){
                pInText++;
            } else {
                pInPtrn = piTable[pInPtrn - 1];
            }
        }

        if (pInPtrn == pattern.size()){
            found++;
        }
    }

    return found;
}

int main(){
    
    __fastIO__

    string text, pattern;
    cin>>text;
    cin>>pattern;

    int patternInText = KMP(text, pattern);

    printf("%d\n", patternInText);

    return 0;
}