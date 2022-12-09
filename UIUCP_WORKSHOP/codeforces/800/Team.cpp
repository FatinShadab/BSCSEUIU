#include <bits/stdc++.h>

using namespace std;

int main(){

    int problemset;
    cin>>problemset;

    int problem_attempted = 0;

    while(problemset){

        int confidence = 0;

        for (int i=0; i<3; i++){
            int confident;
            cin>>confident;

            if (confident) confidence++;
        }

        if (confidence > 1) problem_attempted++;

        problemset--;
    }

    cout<<problem_attempted<<endl;

    return 0;
}