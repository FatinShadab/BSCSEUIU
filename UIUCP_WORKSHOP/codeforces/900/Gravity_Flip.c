#include <stdio.h>
#include <limits.h>

void draw_box(int arr[], int size);

int main(){
    int n;
    scanf("%d", &n);

    int cols[n];
    for(int idx=0; idx<n; scanf("%d", &cols[idx++]));

    //printf("When Gravity pulling down :");
    //draw_box(cols, n);


    for (int idx=0; idx<n-1; idx++){
        for (int _idx=idx+1; _idx<n; _idx++){
            if (cols[idx] > cols[_idx]){
                cols[idx] = cols[idx]^cols[_idx];
                cols[_idx] = cols[idx]^cols[_idx];
                cols[idx] = cols[idx]^cols[_idx];
            }
        }
    }

    //printf("When Gravity pulling right :");
    //draw_box(cols, n);

    for(int idx=0; idx<n; printf("%d ", cols[idx++]));
    printf("\n");

    return 0;
}

void draw_box(int arr[], int size){
    int max = INT_MIN;

    for(int idx=0; idx<size; idx++){
        if (max < arr[idx])
            max = arr[idx];
    }

    printf("\n");
    for (int row=max; row >= 1; row--){
        for (int col=0; col < size; col++){
            (arr[col] >= row) ? printf("%c", (char)254u):printf(" ");
        }
        printf("\n");
    }

    return;
}