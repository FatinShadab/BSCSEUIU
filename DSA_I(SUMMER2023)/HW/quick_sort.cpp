#include <bits/stdc++.h>
using namespace std;

// Function to print the elements of an array
void printArray(int *arr, int arr_size){
	printf("The Array : ");
	for(int idx=0; idx < arr_size; idx++){
		printf("%d ", *(arr+idx));
	}
	printf("\n");
	return;
}

// Function to swap two elements in an array
void swap(int i, int j, int * arr){
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
    return;
}

// Function to randomize the order of elements in an array
void randomize(int * arr, int arr_size){
    for (int i = 0; i < arr_size; i++){
        int random_idx = rand() % arr_size; // Generate a random index within the array size
        swap(i, random_idx, arr); // Swap the current element with a randomly chosen element
    }
    return;
}

// Function to partition the array for quicksort
int partition(int * arr, int low, int high){
    int pivot = *(arr+high); // Choose the pivot as the last element
    int i = low - 1; // Initialize the index of the smaller element

    // Iterate through the array
    for (int j = low; j < high; j++){
        if (*(arr+j) < pivot){ // If the current element is smaller than the pivot
            swap(++i, j, arr); // Move the smaller element to the left side of the pivot
        }
    }

    swap(++i, high, arr); // Move the pivot element to its correct position
    return i; // Return the index of the pivot element
}

// Function to perform quicksort on the array
void quickSort(int * arr, int low, int high){
    if (low < high) { // If there are more than one element in the subarray
        int pivot_idx = partition(arr, low, high); // Get the index of the pivot element

        // Recursively perform quicksort on the two subarrays on either side of the pivot
        quickSort(arr, low, pivot_idx-1);
        quickSort(arr, pivot_idx+1, high);
    }
    return;
}

int main(){
    int arr[] = {7, 8, 5, 3, 2, 1, 0}; // Initialize an array with some values
    int arr_size = sizeof(arr)/sizeof(arr[0]); // Calculate the size of the array

    printArray(arr, arr_size); // Print the original array

    // To avoid the worst time complexity O(n^2) in quicksort, randomize the array
    randomize(arr, arr_size);

    printArray(arr, arr_size); // Print the randomized array

    quickSort(arr,  0, arr_size-1); // Sort the array using quicksort

    printArray(arr, arr_size); // Print the sorted array

    return 0;
}
