#include <bits/stdc++.h>

using namespace std;

int main(){

    vector <int> magicBox;

    int n; cin>>n;

    while(n--){
        int ele;
        cin>>ele;
        magicBox.push_back(ele);
    }

    sort(magicBox.begin(), magicBox.end());

    for (int ele : magicBox){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}