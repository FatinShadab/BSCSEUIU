#include <stdio.h>
#include <limits.h>

int find_narrow_path(int L[], int R[], int size_L, int size_R, int road_lenght){

    if (size_L != size_R){
        printf("Two array must be of same size !");
        return -1;
    }

    int narrow_path = INT_MAX;

    for (int idx = 0; idx < size_L; idx++){
        int gap = road_lenght - (L[idx] + R[idx]);
        //printf("\nGap : %d, L: %d, R: %d", gap, L[idx], R[idx]);
        if (gap < narrow_path) narrow_path = gap;
    }

    return narrow_path;
}


int main(){
    int L[] = {9, 7, 4, 6, 3};
    int R[] = {1, 2, 3, 4, 5};
    int road_lenght = 15;

    printf("The narrow path is : %d", find_narrow_path(L, R, 5, 5, road_lenght));

    return 0;
}