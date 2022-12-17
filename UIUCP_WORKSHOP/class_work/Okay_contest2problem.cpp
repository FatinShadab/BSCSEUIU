#include <bits/stdc++.h>

using namespace std;

int main(){

    set <int> s;

    int n; cin>>n;

    while(n--){
        int query, value;
        cin>>query>>value;

        switch (query){
            case 1:
                s.insert(value);
                break;
        
            case 2:
                s.erase(value);
                break;

            case 3:
                printf((s.find(value) != s.end()) ? "Yes\n":"No\n");
                break;
        }
    }

    return 0;
}