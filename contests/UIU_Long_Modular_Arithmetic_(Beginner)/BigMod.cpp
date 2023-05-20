#include <bits/stdc++.h>
using namespace std;
#define lint long long int

lint bigMod(lint B, lint P, lint M){
    if (P == 0) return 1;
    if (P == 1) return B;

    lint res = bigMod(B, P/2, M);

    res = (res * res) % M;

    if (P & 1) res = (res * B%M) % M;

    return res;
}

int main(){    
    lint B, P, M;

    while(cin >> B >> P >> M){
        printf("%lld\n", bigMod(B, P, M));
    }

    return 0;
}
