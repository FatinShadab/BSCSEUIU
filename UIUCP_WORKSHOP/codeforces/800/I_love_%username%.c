#include <stdio.h>
#include <limits.h>

int leftSubArrMax(int arr[], int size);
int leftSubArrMin(int arr[], int size);

int main(){
    int count = 0;
    int n; scanf("%d", &n);
    int arr[n]; for(int i=0; i<n; scanf("%d", &arr[i++]));

    for (int i=1; i<n; i++){
        if (arr[i] > leftSubArrMax(arr, i) || arr[i] < leftSubArrMin(arr, i))
            count++;
    }

    printf("%d\n", count);

    return 0;
}

int leftSubArrMax(int arr[], int size){
    int max = INT_MIN;

    for (int i=0; i<size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }

    return max;
}

int leftSubArrMin(int arr[], int size){
    int min = INT_MAX;

    for (int i=0; i<size; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }

    return min;
}