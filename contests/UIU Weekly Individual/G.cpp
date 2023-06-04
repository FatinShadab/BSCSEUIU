// PB Link : https://vjudge.net/contest/561667#problem/G

#include <bits/stdc++.h>
using namespace std;

#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_N 1001

int students[MAX_N];
bool visited[MAX_N];

int get_real_mastermind(int student_idx){
    //cout << "\t" << student_idx;
    if (!visited[student_idx]){
        visited[student_idx] = true;
        //cout << " -> " << students[student_idx] <<"\n";
    }
    else{
        //cout << " ! " <<"\n";
        return student_idx;
    }

    return get_real_mastermind(students[student_idx]);
}

int main(){
    __fastIO__
    
    int n; cin >> n;
    
    for (int i=1; i<=n; cin>> students[i++]);

    for (int student=1; student<=n; student++){
        cout << get_real_mastermind(student) << " ";
        for (int i=0; i<MAX_N; visited[i++] = false);
    }

    return 0;
}