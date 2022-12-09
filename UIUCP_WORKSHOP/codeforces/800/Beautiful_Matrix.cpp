#include <bits/stdc++.h>

using namespace std;

int main(){

    int br = 3, bc = 3;
    int r1, c1, ele;

    for (int i=1; i <= 5; i++){
        for (int j=1; j <= 5; j++){
            cin>>ele;
            if (ele){
                r1 = i;
                c1 = j;
            }
        }
    }

    int rswap_needed = (r1 != br) ? ((r1 > br) ? r1-br:br-r1) : 0;
    int cswap_needed = (c1 != bc) ? ((c1 > bc) ? c1-bc:bc-c1) : 0; 

    cout<<rswap_needed+cswap_needed<<endl;

    return 0;
}