#include <stdio.h>

void task(int array[], int size){

    if (size%2 == 0){
        for (int i=0, j=size-1; i< size, j>=0; i++,j--){
            if (i<j){
                printf("%d ", array[i]);
                printf("%d ", array[j]);
            }
        }
    }
    else{
        for (int i=0, j=size-1; i< size, j>=0; i++,j--){
            if (i<j){
                printf("%d ", array[i]);
                printf("%d ", array[j]);
            }
            else if (i==j){
                printf("%d ", array[i]);
            }
        }
    }

}

int main(){
    int tesecases;
    scanf("%d", &tesecases);

    for (int tesecase=0; tesecase<tesecases; tesecase++){
        int size;
        scanf("%d", &size);

        int array[size];
        for (int i=0; i<size; i++){
            scanf("%d", &array[i]);
        }
        task(array, size);
    }

    return 0;
}