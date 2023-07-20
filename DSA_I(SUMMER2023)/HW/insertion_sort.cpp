#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int arr_size){
	printf("The Array : ");
	for(int idx=0; idx < arr_size; idx++){
		printf("%d ", *(arr+idx));
	}
	printf("\n");
	return;
}

void insertionSort(int *arr, int arr_size, bool debug, int order){
	int total_loop_run = 0;

	if (debug)
		printf("\n*** Insertion Sort: %s,\n", (order == 1) ? "Ascending Order":"Descending Order");

	for (int right_ptr = 1; right_ptr < arr_size; right_ptr++){
		int loop_run = 0;

		int key = *(arr+right_ptr);
		int left_ptr = right_ptr - 1;

		if (debug)
			printf("\tright_ptr : %d, key = arr[%d] = %d\n", right_ptr, right_ptr, key);

		if (order == 1){
			// Ascending order
			while(left_ptr >= 0 && *(arr+left_ptr) > key){
				if (debug)
					printf("\t\tleft_ptr : %d:\n\t\t\t", left_ptr);
				
				*(arr+left_ptr+1) = *(arr+left_ptr);
				left_ptr--;
				
				if (debug)
					printArray(arr, arr_size);

				loop_run++;
			}

			*(arr+left_ptr+1) = key;

			if (debug){
				printf("\t\tInner loop run %d\n", loop_run);
				printf("\t\tAfter Inserting the key :\n\t\t\t");
				printArray(arr, arr_size);
			}
				
			total_loop_run += loop_run;
		}
		else if (order == -1){
			// Descending order
			while(left_ptr >= 0 && *(arr+left_ptr) < key){
				if (debug)
					printf("\t\tleft_ptr : %d:\n\t\t\t", left_ptr);

				*(arr+left_ptr+1) = *(arr+left_ptr);
				left_ptr--;

				if (debug)
					printArray(arr, arr_size);

				loop_run++;
			}

			*(arr+left_ptr+1) = key;

			if (debug){
				printf("\t\tInner loop run %d\n", loop_run);
				printf("\t\tAfter Inserting the key :\n\t\t\t");
				printArray(arr, arr_size);
			}
				
			total_loop_run += loop_run;
		}
	}

	if (debug)
		printf("\nTotal Iteration of Inner Loop : %d\n\n", total_loop_run);
	
	return;
}

int main(){
	int arr[] = {40, 30, 20, 10}; // change the data set as you wish
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Before Sorting :\n\t");
	printArray(arr, arr_size);

	// for ascending order sort
	insertionSort(arr, arr_size, true, 1);

	// uncomment for descending order sort
	//insertionSort(arr, arr_size, true, -1);

	printf("After Sorting :\n\t");
	printArray(arr, arr_size);

	return 0;
}
