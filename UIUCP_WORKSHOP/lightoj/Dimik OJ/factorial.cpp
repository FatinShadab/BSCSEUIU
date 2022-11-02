#include <bits/stdc++.h>

using namespace std;

long long int factorial(long long int  n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    int tcase;
    cin>>tcase;

    for (int c=0; c < tcase; c++){
        // number range (0-19)
        long long int number;
        cin>>number;

        cout<<factorial(number)<<endl;
    }

    return 0;
}