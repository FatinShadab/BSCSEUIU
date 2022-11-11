#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        long long int number;
        int prime = 1;
        cin>>number;

        for (long long int n = 2; n*n <= number; n++){
            if (number % n == 0){
                prime = 0;
                break;
            }
        }
        if (prime == 0)
            cout<<number<<" is not a prime"<<endl;
        else
            cout<<number<<" is a prime"<<endl;
    }

    return 0;
}