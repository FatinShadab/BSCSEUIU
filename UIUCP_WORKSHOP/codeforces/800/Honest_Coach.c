#include <stdio.h>

void sort(int *array, int size){

    for (int i=0; i<size-1; i++){

        for (int j=i+1; j<size; j++){

            if (array[j]<array[i]){

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }

        }
    }

}

int main(){
    int testcases;
    scanf("%d", &testcases);

    for (int testcase=0; testcase<testcases; testcase++){
        int size;
        scanf("%d", &size);

        int array[size];
        for (int i=0; i<size; i++){
            scanf("%d", &array[i]);
        }

        sort(array, size);

        int min = array[size-1];

        for (int i=0; i<size; i++){
            int sub = array[i+1] - array[i];
            if (sub<min){
                min = sub;
            }
        }

        printf("%d\n", min);
    }

    return 0;
}