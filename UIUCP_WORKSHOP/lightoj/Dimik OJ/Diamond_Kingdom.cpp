#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    while (testcase){

        int n, x;
        cin>>n>>x;

        for (int row=0; row < n; row++){
            for (int col=0 ; col <= row; col++){
                printf("%d ", x);
            }
            printf("\n");
        }
        for (int row=n-2; row >= 0; row--){
            for (int col=0 ; col <= row; col++){
                printf("%d ", x);
            }
            printf("\n");
        }
        printf("\n");
        testcase--;
    }

    return 0;
}