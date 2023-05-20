#include <bits/stdc++.h>
using namespace std;

const int mod = 131071;

long long bigMod(int base, int pow, int mod){
    if (pow == 0) return 1;
    if (pow == 1) return base;

    long long res = bigMod(base, pow/2, mod);

    res = (res * res) % mod;

    if (pow & 1) res = (res * base%mod) % mod;

    return res; 
}

void solve(string binary){
    long long num = 0;
    int pos = 0;
    char d;

    //cout << binary << " => ";

    while (binary.length() > 0){
        d = binary.back();

        if (d != '#'){
            if (d == '1'){
                num += bigMod(2, pos, mod);
                num %= mod;
            }
            pos++;
        }

        binary.pop_back();
    }

    //cout << num << '\n';

    if (num == 0){
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string binary = "";
    string temp_binary;

    while (cin >> temp_binary){
        binary += temp_binary;

        if (binary.back() == '#'){
            solve(binary);
            binary = "";
        }
    }

    return 0;
}