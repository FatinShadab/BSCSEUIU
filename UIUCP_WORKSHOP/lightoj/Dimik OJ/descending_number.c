#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    for (int i=1000; i>0; i--){
        cout<<i;
        if (i%5 == 1){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
    }
    
    return 0;
}