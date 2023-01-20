// Have to learn BS for searching lower bound
// Have to learn BS for searching upper bound

#include <bits/stdc++.h>

using namespace std;

int getMarbleIdx(int arr[], int lb, int ub, int target);

int main(){
    //freopen("inputq1.txt", "r", stdin);
    int counter = 0;

    while (1){
        int n, q;
        scanf("%d %d", &n, &q);

        if (n+q == 0) 
            break;

        int marbles[n];
        for (int i=0; i<n; scanf("%d", &marbles[i++]));

        sort(marbles, marbles+n);

        printf("CASE# %d:\n", ++counter);
        
        while (q--){
            int m;
            scanf("%d", &m);

            int m_idx = getMarbleIdx(marbles, 0, n-1, m);

            if (m_idx != -1)
                printf("%d found at %d\n", m, m_idx+1);
            else
                printf("%d not found\n", m);
        }
    }
    
    return 0;
}
// BUG : 

int getMarbleIdx(int arr[], int lb, int ub, int target){
    //printf("UB: %d\n", ub);
    if (ub == lb)
        if (arr[ub] == target)
            return ub;
        else
            return -1;

    if (ub >= lb) {
        int mid = lb + (ub - lb) / 2;
 
       // if (arr[mid] == target)
            //return mid;
 
        if (arr[mid] >= target) // 1st encounter
        // arr[mid] > target    // last encounter
            return getMarbleIdx(arr, lb, mid, target);
 
        return getMarbleIdx(arr, mid + 1, ub, target);
    }
 
    return -1;
}