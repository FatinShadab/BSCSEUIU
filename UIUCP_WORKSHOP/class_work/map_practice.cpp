#include <bits/stdc++.h>

using namespace std;

int main(){
    int student_numbers;
    cout<<"Enter Student : ";
    cin>>student_numbers;

    map <string, string> student;

    for (int i=1; i <= student_numbers; i++){
        if (i==1) getchar();
        string name;
        string sid;

        cout<<"\nEnter student ("<<i<<") name : ";
        getline(cin, name);
        cout<<"\nEnter student ("<<i<<") id : ";
        getline(cin, sid);

        student[name] = sid;
    }

    for (pair <string, string> tempPair : student){
        cout<<"Name : "<<tempPair.first<<", Id : "<<tempPair.second<<endl;
    }
}