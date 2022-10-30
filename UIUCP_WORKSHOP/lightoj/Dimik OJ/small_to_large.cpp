#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        int numbers[3];
        cin>>numbers[0]>>numbers[1]>>numbers[2];

        for (int i=0; i<3; i++){
            for (int j=i+1; j<3; j++){
                if (numbers[i] > numbers[j]){
                    numbers[i] = numbers[i] ^ numbers[j];
                    numbers[j] = numbers[i] ^ numbers[j];
                    numbers[i] = numbers[i] ^ numbers[j];
                }
            }
        }

        cout<<"Case "<<tcase+1<<": "<<numbers[0]<<" "<<numbers[1]<<" "<<numbers[2]<<endl;
    }

    return 0;
}