#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

int main(){
    int str_a_val = 0;
    int str_b_val = 0;

    string str_a;
    string str_b;

    getline(cin, str_a);
    getline(cin, str_b);

    for (int i=0; i<str_a.length(); i++){
        str_a[i] = toupper(str_a[i]);
        str_b[i] = toupper(str_b[i]);
    }

    if (str_a == str_b){
        cout<<0<<endl;
    }
    else{
        for (int i=0; i<str_a.length(); i++){
            if (str_a[i] > str_b[i]){
                cout<<1<<endl;
                break;
            }
            if (str_a[i] < str_b[i]){
                cout<<-1<<endl;
                break;
            }
        }
    }

    return 0;
}