#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;

    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        int number;

        cin>>number;
        cout<<"Case "<<tcase+1<<": ";
        for (int i=1; i <= number; i++){
            if (number % i == 0){
                cout<<i;
                if (i != number){
                    cout<<" ";
                }
                else{
                    cout<<endl;
                }
            }
        }
    }

    return 0;
}