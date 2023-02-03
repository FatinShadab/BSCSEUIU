#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int bombed = 0;

        string str;
        cin>>str;
        int userStrLen = str.length();

        int idx = 0;
        int limit = userStrLen-1;
        while (idx < limit){
            //cout<<str<<endl;
            char char1 = str[idx];
            char char2 = str[idx+1];

            if ((char1 == 'A' || char1 == 'B') && char2 == 'B'){
                //printf("\t%d %d bombed\n", idx, idx+1);
                str.erase(idx, 2);
                limit = limit-2;
                bombed++;
                idx = 0;
            }else{
                idx++;
            }
        }

        printf("%d\n", userStrLen-(2*bombed));
    }

    return 0;
}