// Add some code
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int testcase;
    
    cin>>testcase;
    
    for (int i=0; i<testcase; i++){
        int num;
        cin >> num;
        if (num % 2 == 0){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
    }
    
    return 0;
}