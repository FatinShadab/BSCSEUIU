/*
Problem Link -> https://vjudge.net/contest/543519#problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    string signalStr;

    cin>>N;
    cin>>signalStr;

    int found = 1;
    int prev1 = -1;
    int currentD = -1;

    int idx = 0;
    for (char signal : signalStr){
        //cout<<signal<<" "<<idx<<endl;
        if (signal == '1'){
            //cout<<signal<<" : "<<idx<<endl;
            
            if (prev1 == -1){
                prev1 = idx;
                idx++;
                continue;
            }

            int d = idx - prev1;
            prev1 = idx;

            //cout<<"distance : "<<d<<endl;

            if (currentD == -1){
                currentD = d;
                idx++;
                continue;
            }

            //cout<<"\t cD" <<currentD<<endl;
            
            if (currentD != d){
                found = 0;
                break;
            }
        }
        idx++;
    }

    (found) ? cout<<"YES\n" : cout<<"NO\n";

    return 0;
}