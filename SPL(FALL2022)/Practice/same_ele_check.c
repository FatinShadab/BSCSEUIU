/*
WAP
*/

#include <stdio.h>

int main(){
    int sameflag = 1;

    int n; scanf("%d", &n);

    int arr[n];

    for (int idx=0; idx < n; scanf("%d", &arr[idx++]));

    for (int idx=0; idx < n; idx++){
        if (arr[idx] != arr[n-1-idx]){
            sameflag = 0;
            break;
        }
    }

    printf((sameflag) ? "Yes":"No");

    return 0;
}