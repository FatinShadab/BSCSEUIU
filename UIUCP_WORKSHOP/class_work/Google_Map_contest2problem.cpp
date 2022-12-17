#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string, int> student_db;

    int n; cin>>n;

    while (n--){

        int query_type;
        int student_marks;
        string student_name;
        
        cin>>query_type>>student_name;

        switch (query_type){
            case 1:
                cin>>student_marks;
                student_db[student_name] += student_marks;
                break;
        
            case 2:
                student_db[student_name] = 0;
                break;

            case 3:
                cout<<student_db[student_name]<<endl;
                break;
        }
    }

    return 0;
}