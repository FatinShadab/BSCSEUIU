#include <bits/stdc++.h>
using namespace std;

int main() {
    double n, m, a;
    cin >> n >> m >> a;

    long long int x = ceil(n / a);
    long long int y = ceil(m / a);
    
    cout << x * y << endl;
    
    return 0;
}