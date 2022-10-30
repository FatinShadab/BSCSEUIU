#include <bits/stdc++.h>

using namespace std;

int main(){

    int testcase;
    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        int number;
        cin>>number;

        cout<<"Sum = "<<(number/10000)+(number%10)<<endl;
    }

    return 0;
}