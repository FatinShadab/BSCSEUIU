#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);

    int puzzles[m];
    for(int i=0; i<m; scanf("%d", &puzzles[i++]));
    sort(puzzles, puzzles+m);

    int smallest_difference = INT_MAX;
    int start_idx = 0;
    int end_idx = n;

    while (end_idx<=m){
        int min = INT_MAX;
        int max = INT_MIN;

        //printf("Sub array : ");
        for(int idx=start_idx; idx<end_idx; idx++){
            //printf("%d ", puzzles[idx]);
            if (puzzles[idx] >= max)
                max = puzzles[idx];
            if (puzzles[idx] <= min)
                min = puzzles[idx];
        }
        //puts("");

        int difference = max - min;
        //printf(" smd: %d min: %d max: %d usmd: %d", smallest_difference, min, max, difference);

        //puts("");
        //puts("");

        if (difference <= smallest_difference)
            smallest_difference = difference;
    
        start_idx += 1;
        end_idx += 1;
    }

    printf("%d\n", smallest_difference);

    //main();

    return 0;
}