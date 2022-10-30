#include <bits/stdc++.h>

using namespace std;

int main(void){
    int testcase;
    cin>>testcase;
    
    for (int i=0; i<testcase; i++){
        string num;
        cin>>num;

        if (((int) num[num.size()-1] - (int) '0')% 2 == 0 ){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
    }
    
    return 0;
}