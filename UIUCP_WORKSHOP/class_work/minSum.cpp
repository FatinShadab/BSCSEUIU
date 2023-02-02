/*
https://vjudge.net/contest/539645#problem/F
pass: upsolve-upsolve-upsolve

gives TLE !!!
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int n;
        scanf("%d", &n);

        int nums[n];
        for (int i=0; i<n; scanf("%d", &nums[i++]));

        sort(nums, nums+n);

        long long int minSum = 0;
        int prevChecked = -1;
        for (int i=0; i<n; i++){
            if (nums[i] != prevChecked && nums[i] > prevChecked){
                prevChecked = nums[i];
                minSum += nums[i];
                for (int j=i+1; j<n; j++){
                    if (nums[j]%nums[i] == 0){
                        nums[j] = nums[i];
                        minSum += nums[j];
                    }
                }

                //printf("The array after checking with %d in index : %d  :", nums[i], i);
                //for (int i = 0; i<n; i++){
                //    printf("%d ", nums[i]);
                //}
                //printf("\n");

            }
        }

        printf("%lld\n", minSum);
    }

    return 0;
}