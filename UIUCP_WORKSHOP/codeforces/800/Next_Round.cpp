#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int p[n];
    for(int i=0; i<n; scanf("%d", &p[i++]));

    int rs = p[k-1];
    
    if (rs <= 0){
        int qualified = 0;

        for (int i=0; i<k; i++){
            if (p[i] > 0) qualified++;
        }

        cout<<qualified<<endl;
        
        return 0;
    }

    int qualified = k;

    for(int i=k; i<n; i++){
        if (p[i] == rs) qualified++;
        else break;
    }

    cout<<qualified<<endl;

    return 0;
}