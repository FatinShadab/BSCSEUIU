#include <bits/stdc++.h>

using namespace std;


int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int testcases;
    cin>>testcases;

    int testcaseRes[testcases];

    for(int testcase=0; testcase<testcases; testcase++){
        int size;
        cin>>size;

        int arr[size];

        for(int i=0; i<size; i++){
            cin>>arr[i];
        }

        for(int i=1; i<size; i++){
            int key = arr[i];
            int j= i-1;
            while(arr[j]>key && j>=0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }

        int minIdx = 0;
        int minVal = arr[0];
        
        for(int i=0; i<size; i++){
            if(minVal == arr[i] || minVal > arr[i]){
                minVal = arr[i];
                minIdx = i;
            }
        }

        testcaseRes[testcase] = size-(minIdx+1);
    }

    for (int i=0; i<testcases; i++){
        cout<<testcaseRes[i]<<endl;
    }

    return 0;
}