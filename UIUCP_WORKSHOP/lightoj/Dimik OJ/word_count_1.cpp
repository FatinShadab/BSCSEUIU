#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase, flag = 0;
    cin>>testcase;

    while(testcase--){
        if (flag == 0){
            getchar();
            flag = 1;
        }

        string str;
        getline(cin, str);

        stringstream ss(str);

        string temp;
        int count = 0;

        while (ss >> temp){
            //cout<<"count : "<<count<<", word : "<<temp<<endl;
            count++;
        }

        cout<<"Count = "<<count<<endl;
    }

    return 0;
}