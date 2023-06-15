#include <bits/stdc++.h>
using namespace std;

/*
    TOPIC : counting sort
    (sort without using any logical check)

    step 1: find out the max element present in the
            given array.
    
    step 2: create a freq_array of size (max element + 1).
            By doing so, we can find the elements of the 
            given array as the indices of the freq_array,
            and the values of a index represents the frequency
            of the element in the given (original) array.

            *** index of freq_array => possible element of the original array
            *** freq_array[index] => is the frequency of the element(index) in the original array 

    step 3: we will create another array of size same as freq_array
            (suppose prefix_arr) and the we will performe the cumulative 
            sum of freq_array and store that in prefix_arr.

            *** index of prefix_arr => possible element of the original array
            *** prefix_arr[__index] => is the required 'index' to put the element(__index) to sort the original array

    step 4: we will create the last array named sorted_arr array sized 
            as the original array, After that we will traverse trough the 
            original array and using the element as index for prefix_arr
            we will get the index in which we should put the element inorder to
            sort the array and after that we will decrease the value of prefix_arr
            the perticuler index by 1. After the  traversal the sorted_arr will be a 
            sorted version of the original array.
*/

int main(){
    int arr[] = {2, 1, 0, 5, 3, 4, 5, 1, 0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("The Given Array : ");
    for (int element : arr){
        printf("%d ", element);
    }
    printf("\n");

    // Step : 1
    int max_element = INT_MIN;
    for(int element : arr){
        max_element = (element > max_element) ? element:max_element;
    }

    printf("max element of the given array : %d\n", max_element);

    // Step : 2
    int freq_array[max_element+1];
    memset(freq_array, 0, sizeof(freq_array));

    for(int element : arr){
        freq_array[element]++;
    }

    // Step : 3
    int prefix_sum[max_element+1];
    for (int idx = 0; idx <= max_element; idx++){
        prefix_sum[idx] = (idx) ?  freq_array[idx] + prefix_sum[idx-1]:freq_array[idx];
    }

    // Step : 4
    int sorted_array[arr_size];
    for (int element : arr){
        sorted_array[prefix_sum[element]-1] = element;
        prefix_sum[element]--;
    }

    printf("After Shorted : ");
    for (int sorted_element : sorted_array){
        printf("%d ", sorted_element);
    }
    printf("\n");

    return 0;
}