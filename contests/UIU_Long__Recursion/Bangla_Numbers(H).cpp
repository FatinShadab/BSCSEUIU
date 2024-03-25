// problem link : https://vjudge.net/contest/616828#problem/H
#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

unordered_map <int, string> VALID_UNIT = {
    {100, "shata"}, {1000, "hajar"},
    {100000, "lakh"}, {10000000, "kuti"}
};

void bangla_number(ull n, int unit) {
    if (unit == 0) {
        if (n) cout << " " << n;
        return;
    }

    if (VALID_UNIT.find(unit) == VALID_UNIT.end() || unit > n) {
       return bangla_number(n, unit/10);
    }

    ull _n = n / unit;

    if (_n > 99) {
        bangla_number(_n, unit);
    }
    else {
        cout << " " << n / unit;
    }

    cout << " " << VALID_UNIT[unit];

    bangla_number(n%unit, unit / 10);
}

int main() {
    int count = 1;
    ull number;
    int starting_unit;

    while (cin >> number) {
        switch (number){
            case 1 ... 99:
                starting_unit = 10;
                break;
            case 100 ... 999:
                starting_unit = 100;
                break;
            case 1000 ... 99999:
                starting_unit = 1000;
                break;
            case 100000 ... 9999999:
                starting_unit = 100000;
                break;
            default:
                starting_unit = 10000000;
        }
        cout << setw(4) << count++ << ".";
        if (number == 0) {
            cout << " " << 0;
        }
        else {
            bangla_number(number, starting_unit);
        }
        cout << "\n";
    }

    return 0;
}