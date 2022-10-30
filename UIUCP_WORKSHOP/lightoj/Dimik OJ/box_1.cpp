#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        int rows;
        cin>>rows;
        for (int row=0; row<rows; row++){
            for (int col=0; col<rows; col++){
                cout<<"*";
            }
            cout<<endl;
        }
        if (tcase != testcase-1)
            cout<<endl;
    }

    return 0;
}