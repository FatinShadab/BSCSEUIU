#include<stdio.h>

int main(){
    int num_of_test;
    scanf("%d", &num_of_test);

    for (int k = 0; k < num_of_test; k++)
   
    {
        int max = -1;
        int arr_size;
        scanf("%d", &arr_size);
        
        int arr[arr_size];
        int countAr[200001] = {0};
        
        for (int i = 0; i < arr_size; i++)
        {
            scanf("%d", &arr[i]);
            countAr[arr[i]]++;

        }
        
        for (int i = 0; i < arr_size; i++)
        {
            
            if (countAr[arr[i]]>=3)
            {
                max = arr[i];
            } 
    
        }
        
        printf(" %d", max);
    }

    return 0;
}