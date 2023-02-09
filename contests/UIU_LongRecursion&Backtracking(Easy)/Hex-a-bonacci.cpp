/*
    (a + b) % c == {(a % c) + (b % c)} % c
    (a - b) % c == {(a % c) - (b % c) + c} % c
    (a * b) % c == {(a % c) * (b % c)} % c
    (a / b) % c == {(a % c) * (b^-1 % c)} % c

    2nd way is used to avoid overflow.
    theory link : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/

    problem link : https://lightoj.com/problem/hex-a-bonacci
    
*/
#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1e7+7;
const unsigned int N = 1e4+1;

int DP[N];
unsigned int a, b, c, d, e, f, n;

unsigned int fn(unsigned int n) {
    
    if (n == 0) return a%M;
    if (n == 1) return b%M;
    if (n == 2) return c%M;
    if (n == 3) return d%M;
    if (n == 4) return e%M;
    if (n == 5) return f%M;

    if (DP[n] != -1){
        return DP[n];
    }

    DP[n] = fn(n-1)%M + fn(n-2)%M + fn(n-3)%M + fn(n-4)%M + fn(n-5)%M + fn(n-6)%M;

    return DP[n];
}

int main() {
    unsigned int T;
    scanf("%u", &T);

    for (unsigned int caseno = 1; caseno <= T; ++caseno) {
        scanf("%u %u %u %u %u %u %u", &a, &b, &c, &d, &e, &f, &n);
        memset(DP,-1,sizeof(DP));
        printf("Case %u: %u\n", caseno, (fn(n) + M) % M);
    }

    return 0;
}