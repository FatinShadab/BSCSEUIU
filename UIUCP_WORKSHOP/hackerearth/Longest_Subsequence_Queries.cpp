#include <bits/stdc++.h>

using namespace std;

int bsLessThenK(long long arr[], int size, long long k){
    int lb = 0;
    int ub = size-1;
    int answer = -1;

    while (lb <= ub){
        int mid = (lb + (ub-lb)/2);

        if (arr[mid] < k){
            answer = mid;
            lb = mid + 1;
        }
        else{
            ub = mid - 1;
        }
    }

    return answer+1;
}

int main(){

    int T; 
    scanf("%d", &T);

    while (T--){
        int n, q;
        scanf("%d %d", &n, &q);

        long long arr[n];
        for(int idx=0; idx<n; scanf("%lld", &arr[idx++]));

        // sort in ascending order
        sort(arr, arr+n);

        //prefix sum array
        long long pre_sum[n];
        long long sum = 0;
        for (int i=0; i<n; i++){
            sum += arr[i];
            pre_sum[i] = sum;
        }
        
        long long k;
        while (q--){
            scanf("%lld", &k);
            
            /*
            // gives TLE
            int count = 0;
            long long sum = 0;

            while (sum < k){
                sum += arr[count++];
            }
            
            printf("%d\n", count-1);
            */

            printf("%d\n", bsLessThenK(pre_sum, n, k));
        }
    }

    return 0;
}